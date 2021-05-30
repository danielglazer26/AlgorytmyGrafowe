
#ifndef ALGORYTMYGRAFOWE_PRIMALGORITHM_H
#define ALGORYTMYGRAFOWE_PRIMALGORITHM_H

#include "AlgorithmsMST.h"

class PrimAlgorithm : public AlgorithmsMST {
private:

    bool *visitedTable;

    void createTable();

    void findMSTbyMatrix(int k, int * x_min, int * y_min);

    void findMSTbyList(int k, int * x_min, int * y_min);

public:

    void findMSTbyMatrix();

    void findMSTbyList();

    void deleteTables();

    PrimAlgorithm(GraphRepresentation *graphRepresentation) :
            AlgorithmsMST(graphRepresentation) {
        createTable();
    }

    ~PrimAlgorithm() {
        deleteTables();
    }
};


#endif //ALGORYTMYGRAFOWE_PRIMALGORITHM_H
