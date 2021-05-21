#ifndef ALGORYTMYGRAFOWE_BELLMANFORDALGORITHM_H
#define ALGORYTMYGRAFOWE_BELLMANFORDALGORITHM_H


#include "../GraphRepresentation.h"
#include "AlgorithmsTheShortestPath.h"
#include "../Queue.h"

class BellmanFordAlgorithm : public AlgorithmsTheShortestPath {
private:

    Queue *queue = new Queue();

    void findMinimalPathByMatrix(int vertex);

    void findMinimalPathByList(int vertex);

    void checkQueue(int const i) const;

public:

    BellmanFordAlgorithm(GraphRepresentation *graphRepresentation)
    :AlgorithmsTheShortestPath(graphRepresentation){}

    void findMinimalPathByList();

    void findMinimalPathByMatrix();
    ~BellmanFordAlgorithm(){
        delete queue;
    }

};


#endif //ALGORYTMYGRAFOWE_BELLMANFORDALGORITHM_H
