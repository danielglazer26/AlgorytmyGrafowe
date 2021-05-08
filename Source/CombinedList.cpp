#include <iostream>
#include "../Header/CombinedList.h"


void CombinedList::createUndirectedList(int *vS, int *vE, int *w) {

    createDirectedList(vS, vE, w);
    createDirectedList(vE, vS, w);
}

void CombinedList::createDirectedList(int *vS, int *vE, int *w) {

    edge *pointer = list[*vS];

    do {
        if (pointer->vertex == -1) {
            pointer->vertex = *vE;
            pointer->weight = *w;
            break;
        } else {
            if (pointer->next == nullptr)
                pointer->next = new edge;
            pointer = pointer->next;

        }

    } while (true);
}

void CombinedList::showList() {
    edge *pointer;
    for (int i = 0; i < size; i++) {
        std::cout << i << "  ";
        pointer = list[i];
        while (true) {
            if (pointer->vertex != -1)
                std::cout << pointer->vertex << " " << pointer->weight << "  ";
            if (pointer->next != nullptr)
                pointer = pointer->next;
            else
                break;
        }
        std::cout << "\n";
    }
}

int CombinedList::getSize() const {
    return size;
}

CombinedList::EdgeList **CombinedList::getList() {
    return list;
}

void CombinedList::deleteList() {
    edge *pointer;
    edge *pointer2;

    for (int i = 0; i < size; i++) {
        pointer = list[i];
        while (true) {
            if (pointer->next != nullptr) {
                pointer2 = pointer->next;
                delete pointer;
                pointer = pointer2;
            } else {
                delete pointer;
                break;
            }
        }
    }
    delete list;
}
