

#ifndef ALGORYTMYGRAFOWE_DIJKSTRAALGORITHM_H
#define ALGORYTMYGRAFOWE_DIJKSTRAALGORITHM_H


#include "../GraphRepresentation.h"

class DijkstraAlgorithm {
private:
    int ** pathTable;
    bool * visitedTable;
public:
    void createTable();
    GraphRepresentation * gr;
    DijkstraAlgorithm(GraphRepresentation * graphRepresentation){
        gr = graphRepresentation;
    }

    void findMinimalPathByMatrix();
    void findMinimalPathByList();
};


#endif //ALGORYTMYGRAFOWE_DIJKSTRAALGORITHM_H
