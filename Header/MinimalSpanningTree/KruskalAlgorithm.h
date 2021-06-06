#ifndef ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H
#define ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H

#include "AlgorithmsMST.h"

class KruskalAlgorithm : public AlgorithmsMST {
private:

    int *colorTable;

    void createTable();

    void findMSTbyMatrix(int k);

    void findMSTbyList(int k);

    bool canAddThisEdge(int x, int y);

    void changeColor(int x, int y);

public:


    void findMSTbyMatrix();

    void findMSTbyList();

    KruskalAlgorithm(GraphRepresentation *graphRepresentation) :
            AlgorithmsMST(graphRepresentation) {
        createTable();
    }

    void deleteTables();

    ~KruskalAlgorithm() {
        deleteTables();
    }


};


#endif //ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H
