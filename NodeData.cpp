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


int NodeData::get_sum() {
    int s = 0;
    NodeData* temp = this;
    while (temp){
        s++;
        temp = temp->next;
    }
    return s;
}