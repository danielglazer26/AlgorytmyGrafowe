#ifndef ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H
#define ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H

#include "GraphRepresentation.h"

class KruskalAlgorithm {
private:
    int **tabLeMST;
    int *tableColor;
    GraphRepresentation *gr;

    void createTable();

public:

    KruskalAlgorithm() {
        gr = new GraphRepresentation(false);
        createTable();
    }

    void findMSTbyMatrix();

    void findMSTbyList();
};


#endif //ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H
