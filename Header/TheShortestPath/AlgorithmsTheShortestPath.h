
#ifndef ALGORYTMYGRAFOWE_ALGORITHMSTHESHORTESTPATH_H
#define ALGORYTMYGRAFOWE_ALGORITHMSTHESHORTESTPATH_H


#include "../GraphRepresentation.h"

class AlgorithmsTheShortestPath {
private:
    void showPath(int k);

protected:

    bool *visitedTable;
    int **pathTable;
    GraphRepresentation *gr;

    void createTable();
    virtual void deleteTables();

    void showPathTable();

public:

    void showPath();

    AlgorithmsTheShortestPath(GraphRepresentation *graphRepresentation) {
        gr = graphRepresentation;
    }


};


#endif //ALGORYTMYGRAFOWE_ALGORITHMSTHESHORTESTPATH_H
