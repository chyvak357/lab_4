#ifndef LAB_4_TREE_H
#define LAB_4_TREE_H

#include <iostream>
using namespace std;

class Tree{
    int key;                                    // номер вершины
    int height;                                 // высота поддерева
    Tree* left;                                 // cсылка на левого сына
    Tree* right;                                // ссылка на правого сына

public:

    Tree(int k){                                // конструктор пустой вершины без листьев
        key = k;
        left = right = 0;
        height = 1;
    }

    int calc_height(Tree* p);              // получение высоты вершины
    int bfactor(Tree* p);                        // разность высот между сыновьями
    void fix_height(Tree *p);                    // обновим высоту, если сбалансированность нарушена
    Tree* rotate_right(Tree *p);                // правый поворот вокруг p
    Tree* rotate_left(Tree *q);                  // левый поворот вокруг q
    Tree* balance(Tree* p);                      // балансировка узла p
    Tree* insert(Tree* p, int k);               // вставка ключа k в дерево с корнем p
    Tree* find_min(Tree *p);                     // поиск узла с минимальным ключом в дереве p
    Tree* rm_min(Tree *p);                      // удаление узла с минимальным ключом из дерева p
    Tree* remove(Tree* p, int k);                // удаление ключа k из дерева p
    void print_tree(Tree * p, int level);
#endif //LAB_4_TREE_H


/*
 * void BalanceTree::Print(const Tree* t,const int& h)
{
    if (t!=NULL)
    {
        Print(t->left,h+1);
        for (int i=1;i<=h;i++)
        {
            cout << "      ";
        }
        cout << t->data<<endl<<endl;
        Print(t->right,h+1);
    }
    return;
}
 */