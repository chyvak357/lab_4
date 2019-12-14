#ifndef LAB_4_TREE_H
#define LAB_4_TREE_H

#include <iostream>
#include "NodeData.h"
using namespace std;

class Tree {
    string word;                                // ����� �������
    NodeData* rows;
    int height;                                 // ������ ���������
    Tree *left;                                 // c����� �� ������ ����
    Tree *right;                                // ������ �� ������� ����

public:
//    ����������
    Tree(string str_value, int row_num) {      // ����������� ������ ������� ��� �������
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

    int calc_height(Tree *p);                           // ��������� ������ �������
    int bfactor(Tree *p);                               // �������� ����� ����� ���������
    void fix_height(Tree *p);                           // ������� ������, ���� ������������������ ��������
    Tree *rotate_right(Tree *p);                        // ������ ������� ������ p
    Tree *rotate_left(Tree *q);                         // ����� ������� ������ q
    Tree *balance(Tree *p);                             // ������������ ���� p
    Tree *insert(Tree *p, string str_val, int row_num); // ������� ����� k � ������ � ������ p
    void print_tree(Tree *p, int level);                // ����� ������ �� �����
    void search_max(Tree* p, Tree*& p_max, int*& max);
    Tree* get_max();
    string get_word(){ return this->word; }

};

#endif //LAB_4_TREE_H