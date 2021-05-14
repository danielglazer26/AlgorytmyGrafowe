
#ifndef ALGORYTMYGRAFOWE_PRIMALGORITHM_H
#define ALGORYTMYGRAFOWE_PRIMALGORITHM_H

#include "AlgorithmsMST.h"

class PrimAlgorithm : public AlgorithmsMST {
private:

    void createTable();

public:
    PrimAlgorithm(GraphRepresentation *graphRepresentation):
    AlgorithmsMST(graphRepresentation) {}
};


#endif //ALGORYTMYGRAFOWE_PRIMALGORITHM_H
