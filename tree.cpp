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
    p->height = (hl>hr?hl:hr)+1;                    // высота вершины - это высота сына с макс высотой плюс 1
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


Tree* Tree::insert(Tree* p, string k){                 // вставка ключа k в дерево с корнем p
    if( !p ) return new Tree(k);                    // если дерево пустое создадим его
    if( k<p->word )                                  //если ключ больше вершины, вызомем это рекурсивно от левого сына
        p->left = insert(p->left,k);
    else
        p->right = insert(p->right,k);              // если ключ меньше вершины, вызовем рекурсию от правго сына
    return balance(p);                              // отбалансируем вершину
}


Tree* Tree::find_min(Tree *p){                      // поиск узла с минимальным ключом в дереве p
    return p->left? find_min(p->left):p;            //если есть левый сын, идем в него иначе ответ в этой вершине
}


Tree* Tree::rm_min(Tree *p){                        // удаление узла с минимальным ключом из дерева p
    if( p->left==0 )                                // если нет левого сына удалим эту вершину
        return p->right;
    p->left = rm_min(p->left);                      // иначе идем в левого сына
    return balance(p);                              //балансируем дерево
}


Tree* Tree::remove(Tree* p, string k){                 // удаление ключа k из дерева p
    if( !p ){
        return 0;                                   // если дерево пустое, уходим
    }
    if( k < p->word ) {                              //если элемент меньше вершины идем в левого сына
        p->left = remove(p->left, k);
    } else if( k > p->word ) {
        p->right = remove(p->right, k);             // если элемент больше вершины, идем в правого сына
    } else {                                        //  мы пришли в вершину, которую надо удалить
        Tree* q = p->left;
        Tree* r = p->right;
        delete p;                                   //удалим физически эту вершину
        if( !r ) {
            return q;
        }
        Tree* min = find_min(r);
        min->right = rm_min(r);                     //правый сын минимальной вершины - это правое поддерево удаляемой без минимума
        min->left = q;                              // левый сын минимальной вершины - левый сын удаляемой
        return balance(min);                        // балансируем меньшую вершину
    }
    return balance(p);                              // мы ничего не нашли, балансируем дерево
}


void Tree::print_tree(Tree * p, int level) {
    if(p){
        print_tree(p->right, level + 1);
        for(int i = 0;i< level;i++) {
            cout << "   ";
        }
        cout << p->word << endl;
        print_tree(p->left, level + 1);
    }
}