#include "../../Header/MinimalSpanningTree/PrimAlgorithm.h"

void PrimAlgorithm::createTable() {

    visitedTable = new bool[gr->getVerticesNumber()];
    tabLeMST = new int *[gr->getVerticesNumber() - 1];

    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        visitedTable[i] = false;
        if (i != gr->getVerticesNumber() - 1)
            tabLeMST[i] = new int[3];
    }

    visitedTable[0] = true;
}

//wywolanie rekurencyjnego algorytmu dla macierzy
void PrimAlgorithm::findMSTbyMatrix() {

    int *x_min = new int[1];
    int *y_min = new int[1];
    findMSTbyMatrix(0, x_min, y_min);
    delete [] x_min;
    delete [] y_min;
}

//rekurencyjna wersja algorytmu dla macierzy
void PrimAlgorithm::findMSTbyMatrix(int k, int *x_min, int *y_min) {


    int w_min = INT32_MAX;



    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        if (visitedTable[i]) {
            for (int j = 0; j < gr->getMatrix()->getSize(); j++) {

                //szukamy krawedzi o najmniejszej wadze, ktora prowadzi do nieodwiedzonego wierzchołka
                int pointer = gr->getMatrix()->getMatrixWeights()[i][j];
                if (!visitedTable[j]) {
                    if (w_min == INT32_MAX || pointer < w_min) {
                        *x_min = i;
                        *y_min = j;
                        w_min = pointer;
                    }
                }
            }
        }
    }

    if (addNextEdge(w_min, *x_min, *y_min, k)) {
        visitedTable[*y_min] = true;
        findMSTbyMatrix(k + 1, x_min, y_min);
    }
}

//wywolanie rekurencyjnego algorytmu dla listy
void PrimAlgorithm::findMSTbyList() {

    int *x_min = new int[1];
    int *y_min = new int[1];
    findMSTbyList(0, x_min, y_min);
    delete []x_min;
    delete []y_min;
}

//rekurencyjna wersja algorytmu dla listy
void PrimAlgorithm::findMSTbyList(int k, int *x_min, int *y_min) {

    int w_min = INT32_MAX;

    for (int i = 0; i < gr->getCombinedList()->getSize(); i++) {
        if (visitedTable[i]) {
            CombinedList::EdgeList *pointer = gr->getCombinedList()->getList()[i];
            while (true) {
                if (!visitedTable[pointer->vertex]) {
                    if (w_min == INT32_MAX || pointer->weight < w_min) {
                        *x_min = i;
                        *y_min = pointer->vertex;
                        w_min = pointer->weight;
                    }

                }
                if (pointer->next != nullptr)
                    pointer = pointer->next;
                else
                    break;

            }

        }

    }
    if (addNextEdge(w_min, *x_min, *y_min, k)) {
        visitedTable[*y_min] = true;
        findMSTbyList(k + 1, x_min, y_min);
    }


}
//usuwanie tabeli
void PrimAlgorithm::deleteTables() {
    AlgorithmsMST::deleteTables();
    delete visitedTable;
}
