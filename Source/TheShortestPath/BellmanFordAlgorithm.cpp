#include <iostream>
#include "../../Header/TheShortestPath/BellmanFordAlgorithm.h"


void BellmanFordAlgorithm::findMinimalPathByMatrix() {

    createTable();
    queue->push(gr->getStartingVertex());
    findMinimalPathByMatrix(*queue->getFirst());

}

void BellmanFordAlgorithm::findMinimalPathByMatrix(int vertex) {
    visitedTable[vertex] = true;
    queue->pop();
    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        int *weight = gr->getMatrix()->getMatrixWeights()[vertex][i];
        if (weight != nullptr) {
            if (pathTable[i][0] > *weight + pathTable[vertex][0]) {
                pathTable[i][0] = *weight + pathTable[vertex][0];
                pathTable[i][1] = vertex;
                checkQueue(i);
            }
        }
    }
    if (queue->getFirst() != nullptr)
        findMinimalPathByMatrix(*queue->getFirst());

}

void BellmanFordAlgorithm::findMinimalPathByList() {

    //kolejka zawierajacy kolejnosc odkrywania wierzcholkow
    createTable();
    queue->push(gr->getStartingVertex());
    findMinimalPathByList(*queue->getFirst());
}

void BellmanFordAlgorithm::findMinimalPathByList(int vertex) {

    CombinedList::EdgeList *pointer = gr->getCombinedList()->getList()[vertex];
    if (pointer->vertex != -1)  //sprawdzamy czy wierzchołek ma sciezki
        while (true) {
            int *weight = &pointer->weight;
            if (pathTable[pointer->vertex][0] > *weight + pathTable[vertex][0]) {
                pathTable[pointer->vertex][0] = *weight + pathTable[vertex][0];
                pathTable[pointer->vertex][1] = vertex;
                checkQueue(pointer->vertex);
            }
            if (pointer->next != nullptr)
                pointer = pointer->next;
            else
                break;
        }
    if (queue->getFirst() != nullptr)
        findMinimalPathByList(*queue->getFirst());

}

//sprawdzamy czy odwiedzilismy dany wierzcholek
void BellmanFordAlgorithm::checkQueue(int const i) const {

    if(visitedTable[i])
        queue->beginAddElementToQueue(i);
    else
        queue->push(i);


}


