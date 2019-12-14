#include <iostream>
#include <fstream>
#include <regex>
#include <iomanip>
#include <string.h>
#include "tree.h"
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

    +��������� ������ ���������� ����
    +����� �����, ������������� � ������ � ������������ ����� �����
    ?��������� �������� ������
    +����������� ������� ������
 */


/*
 * ��������:
 *  1) ������ ��������� �� ����� � ��������� �� �����
 *  2) ������ ����� � ������
 *  3) ��������� ������ ��� �������� ���������� ���������.
 *  4) ��������
 */

int main() {
    Tree* tree = new Tree("root", 1);

    string temp_s; // ���� ����� ������ ��������� ������
    ifstream file("D:\\Torrent\\data.txt");
    int row_num = 0;
    while(getline(file, temp_s)){
        row_num++;

        char * pch = strtok (temp_s," ,.-");
        while (pch != NULL){
            std::cout << pch� << "n";
            pch = strtok (NULL, " ,.-");
        }
        tree = tree->insert(tree, t_word, row_num);
    }

    file.close();

    tree->print_tree(tree, 0);
    cout << "Completed!\n"<< endl;

    Tree* max_answer = tree->get_max();
    cout << max_answer->get_word() << endl;



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


/*
    Tree* tree = new Tree("root", 1);
    tree = tree->insert(tree, "pidor", 1);
    tree = tree->insert(tree, "sosat", 2);
    tree = tree->insert(tree, "sosat", 2);
    tree = tree->insert(tree, "sosat", 3);

    tree = tree->insert(tree, "lokh", 3);
    tree = tree->insert(tree, "pidor", 3);
    tree = tree->insert(tree, "derevo", 4);

    tree->print_tree(tree, 0);
    cout << "Completed!"<< endl;


//    cout << tree->get_max()->get_word() << endl;
    Tree* max_answer = tree->get_max();
    cout << max_answer->get_word() << endl;
*/
    return 0;
}