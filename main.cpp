#include <iostream>
#include <fstream>
#include <regex>
#include <iomanip>
#include <string.h>
#include "tree.h"
using namespace std;

int main() {

    Tree* tree = new Tree("root", 1);
    regex re("(\\w*)[^\\W0-9]");

    string temp_s;
    ifstream file("D:\\Torrent\\data.txt");
    int row_num = 0;
    while(getline(file, temp_s)){
        row_num++;
        sregex_iterator next(temp_s.begin(), temp_s.end(), re);
        sregex_iterator end;
        while (next != end) {
            smatch match = *next;
            tree = tree->insert(tree, match.str(), row_num);
            next++;
        }
    }

    cout << "Input completed" << endl;
    file.close();

    tree->print_tree(tree, 0);
    cout << "Completed!\n"<< endl;

    Tree* max_answer = tree->get_max();
    cout << max_answer->get_word() << endl;

    return 0;
}