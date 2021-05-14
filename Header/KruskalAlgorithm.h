#ifndef ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H
#define ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H

#include "AlgorithmsMST.h"

class KruskalAlgorithm : public AlgorithmsMST{
private:

    int *tableColor;

    void createTable();

    void findMSTbyMatrix(int k);

    void findMSTbyList(int k);

    bool canAddThisEdge(int x, int y);

    bool canAddThisEdge(int x);

    void changeColor(int x, int y);

    bool addNextEdge(int *w_min, int x_min, int y_min, int k);

    void deleteTables();


public:


    void findMSTbyMatrix();

    void findMSTbyList();

    //void showMST();
    KruskalAlgorithm(GraphRepresentation *graphRepresentation):
    AlgorithmsMST(graphRepresentation) {}


};


#endif //ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H
