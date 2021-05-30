#include <iostream>
#include "../../Header/TheShortestPath/DijkstraAlgorithm.h"

//wywolanie rekurencyjnego algorytmu dla macierzy
void DijkstraAlgorithm::findMinimalPathByMatrix() {

    findMinimalPathByMatrix(gr->getStartingVertex());
}

//rekurencyjne wyszukiwanie najkrotszej sciezki za pomoca macierzy
void DijkstraAlgorithm::findMinimalPathByMatrix(int minVertex) {

    bool exception = false;
    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        int weight = gr->getMatrix()->getMatrixWeights()[minVertex][i];
        if (pathTable[i][0] > -1) {
            if (weight != INT32_MAX) {
                if (pathTable[i][0] > weight + pathTable[minVertex][0]) {
                    pathTable[i][0] = weight + pathTable[minVertex][0];
                    pathTable[i][1] = minVertex;
                }
            }
        } else {
            exception = true;
            break;
        }
    }
    if (!exception) {
        visitedTable[minVertex] = true;
        int nextVertex = findMinimum();
        if (nextVertex != -1)
            findMinimalPathByMatrix(nextVertex);
    } else
        std::cout << "Błąd\n";
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

    bool exception = false;

    CombinedList::EdgeList *pointer = gr->getCombinedList()->getList()[minVertex];
    if (pointer->vertex != -1) {
        while (true) {
            if (pathTable[pointer->vertex][0] > -1) {
                int weight = pointer->weight;
                if (pathTable[pointer->vertex][0] > weight + pathTable[minVertex][0]) {
                    pathTable[pointer->vertex][0] = weight + pathTable[minVertex][0];
                    pathTable[pointer->vertex][1] = minVertex;
                }
                if (pointer->next != nullptr)
                    pointer = pointer->next;
                else
                    break;
            } else {
                exception = true;
                break;
            }
        }
    }
    if (!exception) {
        visitedTable[minVertex] = true;
        int nextVertex = findMinimum();
        if (nextVertex != -1)
            findMinimalPathByList(nextVertex);
    }
}

//usuwanie tablic, które są potrzebne do funkcjonowania algorytmu
void DijkstraAlgorithm::deleteTables() {
    AlgorithmsTheShortestPath::deleteTables();
}
