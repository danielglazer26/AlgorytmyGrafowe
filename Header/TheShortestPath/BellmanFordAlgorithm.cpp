#include <iostream>
#include "BellmanFordAlgorithm.h"

void BellmanFordAlgorithm::createTable() {
    pathTable = new int *[gr->getVerticesNumber()];
    visitedTable = new bool[gr->getVerticesNumber()];
    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        visitedTable[i] = false;
        pathTable[i] = new int[2];
        pathTable[i][0] = INT32_MAX; //odpowiednik nieskonczonosci
        pathTable[i][1] = -1;

    }
    pathTable[gr->getStartingVertex()][0] = 0;
    visitedTable[gr->getStartingVertex()] = true;

}

void BellmanFordAlgorithm::findMinimalPathByMatrix() {
    int *stack = new int[gr->getVerticesNumber()];
    stack[0] = gr->getStartingVertex();
    int stackIterator = 1;
    findMinimalPathByMatrix(stack[0], stack, &stackIterator, 0);
}

void BellmanFordAlgorithm::findMinimalPathByMatrix(int vertex, int *stack, int *stackIterator, int k) {
    int *weight;
    bool somethingChange = false;

    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        weight = gr->getMatrix()->getMatrixWeights()[vertex][i];
        if (weight != nullptr) {
            if (pathTable[i][0] > *weight + pathTable[vertex][0]) {
                pathTable[i][0] = *weight + pathTable[vertex][0];
                pathTable[i][1] = vertex;
                if (*stackIterator < gr->getVerticesNumber())
                    stack[(*stackIterator)++] = i;
            }
        }

    }
    showPathTable();
    if (k + 1 < gr->getVerticesNumber())
        findMinimalPathByMatrix(stack[k + 1], stack, stackIterator, k + 1);


}

void BellmanFordAlgorithm::findMinimalPathByList() {

}

void BellmanFordAlgorithm::showPathTable() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < gr->getVerticesNumber(); j++) {
            if (i == 0)
                std::cout << j << " ";
            else
                std::cout << pathTable[j][i - 1] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void BellmanFordAlgorithm::showPath() {
    showPathTable();
    for (int i = 0; i < gr->getVerticesNumber(); ++i) {
        showPath(i);
    }
}

void BellmanFordAlgorithm::showPath(int k) {
    int i = k;
    int *stack = new int[gr->getVerticesNumber()];
    int stackIterator = 0;
    while (pathTable[i][1] != -1) {
        stack[stackIterator++] = i;
        i = pathTable[i][1];
    }
    std::cout << k << " | " << pathTable[k][0] << " | " << gr->getStartingVertex() << " ";
    while(stackIterator){
        std::cout << stack[--stackIterator] << " ";
    }

    std::cout << std::endl;
}

void BellmanFordAlgorithm::deleteTables() {
    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        delete pathTable[i];
    }
    delete pathTable;
    delete visitedTable;
}
