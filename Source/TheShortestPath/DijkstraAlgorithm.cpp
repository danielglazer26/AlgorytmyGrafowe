#include <iostream>
#include "../../Header/TheShortestPath/DijkstraAlgorithm.h"

//wywolanie rekurencyjnego algorytmu dla macierzy
void DijkstraAlgorithm::findMinimalPathByMatrix() {

    findMinimalPathByMatrix(gr->getStartingVertex());
}

//rekurencyjne wyszukiwanie najkrotszej sciezki za pomoca macierzy
void DijkstraAlgorithm::findMinimalPathByMatrix(int minVertex) {

    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        int weight = gr->getMatrix()->getMatrixWeights()[minVertex][i];
        if (weight != INT32_MAX) {
            if (pathTable[i][0] > weight + pathTable[minVertex][0]) {
                pathTable[i][0] = weight + pathTable[minVertex][0];
                pathTable[i][1] = minVertex;
            }
        }

    }
    visitedTable[minVertex] = true;
    int nextVertex = findMinimum();
    if (nextVertex != -1)
        findMinimalPathByMatrix(nextVertex);

}

//wyszukujemy wierzcholek do ktorego prowadzi najkrotsza sciezka
int DijkstraAlgorithm::findMinimum() {
    int minVertex = -1;
    int *minWeight = nullptr;
    for (int j = 0; j < gr->getVerticesNumber(); j++) {
        if (!visitedTable[j]) {
            if (minWeight == nullptr || *minWeight > pathTable[j][0]) {
                minWeight = &pathTable[j][0];
                minVertex = j;
            }
        }
    }
    return minVertex;
}

//wywolanie rekurencyjnego algorytmu dla listy
void DijkstraAlgorithm::findMinimalPathByList() {

    findMinimalPathByList(gr->getStartingVertex());
}

//rekurencyjne wyszukiwanie najkrotszej sciezki za pomoca listy
void DijkstraAlgorithm::findMinimalPathByList(int minVertex) {

    CombinedList::EdgeList *pointer = gr->getCombinedList()->getList()[minVertex];
    if (pointer->vertex != -1) {
        while (true) {
            int weight = pointer->weight;
            if (pathTable[pointer->vertex][0] > weight + pathTable[minVertex][0]) {
                pathTable[pointer->vertex][0] = weight + pathTable[minVertex][0];
                pathTable[pointer->vertex][1] = minVertex;
            }
            if (pointer->next != nullptr)
                pointer = pointer->next;
            else
                break;
        }
    }
    visitedTable[minVertex] = true;
    int nextVertex = findMinimum();
    if (nextVertex != -1)
        findMinimalPathByList(nextVertex);

}

//usuwanie tablic, kt??re s?? potrzebne do funkcjonowania algorytmu
void DijkstraAlgorithm::deleteTables() {
    AlgorithmsTheShortestPath::deleteTables();
}
