
#ifndef ALGORYTMYGRAFOWE_GRAPHREPRESENTATION_H
#define ALGORYTMYGRAFOWE_GRAPHREPRESENTATION_H


#include "EdgesSortedList.h"
#include "Matrix.h"
#include "LoadFromFile.h"
#include "Matrix.h"

class GraphRepresentation {
public:

    GraphRepresentation(bool directed) { graphInitialization(directed); }

    ~GraphRepresentation(){
        delete matrix;
        delete edgesSortedList;
    }

    EdgesSortedList *getList();
private:
    EdgesSortedList *edgesSortedList;
    Matrix * matrix;
    int edgesNumber;
    int verticesNumber;
    int startingVertex;

    int endingVertex;

    void graphInitialization(bool directed);

    void createList(LoadFromFile *loadFromFile);

    void createMatrix(bool directed);
};


#endif //ALGORYTMYGRAFOWE_GRAPHREPRESENTATION_H
