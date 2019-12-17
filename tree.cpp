#include "tree.h"

int Tree::calc_height(Tree* p){                     // ��������� ������ �������
    if (not p){
        return 0;
    } else {
        return p->height;                           // ������ ��������� ���� �������
    }
}


int Tree::bfactor(Tree* p){                         // �������� ����� ����� ���������
    return calc_height(p->right)-calc_height(p->left); // ������� ��������� �������
}


void Tree::fix_height(Tree *p){                     // ������� ������, ���� ������������������ ��������
    int hl = calc_height(p->left);                  // ������ ������ ����
    int hr = calc_height(p->right);                 // ������ ������� ����
    p->height = ( hl>hr ? hl: hr) + 1;              // ������ ������� - ��� ������ ���� � ���� ������� ���� 1
}


Tree* Tree::rotate_right(Tree *p){                  // ������ ������� ������ p
    Tree* q = p->left;                              // �������� ������ � ������� ����
    p->left = q->right;
    q->right = p;
    fix_height(p);                                  //������� ������
    fix_height(q);
    return q;
}


Tree* Tree::rotate_left(Tree *q){                   // ����� ������� ������ q
    Tree* p = q->right;                             // �������� ������� � ������ ����
    q->right = p->left;
    p->left = q;
    fix_height(q);
    fix_height(p);
    return p;
}


Tree* Tree::balance(Tree* p){                       // ������������ ���� p
    fix_height(p);
    if( bfactor(p)==2 ){                            //���� ����� ��� ������ ������ ������� ������� ������ �������
        if( bfactor(p->right) < 0 )
            p->right = rotate_right(p->right);
        return rotate_left(p);
    }
    if( bfactor(p)==-2 ){                           // ���� ������ ��� ����� ������ ������ ������� ����� �������
        if( bfactor(p->left) > 0  )
            p->left = rotate_left(p->left);
        return rotate_right(p);
    }
    return p;                                       // ������������ �� �����
}


Tree* Tree::insert(Tree* p, string str_val, int row_num){         // ������� ����� k � ������ � ������ p
    if( !p ) return new Tree(str_val, row_num);                   // ���� ������ ������ �������� ���
    if( str_val < p->word ) {                                     //���� ���� ������ �������, ������� ��� ���������� �� ������ ����
        p->left = insert(p->left, str_val, row_num);
    } else if ( str_val > p->word ) {
        p->right = insert(p->right, str_val,
                          row_num);              // ���� ���� ������ �������, ������� �������� �� ������ ����
    } else if ( str_val == p->word ) {
        p->rows->append(row_num);
    }
    return balance(p);                                              // ������������� �������
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