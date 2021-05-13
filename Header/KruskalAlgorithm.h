#ifndef ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H
#define ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H

#include "GraphRepresentation.h"

class KruskalAlgorithm {
private:
    int **tabLeMST;
    int *tableColor;
    GraphRepresentation *gr;

    void createTable();

    void findMSTbyMatrix(int k);

    void findMSTbyList(int k);

    bool canAddThisEdge(int x, int y);

    bool canAddThisEdge(int x);

    void changeColor(int x, int y);

    bool addNextEdge(int *w_min, int x_min, int y_min, int k);

    void deleteTables();

    void sortMST();

    void checkedPosition(const int position);

public:


    KruskalAlgorithm() {
        gr = new GraphRepresentation(false);
    }


    void findMSTbyMatrix();

    void findMSTbyList();

    void showMST();


};


#endif //ALGORYTMYGRAFOWE_KRUSKALALGORITHM_H
