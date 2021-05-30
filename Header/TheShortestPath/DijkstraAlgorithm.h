

#ifndef ALGORYTMYGRAFOWE_DIJKSTRAALGORITHM_H
#define ALGORYTMYGRAFOWE_DIJKSTRAALGORITHM_H


#include "../RepresentationOfGraph/GraphRepresentation.h"
#include "AlgorithmsTheShortestPath.h"

class DijkstraAlgorithm : public AlgorithmsTheShortestPath {

private:

    void findMinimalPathByList(int minVertex);

    void findMinimalPathByMatrix(int minVertex);

    int findMinimum();

    void deleteTables();

public:

    DijkstraAlgorithm(GraphRepresentation *graphRepresentation)
            : AlgorithmsTheShortestPath(graphRepresentation) {;
    }

    void findMinimalPathByMatrix();

    void findMinimalPathByList();

    ~DijkstraAlgorithm() {

    }
};


#endif //ALGORYTMYGRAFOWE_DIJKSTRAALGORITHM_H
