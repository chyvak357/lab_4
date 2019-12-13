#ifndef LAB_4_TREE_H
#define LAB_4_TREE_H

#include <iostream>
using namespace std;

class Tree{
    int key;                                    // ����� �������
    int height;                                 // ������ ���������
    Tree* left;                                 // c����� �� ������ ����
    Tree* right;                                // ������ �� ������� ����

public:

    Tree(int k){                                // ����������� ������ ������� ��� �������
        key = k;
        left = right = 0;
        height = 1;
    }

    int calc_height(Tree* p);              // ��������� ������ �������
    int bfactor(Tree* p);                        // �������� ����� ����� ���������
    void fix_height(Tree *p);                    // ������� ������, ���� ������������������ ��������
    Tree* rotate_right(Tree *p);                // ������ ������� ������ p
    Tree* rotate_left(Tree *q);                  // ����� ������� ������ q
    Tree* balance(Tree* p);                      // ������������ ���� p
    Tree* insert(Tree* p, int k);               // ������� ����� k � ������ � ������ p
    Tree* find_min(Tree *p);                     // ����� ���� � ����������� ������ � ������ p
    Tree* rm_min(Tree *p);                      // �������� ���� � ����������� ������ �� ������ p
    Tree* remove(Tree* p, int k);                // �������� ����� k �� ������ p
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