

#ifndef ALGORYTMYGRAFOWE_DIJKSTRAALGORITHM_H
#define ALGORYTMYGRAFOWE_DIJKSTRAALGORITHM_H


#include "../RepresentationOfGraph/GraphRepresentation.h"
#include "AlgorithmsTheShortestPath.h"

class DijkstraAlgorithm : public AlgorithmsTheShortestPath {

private:

    void findMinimalPathByList(int minVertex);

    void findMinimalPathByMatrix(int minVertex);

public:
    DijkstraAlgorithm(GraphRepresentation *graphRepresentation)
            : AlgorithmsTheShortestPath(graphRepresentation) {}

    void findMinimalPathByMatrix();

    void findMinimalPathByList();

    int findMinimum();

    void deleteTables();
};


#endif //ALGORYTMYGRAFOWE_DIJKSTRAALGORITHM_H
