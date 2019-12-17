#include "tree.h"

int Tree::calc_height(Tree* p){                     // получение высоты вершины
    if (not p){
        return 0;
    } else {
        return p->height;                           // высота поддерева этой вершины
    }
}


int Tree::bfactor(Tree* p){                         // разность высот между сыновьями
    return calc_height(p->right)-calc_height(p->left); // вручную посчитаем разницу
}


void Tree::fix_height(Tree *p){                     // обновим высоту, если сбалансированность нарушена
    int hl = calc_height(p->left);                  // высота левого сына
    int hr = calc_height(p->right);                 // высота правого сына
    p->height = ( hl>hr ? hl: hr) + 1;              // высота вершины - это высота сына с макс высотой плюс 1
}


Tree* Tree::rotate_right(Tree *p){                  // правый поворот вокруг p
    Tree* q = p->left;                              // обменяем левого и правого сына
    p->left = q->right;
    q->right = p;
    fix_height(p);                                  //починим дерево
    fix_height(q);
    return q;
}


Tree* Tree::rotate_left(Tree *q){                   // левый поворот вокруг q
    Tree* p = q->right;                             // обменяем правого и левого сына
    q->right = p->left;
    p->left = q;
    fix_height(q);
    fix_height(p);
    return p;
}


Tree* Tree::balance(Tree* p){                       // балансировка узла p
    fix_height(p);
    if( bfactor(p)==2 ){                            //если левый сын сильно больше правого сделаем правый поворот
        if( bfactor(p->right) < 0 )
            p->right = rotate_right(p->right);
        return rotate_left(p);
    }
    if( bfactor(p)==-2 ){                           // если правый сын сибно больше левого сделаем левый поворот
        if( bfactor(p->left) > 0  )
            p->left = rotate_left(p->left);
        return rotate_right(p);
    }
    return p;                                       // балансировка не нужна
}


Tree* Tree::insert(Tree* p, string str_val, int row_num){         // вставка ключа k в дерево с корнем p
    if( !p ) return new Tree(str_val, row_num);                   // если дерево пустое создадим его
    if( str_val < p->word ) {                                     //если ключ больше вершины, вызомем это рекурсивно от левого сына
        p->left = insert(p->left, str_val, row_num);
    } else if ( str_val > p->word ) {
        p->right = insert(p->right, str_val,
                          row_num);              // если ключ меньше вершины, вызовем рекурсию от правго сына
    } else if ( str_val == p->word ) {
        p->rows->append(row_num);
    }
    return balance(p);                                              // отбалансируем вершину
}


void Tree::print_tree(Tree* p, int level) {
    if(p){
        print_tree(p->right, level + 1);
        for(int i = 0;i< level;i++) {
            cout << "   ";
        }
        cout << p->word <<":" << p->rows->get_sum();
        cout << endl;
        print_tree(p->left, level + 1);
    }
}

Tree* Tree::get_max(){
    auto* max = new int(0);
    Tree* answ = 0;
    search_max(this, answ, max);
    return answ;
}
void Tree::search_max(Tree* p, Tree*& p_max, int*& max) {
    if(p){
        if (p->rows->get_sum() > *max){
            *max = p->rows->get_sum();
            p_max = p;
        }
        search_max(p->right, p_max, max);
        search_max(p->left, p_max, max);
    }
}