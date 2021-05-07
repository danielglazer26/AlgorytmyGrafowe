#include <iostream>
#include "../Header/EdgesSortedList.h"


void EdgesSortedList::createEdgeList(const int i, const int * e){
    edgeList[i] = new int[3];
    for (int j = 0; j < 3; j++) {
        edgeList[i][j] = e[j];
    }
}
void EdgesSortedList::showList(){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << edgeList[i][j] <<" ";
        }
        std::cout << "\n";
    }
}
int EdgesSortedList::getSize() const {
    return size;
}
int ** EdgesSortedList::getList(){
    return edgeList;
}

void EdgesSortedList::deleteList(){
    for (int i = 0; i < size; i++) {
        delete[] edgeList[i];
    }
    delete edgeList;
}
