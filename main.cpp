#include <iostream>
#include <fstream>
#include <regex>
#include <iomanip>
#include "tree.h"
#include "NodeData.h"
using namespace std;

/* �������
1) ����������� ����� �������� ������, ������� � ���� ������:
    ����������� �� ��������� � ����� ��������� ������, ��������� ������ ����� ������,
    ������������ ������ �������������.


2) ����������� ����������� ����� ��� ������ ������������� ���������. � ����� �������� ������:
    ����������� � ���������� (��� ����������������� ������) � ����� �����.
    ���������� �����������
    ����������
    ������ ��� ��������, ������������ � ��������.

 */


/* �������
 ��������� ��������� ����������� ������������� ������, �.�. ���������� ������ ����,
 ������� ����������� � ������������� �����. � ��� ������� �����  - ������ ������� �����,
 � ������� ��� ����� �����������. ���������� �� ����� �������� � ���� ��������� ������ ������,
 �������������� �� �������� �����. ������ ������� ����� ��������� � ���������  ��������� ������,
 ��������� �� ������� ������ ��������������� ���� ������.

    ��������� ������ ���������� ����
    ����� �����, ������������� � ������ � ������������ ����� �����
    ��������� �������� ������
    ����������� ������� ������
 */


/*
 * ��������:
 *  1) ������ ��������� �� ����� � ��������� �� �����
 *  2) ������ ����� � ������
 *  3) ��������� ������ ��� �������� ���������� ���������.
 *  4) ��������
 */

int main() {
    /*
    string temp_s; // ���� ����� ������ ��������� ������
    ifstream file("D:\\Torrent\\data.txt");
    while(getline(file, temp_s)){
//        cout << temp_s << endl;
//        temp_s += "+";
    }

    file.close();

    */
//    temp_s = "Project This project covers the need of a group of IT Security Researchers to have a single ";
//    cout << temp_s << endl;
//    if (regex_match(temp_s, sm, regex("(.*)[\\s\\,\\?\\!\\.]"))) {
//        const auto capture = sm[0].str();
//
//        cout << '\t' << capture << endl;

//        if(regex_search(capture, sm, regex("(a|d+)\\s+problems?"))) {
//            const auto count = sm[1] == "a"s ? 1 : stoi(sm[1]);
//
//            cout << '\t' << count << (count > 1 ? " problems\n" : " problem\n"); // Outputs: "\t1 problem\n"
//            cout << "Now they have " << count + 1 << " problems.\n"; // Ouputs: "Now they have 2 problems\n"
//        }
//    }
/*
//    regex regular("(\\w+\\b)");
    temp_s = "sghbjsdfkj12, jsdfj snlsdf lkewc lsdfio s. sdfosfsd?";
    cout << temp_s << endl;
    regex regular("\\w+");
    cmatch match;
//    if( regex_match( temp_s.c_str(), match, regular)){
    regex_match( temp_s.c_str(), match, regular); //regex { R"\w+" });
    cout << "YES!\n";
    for (int k = 0; k < match.size(); k++) {
        cout << match[k] <<  endl;
    }
    */
//    } else {
//        cout << "LOH\n";
//    }
//    (.*)[ ,\?\.]



    Tree* tree = new Tree("root");
    tree->print_tree(tree, 0);
    cout << "-----------\n";

    tree = tree->insert(tree, "pidor");
    tree->print_tree(tree, 0);
    cout << "-----------\n";

    tree = tree->insert(tree, "sosat");
    tree->print_tree(tree, 0);
    cout << "-----------\n";

    tree = tree->insert(tree, "lokh");
    tree->print_tree(tree, 0);
    cout << "-----------\n";

    tree = tree->insert(tree, "derevo");
    tree->print_tree(tree, 0);
    cout << "Completed!"<< endl;


    return 0;
}