#ifndef LAB_4_TREE_H
#define LAB_4_TREE_H

#include <iostream>
#include "NodeData.h"
using namespace std;

class Tree {
    string word;                                // номер вершины
    NodeData* data;
    int height;                                 // высота поддерева
    Tree *left;                                 // cсылка на левого сына
    Tree *right;                                // ссылка на правого сына

public:

    Tree(string k) {                                // конструктор пустой вершины без листьев
        word = k;
        left = right = 0;
        height = 1;
//        data = new NodeData();
    }

    int calc_height(Tree *p);              // получение высоты вершины
    int bfactor(Tree *p);                        // разность высот между сыновьями
    void fix_height(Tree *p);                    // обновим высоту, если сбалансированность нарушена
    Tree *rotate_right(Tree *p);                // правый поворот вокруг p
    Tree *rotate_left(Tree *q);                  // левый поворот вокруг q
    Tree *balance(Tree *p);                      // балансировка узла p
    Tree *insert(Tree *p, string k);               // вставка ключа k в дерево с корнем p
    Tree *find_min(Tree *p);                     // поиск узла с минимальным ключом в дереве p
    Tree *rm_min(Tree *p);                      // удаление узла с минимальным ключом из дерева p
    Tree *remove(Tree *p, string k);                // удаление ключа k из дерева p
    void print_tree(Tree *p, int level);
};

#endif //LAB_4_TREE_H