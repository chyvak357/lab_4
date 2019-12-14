#ifndef LAB_4_NODEDATA_H
#define LAB_4_NODEDATA_H
#include <iostream>

class NodeData {
    NodeData* next = nullptr;
    int doc_str;


public:
    NodeData(int k){
        next = 0;
        doc_str = k;
    }

    void append(int str_value);
    void get_all();
};


#endif //LAB_4_NODEDATA_H
