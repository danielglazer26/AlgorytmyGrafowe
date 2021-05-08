
#include <iostream>
#include "../Header/Matrix.h"

void Matrix::createTables() {

    matrixTable = new int *[size];
    matrixWeights = new int **[size];

    for (int i = 0; i < size; i++) {
        matrixTable[i] = new int[size];
        matrixWeights[i] = new int *[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrixTable[i][j] = 0;
            matrixWeights[i][j] = nullptr;
        }
    }
}

void Matrix::createMatrix(CombinedList *combinedList) {

    for (int i = 0; i < combinedList->getSize(); i++) {

        CombinedList::edge * pointer = combinedList->getList()[i];
        while (true) {
            int vE = pointer->vertex;
            int w = pointer->weight;

            matrixTable[i][vE] = 1;
            matrixWeights[i][vE] = new int[1];
            *matrixWeights[i][vE] = w;

            if(pointer->next!= nullptr)
                pointer = pointer->next;
            else
                break;
        }
    }
}



void Matrix::showMatrix() {
    std::cout << "  ";
    for (int i = 0; i < size + 1; i++) {

        for (int j = 0; j < size; j++) {
            if (i == 0)
                std::cout << j << " ";
            else
                std::cout << matrixTable[i - 1][j] << " ";
        }

        if (i != size)
            std::cout << std::endl << i << " ";

    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void Matrix::showMatrixWages() {

    std::cout << "  ";
    for (int i = 0; i < size + 1; i++) {

        for (int j = 0; j < size; j++) {
            if (i == 0)
                std::cout << j << " ";
            else {
                if (matrixWeights[i - 1][j] != nullptr)
                    std::cout << *matrixWeights[i - 1][j];
                else
                    std::cout << "N";

                std::cout << " ";
            }
        }

        if (i != size)
            std::cout << std::endl << i << " ";

    }
    std::cout << std::endl;
    std::cout << std::endl;

}

void Matrix::deleteMatrixTable() {
    for (int i = 0; i < size; i++) {
        delete[] matrixTable[i];
        delete[] matrixWeights[i];
    }
    delete matrixTable;
    delete matrixWeights;
}