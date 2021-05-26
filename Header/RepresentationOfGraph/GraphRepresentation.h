
#ifndef ALGORYTMYGRAFOWE_GRAPHREPRESENTATION_H
#define ALGORYTMYGRAFOWE_GRAPHREPRESENTATION_H


#include "CombinedList.h"
#include "Matrix.h"
#include "../LoadFromFile.h"

class GraphRepresentation {
public:

    GraphRepresentation(bool directed) { graphInitialization(directed); }

    ~GraphRepresentation() {
        delete matrix;
        delete combinedList;
    }

    CombinedList *getCombinedList();

    Matrix *getMatrix();

    int getEdgesNumber() const;

    int getVerticesNumber() const;

    int getStartingVertex() const;

    int getEndingVertex() const;

private:
    CombinedList *combinedList;
    Matrix *matrix;
    int edgesNumber;
    int verticesNumber;
    int startingVertex;
    int endingVertex;

    void graphInitialization(bool directed);

    void createList(LoadFromFile *loadFromFile, bool directed);

    void createMatrix();
};


#endif //ALGORYTMYGRAFOWE_GRAPHREPRESENTATION_H
