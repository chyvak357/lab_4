#include "NodeData.h"

void NodeData::append(int str_value){
    if (!str_value){
        return;
    }
    NodeData* temp = this;
    if (!this->next){
        this->next = new NodeData(str_value);
        return;
    }

    while (temp->next){
        temp = temp->next;
    }
    temp->next = new NodeData(str_value);
}

void NodeData::get_all() {
    NodeData* temp = this;
    while (temp){
        std::cout << temp->doc_str << ", ";
        temp = temp->next;
    }
}