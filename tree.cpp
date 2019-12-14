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
    p->height = (hl>hr?hl:hr)+1;                    // ������ ������� - ��� ������ ���� � ���� ������� ���� 1
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


Tree* Tree::insert(Tree* p, string k){                 // ������� ����� k � ������ � ������ p
    if( !p ) return new Tree(k);                    // ���� ������ ������ �������� ���
    if( k<p->word )                                  //���� ���� ������ �������, ������� ��� ���������� �� ������ ����
        p->left = insert(p->left,k);
    else
        p->right = insert(p->right,k);              // ���� ���� ������ �������, ������� �������� �� ������ ����
    return balance(p);                              // ������������� �������
}


Tree* Tree::find_min(Tree *p){                      // ����� ���� � ����������� ������ � ������ p
    return p->left? find_min(p->left):p;            //���� ���� ����� ���, ���� � ���� ����� ����� � ���� �������
}


Tree* Tree::rm_min(Tree *p){                        // �������� ���� � ����������� ������ �� ������ p
    if( p->left==0 )                                // ���� ��� ������ ���� ������ ��� �������
        return p->right;
    p->left = rm_min(p->left);                      // ����� ���� � ������ ����
    return balance(p);                              //����������� ������
}


Tree* Tree::remove(Tree* p, string k){                 // �������� ����� k �� ������ p
    if( !p ){
        return 0;                                   // ���� ������ ������, ������
    }
    if( k < p->word ) {                              //���� ������� ������ ������� ���� � ������ ����
        p->left = remove(p->left, k);
    } else if( k > p->word ) {
        p->right = remove(p->right, k);             // ���� ������� ������ �������, ���� � ������� ����
    } else {                                        //  �� ������ � �������, ������� ���� �������
        Tree* q = p->left;
        Tree* r = p->right;
        delete p;                                   //������ ��������� ��� �������
        if( !r ) {
            return q;
        }
        Tree* min = find_min(r);
        min->right = rm_min(r);                     //������ ��� ����������� ������� - ��� ������ ��������� ��������� ��� ��������
        min->left = q;                              // ����� ��� ����������� ������� - ����� ��� ���������
        return balance(min);                        // ����������� ������� �������
    }
    return balance(p);                              // �� ������ �� �����, ����������� ������
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