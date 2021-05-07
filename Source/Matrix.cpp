
#include <iostream>
#include "../Header/Matrix.h"

void Matrix::createTables() {

    matrixTable = new int *[size];
    matrixWages = new int **[size];

    for (int i = 0; i < size; i++) {
        matrixTable[i] = new int[size];
        matrixWages[i] = new int *[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrixTable[i][j] = 0;
            matrixWages[i][j] = nullptr;
        }
    }
}

void Matrix::createDirectedMatrix(EdgesSortedList *edgesSortedList) {

    for (int i = 0; i < edgesSortedList->getSize(); i++) {

        int x = edgesSortedList->getList()[i][0];           //wierzcholek poczatkowy
        int y = edgesSortedList->getList()[i][1];           //wierzcholek koncowy
        int z = edgesSortedList->getList()[i][2];           //waga

        matrixTable[x][y] = 1;

        matrixWages[x][y] = new int[1];
        *matrixWages[x][y] = z;
    }
}

void Matrix::createUndirectedMatrix(EdgesSortedList *edgesSortedList) {
    for (int i = 0; i < edgesSortedList->getSize(); i++) {

        int x = edgesSortedList->getList()[i][0];           //wierzcholek poczatkowy
        int y = edgesSortedList->getList()[i][1];           //wierzcholek koncowy
        int z = edgesSortedList->getList()[i][2];           //waga

        matrixTable[x][y] = matrixTable[y][x] = 1;

        matrixWages[x][y] = new int[1];
        matrixWages[y][x] = new int[1];
        *matrixWages[y][x] = *matrixWages[x][y] = z;
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
                if (matrixWages[i - 1][j] != nullptr)
                    std::cout << *matrixWages[i - 1][j];
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
        delete[] matrixWages[i];
    }
    delete matrixTable;
    delete matrixWages;
}