#include <iostream>

#include "../Header/GraphRepresentation.h"

void GraphRepresentation::graphInitialization(bool directed) {

    LoadFromFile *loadFromFile = new LoadFromFile();

    if (loadFromFile->openFile()) {
        edgesNumber = loadFromFile->getDataFromFile();
        verticesNumber = loadFromFile->getDataFromFile();
        startingVertex = loadFromFile->getDataFromFile();
        endingVertex = loadFromFile->getDataFromFile();
        createList(loadFromFile);
        createMatrix(directed);

    } else
        std::cout << "Brak pliku\n";
}

void GraphRepresentation::createList(LoadFromFile *loadFromFile) {

    combinedList = new CombinedList(verticesNumber);
    int *edge = new int[3];
    for (int i = 0; i < edgesNumber; i++) {
        for (int j = 0; j < 3; j++) {
            edge[j] = loadFromFile->getDataFromFile();
        }
        combinedList->createUndirectedList(edge, &edge[1], &edge[2]);
    }
    delete loadFromFile;
}

void GraphRepresentation::createMatrix(bool directed) {
    matrix = new Matrix(verticesNumber);
    matrix->createMatrix(combinedList);

    matrix->showMatrix();
    matrix->showMatrixWages();
}

CombinedList *GraphRepresentation::getList() {
    return combinedList;
}
Matrix *GraphRepresentation::getMatrix(){
    return matrix;
}

int GraphRepresentation::getEdgesNumber() const {
    return edgesNumber;
}

int GraphRepresentation::getVerticesNumber() const {
    return verticesNumber;
}

int GraphRepresentation::getStartingVertex() const {
    return startingVertex;
}

int GraphRepresentation::getEndingVertex() const {
    return endingVertex;
}
