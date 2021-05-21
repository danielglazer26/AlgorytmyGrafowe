#include <iostream>

#include "../Header/GraphRepresentation.h"

//wczytywanie danych inicjalizujacych graf
void GraphRepresentation::graphInitialization(bool directed) {

    LoadFromFile *loadFromFile = new LoadFromFile();

    if (loadFromFile->openFile()) {
        edgesNumber = loadFromFile->getDataFromFile();
        verticesNumber = loadFromFile->getDataFromFile();
        startingVertex = loadFromFile->getDataFromFile();
        endingVertex = loadFromFile->getDataFromFile();
        createList(loadFromFile, directed);
        createMatrix();

    } else
        std::cout << "Brak pliku\n";
}

//wczytywanie krawedzi z pliku w celu utworzenia listy
void GraphRepresentation::createList(LoadFromFile *loadFromFile, bool directed) {

    combinedList = new CombinedList(verticesNumber);
    int *edge = new int[3];
    for (int i = 0; i < edgesNumber; i++) {
        for (int j = 0; j < 3; j++) {
            edge[j] = loadFromFile->getDataFromFile();
        }
        if (directed)
            combinedList->createDirectedList(edge, &edge[1], &edge[2]);
        else
            combinedList->createUndirectedList(edge, &edge[1], &edge[2]);
    }
    delete loadFromFile;
}
//tworzenie macierzy sąsiedztwa na podstawie listy
void GraphRepresentation::createMatrix() {
    matrix = new Matrix(verticesNumber);
    matrix->createMatrix(combinedList);
}

CombinedList *GraphRepresentation::getCombinedList() {
    return combinedList;
}

Matrix *GraphRepresentation::getMatrix() {
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
