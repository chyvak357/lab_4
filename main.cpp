#include <iostream>
#include <fstream>
#include <regex>
#include <iomanip>
#include "tree.h"
#include "NodeData.h"
using namespace std;

/* Задание
1) Разработать класс бинарное дерево, включив в него методы:
    конструктор по умолчанию и вывод бинарного дерева, используя прямой обход дерева,
    разворачивая дерево горизонтально.


2) Разработать производный класс для дерева определенного вариантом. В класс включить методы:
    Конструктор с параметром (для сбалансированного дерева) – число узлов.
    Копирующий конструктор
    Деструктор
    Методы для операций, определенных в варианте.

 */


/* Вариант
 Составить программу формирующую “перекрестные ссылки”, т.е. печатающую список слов,
 которые встречаются в анализируемом файле. А для каждого слова  - список номеров строк,
 в которых это слово встречается. Информация по слову хранится в узле бинарного дерева поиска,
 упорядоченного по значению слова. Список номеров строк храниться в отдельном  связанном списке,
 указатель на который хранит соответствующий узел дерева.

    Построить дерево указанного вида
    Найти слово, встретившееся в тексте в максимальном числе строк
    Вычислить значение дерева
    Распечатать формулу дерева
 */


/*
 * Добавить:
 *  1) Чтение построчно из файла с разбивкой на слова
 *  2) Запись слова в дерево
 *  3) Структура списка для хранения количества вхождений.
 *  4) Алгоритм
 */

int main() {
    /*
    string temp_s; // сюда будем класть считанные строки
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