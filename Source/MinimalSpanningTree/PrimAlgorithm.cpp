#include "../../Header/MinimalSpanningTree/PrimAlgorithm.h"

void PrimAlgorithm::createTable() {

    visitedTable = new bool[gr->getVerticesNumber()];
    tabLeMST = new int *[gr->getVerticesNumber() - 1];

    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        visitedTable[i] = false;
        if (i != gr->getVerticesNumber() - 1)
            tabLeMST[i] = new int[3];
    }

}
//wywolanie rekurencyjnego algorytmu dla macierzy
void PrimAlgorithm::findMSTbyMatrix() {
    createTable();
    visitedTable[0] = true;
    findMSTbyMatrix(0);
}

//rekurencyjna wersja algorytmu dla macierzy
void PrimAlgorithm::findMSTbyMatrix(int k) {

    int x_min;
    int y_min;
    int *w_min = nullptr;

    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        if (visitedTable[i])
            for (int j = 0; j < gr->getMatrix()->getSize(); j++) {
                if (gr->getMatrix()->getMatrixWeights()[i][j] != nullptr && !visitedTable[j])
                    if (w_min == nullptr || *gr->getMatrix()->getMatrixWeights()[i][j] < *w_min) {
                        x_min = i;
                        y_min = j;
                        w_min = gr->getMatrix()->getMatrixWeights()[i][j];
                    }
            }
    }

    if (addNextEdge(w_min, x_min, y_min, k)) {
        visitedTable[y_min] = true;
        findMSTbyMatrix(k + 1);
    }
}

//wywolanie rekurencyjnego algorytmu dla listy
void PrimAlgorithm::findMSTbyList() {
    createTable();
    visitedTable[0] = true;
    findMSTbyList(0);
}
void PrimAlgorithm::findMSTbyList(int k) {

    int x_min;
    int y_min;
    int *w_min = nullptr;

    for (int i = 0; i < gr->getCombinedList()->getSize(); i++) {
        if (visitedTable[i]) {
            CombinedList::EdgeList *pointer = gr->getCombinedList()->getList()[i];
            while (true) {
                if (!visitedTable[pointer->vertex]) {
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

    }

    if (addNextEdge(w_min, x_min, y_min, k)) {
        visitedTable[y_min] = true;
        findMSTbyList(k + 1);
    }

}


void PrimAlgorithm::deleteTables() {
    AlgorithmsMST::deleteTables();
    delete visitedTable;
}
