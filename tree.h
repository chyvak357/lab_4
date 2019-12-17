#ifndef LAB_4_TREE_H
#define LAB_4_TREE_H

#include <iostream>
#include "NodeData.h"
using namespace std;

class Tree {
    string word;
    NodeData* rows;
    int height;
    Tree *left;
    Tree *right;

public:
//     оструткор
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
    int bfactor(Tree *p);                               // разность высот между ветв€ми
    void fix_height(Tree *p);                           // обновить высоту, если сбалансированность нарушена
    Tree *rotate_right(Tree *p);                        // правый поворот
    Tree *rotate_left(Tree *q);                         // левый поворот
    Tree *balance(Tree *p);                             // балансировка узла
    Tree *insert(Tree *p, string str_val, int row_num); // вставка ключа k в дерево с корнем p
    void print_tree(Tree *p, int level);                // вывод дерева на экран
    void search_max(Tree* p, Tree*& p_max, int*& max);  // ѕоиск слова с максимальным кол-м вхождений
    Tree* get_max();                                    // ѕолучение указател€ на максимальное слово
    string get_word(){ return this->word; }             // ѕолучение значение слова узла

};

#endif //LAB_4_TREE_H