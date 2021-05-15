
#ifndef ALGORYTMYGRAFOWE_PRIMALGORITHM_H
#define ALGORYTMYGRAFOWE_PRIMALGORITHM_H

#include "AlgorithmsMST.h"

class PrimAlgorithm : public AlgorithmsMST {
private:

    bool *visitedTable;

    void createTable();

    void deleteTables();

    void findMSTbyMatrix(int k);

    void findMSTbyList(int k);

public:

    void findMSTbyMatrix();

    void findMSTbyList();

    PrimAlgorithm(GraphRepresentation *graphRepresentation) :
            AlgorithmsMST(graphRepresentation) {}
};


#endif //ALGORYTMYGRAFOWE_PRIMALGORITHM_H