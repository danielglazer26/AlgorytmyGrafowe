#include <iostream>
#include "../../Header/MinimalSpanningTree/KruskalAlgorithm.h"

//tworzymy tablice
void KruskalAlgorithm::createTable() {
    colorTable = new int[gr->getVerticesNumber()];
    tabLeMST = new int *[gr->getVerticesNumber() - 1];

    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        colorTable[i] = i;
        if (i != gr->getVerticesNumber() - 1)
            tabLeMST[i] = new int[3];
    }

}

//uruchamiamy rekurencyjnie algorytm dla macierzy
void KruskalAlgorithm::findMSTbyMatrix() {
    createTable();
    findMSTbyMatrix(0);
}

//uruchamiany rekurencyjnie algorytm dla listy
void KruskalAlgorithm::findMSTbyList() {
    createTable();
    findMSTbyList(0);
}

//rekurencyjna wersja algorytmu dla macierzy
void KruskalAlgorithm::findMSTbyMatrix(int k) {

    int x_min;
    int y_min;
    int *w_min = nullptr;
    // size - 1 bo zakladamy że nie wystepuja petle

    //szukamy krawedzi z najmniejsza waga, ktora nie spowoduje cyklu
    for (int i = 0; i < gr->getMatrix()->getSize() - 1; i++) {
        for (int j = i + 1; j < gr->getMatrix()->getSize(); j++) {
            if (gr->getMatrix()->getMatrixWeights()[i][j] != nullptr) {

                if (canAddThisEdge(i, j)) {
                    if (w_min == nullptr || *gr->getMatrix()->getMatrixWeights()[i][j] < *w_min) {
                        w_min = gr->getMatrix()->getMatrixWeights()[i][j];
                        x_min = i;
                        y_min = j;
                    }
                }
            }
        }
    }

    if (addNextEdge(w_min, x_min, y_min, k)) {
        changeColor(x_min, y_min);
        findMSTbyMatrix(k + 1);
    }


}
//rekurencyjna wersja algorytmu dla listy
void KruskalAlgorithm::findMSTbyList(int k) {

    int x_min;
    int y_min;
    int *w_min = nullptr;

    for (int i = 0; i < gr->getCombinedList()->getSize() - 1; i++) {
        CombinedList::EdgeList *pointer = gr->getCombinedList()->getList()[i];
        while (true) {
            if (canAddThisEdge(i, pointer->vertex)) {
                if (w_min == nullptr || pointer->weight < *w_min) {
                    x_min = i;
                    y_min = pointer->vertex;
                    w_min = &pointer->weight;
                }

            }
            if (pointer->next != nullptr)
                pointer = pointer->next;
            else
                break;

        }

    }

    if (addNextEdge(w_min, x_min, y_min, k)) {
        changeColor(x_min, y_min);
        findMSTbyList(k + 1);
    }

}

bool KruskalAlgorithm::canAddThisEdge(int x, int y) {

    //jesli istnieja dwa wierzcholki w MST to sprawdzamy czy maja taki sam kolor
    if (canAddThisEdge(x)) {
        if (canAddThisEdge(y)) {
            if (colorTable[x] == colorTable[y])
                return false;
        }
    }
    return true;

}

bool KruskalAlgorithm::canAddThisEdge(int x) {

    //sprawdzamy czy wystepuje taki wierzcholek w MST

    for (int i = 0; i < gr->getVerticesNumber() - 1; i++) {
        if (tabLeMST[i][0] == x || tabLeMST[i][1] == x) {
            return true;
        }
    }
    return false;

}


//zamiana kolorow wierzcholkow
void KruskalAlgorithm::changeColor(int x, int y) {


    int colorToChange = colorTable[y];
    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        if (colorTable[i] == colorToChange)
            colorTable[i] = colorTable[x];
    }


}

void KruskalAlgorithm::deleteTables() {
    AlgorithmsMST::deleteTables();
    delete colorTable;
}






