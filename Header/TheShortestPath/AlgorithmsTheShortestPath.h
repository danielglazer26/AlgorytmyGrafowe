
#ifndef ALGORYTMYGRAFOWE_ALGORITHMSTHESHORTESTPATH_H
#define ALGORYTMYGRAFOWE_ALGORITHMSTHESHORTESTPATH_H


#include "../RepresentationOfGraph/GraphRepresentation.h"

class AlgorithmsTheShortestPath {

private:
    void showPath(int k);

protected:
    int cycleDetector = -1;
    bool *visitedTable;
    int **pathTable;
    GraphRepresentation *gr;

    void createTable();

    virtual void deleteTables();

public:

    AlgorithmsTheShortestPath(GraphRepresentation *graphRepresentation) {
        gr = graphRepresentation;
    }

    void showPath();

    void showPathTable();
};


#endif //ALGORYTMYGRAFOWE_ALGORITHMSTHESHORTESTPATH_H
