
#ifndef ALGORYTMYGRAFOWE_ALGORITHMSMST_H
#define ALGORYTMYGRAFOWE_ALGORITHMSMST_H

#include "../RepresentationOfGraph/GraphRepresentation.h"

class AlgorithmsMST {
private:
    void sortMST();

    void checkedPosition(const int position);

protected:
    int **tabLeMST;
    GraphRepresentation *gr;

    bool addNextEdge(int *w_min, int x_min, int y_min, int k);

    virtual void deleteTables();
public:

    void showMST();

    AlgorithmsMST(GraphRepresentation * graphRepresentation){
        gr = graphRepresentation;
    }
};


#endif //ALGORYTMYGRAFOWE_ALGORITHMSMST_H
