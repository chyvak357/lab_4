#ifndef LAB_4_TREE_H
#define LAB_4_TREE_H

#include <iostream>
#include "NodeData.h"
using namespace std;

class Tree {
    string word;                                // номер вершины
    NodeData* rows;
    int height;                                 // высота поддерева
    Tree *left;                                 // cсылка на левого сына
    Tree *right;                                // ссылка на правого сына

public:
//    Коструткор
    Tree(string str_value, int row_num) {      // конструктор пустой вершины без листьев
        word = str_value;
        left = right = 0;
        height = 1;
        rows = new NodeData(row_num);
    }

    Tree (const Tree &object) {
        word = object.word;
        rows = object.rows;
        left = object.left;
        right = object.right;
        height = object.height;
    }

    int calc_height(Tree *p);                           // получение высоты вершины
    int bfactor(Tree *p);                               // разность высот между сыновьями
    void fix_height(Tree *p);                           // обновим высоту, если сбалансированность нарушена
    Tree *rotate_right(Tree *p);                        // правый поворот вокруг p
    Tree *rotate_left(Tree *q);                         // левый поворот вокруг q
    Tree *balance(Tree *p);                             // балансировка узла p
    Tree *insert(Tree *p, string str_val, int row_num); // вставка ключа k в дерево с корнем p
    void print_tree(Tree *p, int level);                // вывод дерева на экран
    void search_max(Tree* p, Tree*& p_max, int*& max);
    Tree* get_max();
    string get_word(){ return this->word; }

};

#endif //LAB_4_TREE_H