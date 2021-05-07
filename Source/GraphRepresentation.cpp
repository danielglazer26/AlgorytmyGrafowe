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

    edgesSortedList = new EdgesSortedList(edgesNumber);
    int *edge = new int[3];
    for (int i = 0; i < edgesNumber; i++) {
        for (int j = 0; j < 3; j++) {
            edge[j] = loadFromFile->getDataFromFile();
        }
        edgesSortedList->createEdgeList(i, edge);
    }
    delete loadFromFile;
}

void GraphRepresentation::createMatrix(bool directed) {
    matrix = new Matrix(verticesNumber);
    if (directed)
        matrix->createDirectedMatrix();
    else
        matrix->createUndirectedMatrix(edgesSortedList);
    matrix->showMatrix();
    matrix->showMatrixWages();
}

EdgesSortedList *GraphRepresentation::getList() {
    return edgesSortedList;
}
