/*
#include <iostream>
#include "../../Header/TheShortestPath/DijkstraAlgorithm.h"

void DijkstraAlgorithm::createTable() {
    pathTable = new int *[gr->getVerticesNumber()];
    visitedTable = new bool [gr->getVerticesNumber()];
    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        visitedTable[i] = false;
        pathTable[i] = new int[2];
        pathTable[i][0] = INT32_MAX; //odpowiednik nieskonczonosci
        pathTable[i][1] = -1;

    }
    pathTable[gr->getStartingVertex()][0] = 0;
}
void DijkstraAlgorithm::findMinimalPathByMatrix(){
    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        if(visitedTable[i])
    }
}

void DijkstraAlgorithm::findMinimalPathByList() {

}
*/
