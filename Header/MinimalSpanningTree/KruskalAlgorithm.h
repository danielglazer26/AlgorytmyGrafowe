#ifndef ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H
#define ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H

#include "AlgorithmsMST.h"

class KruskalAlgorithm : public AlgorithmsMST{
private:

    int *colorTable;

    void createTable();

    void findMSTbyMatrix(int k);

    void findMSTbyList(int k);

    bool canAddThisEdge(int x, int y);

    bool canAddThisEdge(int x);

    void changeColor(int x, int y);

    void deleteTables();


public:


    void findMSTbyMatrix();

    void findMSTbyList();

    KruskalAlgorithm(GraphRepresentation *graphRepresentation):
    AlgorithmsMST(graphRepresentation) {}


};


#endif //ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H
