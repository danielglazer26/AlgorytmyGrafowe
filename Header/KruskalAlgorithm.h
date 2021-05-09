#ifndef ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H
#define ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H

#include "GraphRepresentation.h"

class KruskalAlgorithm {
private:
    int **tabLeMST;
    int *tableColor;
    GraphRepresentation *gr;

    void createTable();

    void deleteTables();

public:

    KruskalAlgorithm() {
        gr = new GraphRepresentation(false);
        createTable();
    }

    ~KruskalAlgorithm(){
        deleteTables();
    }

    void findMSTbyMatrix();

    void findMSTbyList();

    bool canAddThisEdge(int x, int y);

    bool canAddThisEdge(int x);

    void findMSTbyMatrix(int k);

    void showMST();

    void changeColor(int x, int y);

    void sortMST();
};


#endif //ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H
