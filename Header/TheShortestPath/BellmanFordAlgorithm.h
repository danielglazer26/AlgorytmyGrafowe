#ifndef ALGORYTMYGRAFOWE_BELLMANFORDALGORITHM_H
#define ALGORYTMYGRAFOWE_BELLMANFORDALGORITHM_H


#include "../GraphRepresentation.h"

class BellmanFordAlgorithm {
private:
    int ** pathTable;
    bool * visitedTable;

    void createTable();
    void deleteTables();
    void showPath(int k);
    void showPathTable();

    void findMinimalPathByMatrix(int vertex, int *stack, int *stackIterator, int k);
public:
    GraphRepresentation * gr;

    BellmanFordAlgorithm(GraphRepresentation * graphRepresentation){
        gr = graphRepresentation;
    }

    ~BellmanFordAlgorithm(){
        deleteTables();
    }

    void findMinimalPathByList();

    void findMinimalPathByMatrix();

    void showPath();
};


#endif //ALGORYTMYGRAFOWE_BELLMANFORDALGORITHM_H
