
#ifndef ALGORYTMYGRAFOWE_MATRIX_H
#define ALGORYTMYGRAFOWE_MATRIX_H


#include "CombinedList.h"

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

    void createMatrix(CombinedList *combinedList);

private:
    int size;

    int **matrixTable;

    int ***matrixWeights;

    void createTables();

    void deleteMatrixTable();
};


#endif //ALGORYTMYGRAFOWE_MATRIX_H
