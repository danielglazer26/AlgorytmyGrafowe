
#ifndef ALGORYTMYGRAFOWE_ALGORITHMSMST_H
#define ALGORYTMYGRAFOWE_ALGORITHMSMST_H

#include "GraphRepresentation.h"

class AlgorithmsMST {
private:
    void sortMST();

    void checkedPosition(const int position);

protected:
    int **tabLeMST;
    GraphRepresentation *gr;

    virtual void deleteTables();

public:
    void showMST();

    AlgorithmsMST(GraphRepresentation * graphRepresentation){
        gr = graphRepresentation;
    }

};


#endif //ALGORYTMYGRAFOWE_ALGORITHMSMST_H
