#ifndef LAB_4_TREE_H
#define LAB_4_TREE_H

#include <iostream>
#include "NodeData.h"
using namespace std;

class Tree {
    string word;                                // ����� �������
    NodeData* data;
    int height;                                 // ������ ���������
    Tree *left;                                 // c����� �� ������ ����
    Tree *right;                                // ������ �� ������� ����

public:

    Tree(string k) {                                // ����������� ������ ������� ��� �������
        word = k;
        left = right = 0;
        height = 1;
//        data = new NodeData();
    }

    int calc_height(Tree *p);              // ��������� ������ �������
    int bfactor(Tree *p);                        // �������� ����� ����� ���������
    void fix_height(Tree *p);                    // ������� ������, ���� ������������������ ��������
    Tree *rotate_right(Tree *p);                // ������ ������� ������ p
    Tree *rotate_left(Tree *q);                  // ����� ������� ������ q
    Tree *balance(Tree *p);                      // ������������ ���� p
    Tree *insert(Tree *p, string k);               // ������� ����� k � ������ � ������ p
    Tree *find_min(Tree *p);                     // ����� ���� � ����������� ������ � ������ p
    Tree *rm_min(Tree *p);                      // �������� ���� � ����������� ������ �� ������ p
    Tree *remove(Tree *p, string k);                // �������� ����� k �� ������ p
    void print_tree(Tree *p, int level);
};

#endif //LAB_4_TREE_H