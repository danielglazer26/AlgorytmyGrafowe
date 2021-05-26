#include <iostream>
#include "../../Header/TheShortestPath/BellmanFordAlgorithm.h"

//wywolanie rekurencyjnego algorytmu dla macierzy
void BellmanFordAlgorithm::findMinimalPathByMatrix() {

    cycleDetector = -1;
    createTable();
    queue->push(gr->getStartingVertex());
    findMinimalPathByMatrix(*queue->getFirst());

}

//rekurencyjne wyszukiwanie najkrotszej sciezki za pomoca macierzy
void BellmanFordAlgorithm::findMinimalPathByMatrix(int vertex) {

    cycleDetector++;
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
    if (cycleDetector <= gr->getEdgesNumber()) {
        if (queue->getFirst() != nullptr)
            findMinimalPathByMatrix(*queue->getFirst());
    }
}

//wywolanie rekurencyjnego algorytmu dla listy
void BellmanFordAlgorithm::findMinimalPathByList() {

    cycleDetector = -1;
    createTable();
    queue->push(gr->getStartingVertex());
    findMinimalPathByList(*queue->getFirst());
}

//rekurencyjne wyszukiwanie najkrotszej sciezki za pomoca listy
void BellmanFordAlgorithm::findMinimalPathByList(int vertex) {

    cycleDetector++;
    visitedTable[vertex] = true;
    queue->pop();

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
    if (cycleDetector <= gr->getEdgesNumber()) {
        if (queue->getFirst() != nullptr)
            findMinimalPathByList(*queue->getFirst());
    }

}

//sprawdzamy czy odwiedzilismy dany wierzcholek
void BellmanFordAlgorithm::checkQueue(int const i) const {

    if (visitedTable[i])
        queue->beginAddElementToQueue(i);
    else
        queue->push(i);


}



