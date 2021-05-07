
#ifndef ALGORYTMYGRAFOWE_MATRIX_H
#define ALGORYTMYGRAFOWE_MATRIX_H


#include "EdgesSortedList.h"

class Matrix {
public:
    Matrix(int size) {
        this->size = size;
        createTables();
    }

    ~Matrix() {
        deleteMatrixTable();
    }

    void showMatrix();

    void showMatrixWages();

    void createDirectedMatrix(EdgesSortedList *edgesSortedList);

    void createUndirectedMatrix(EdgesSortedList *list);
private:
    int size;

    int **matrixTable;

    int ***matrixWages;

    void createTables();

    void deleteMatrixTable();
};


#endif //ALGORYTMYGRAFOWE_MATRIX_H
