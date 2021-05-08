#include "../Header/KruskalAlgorithm.h"


void KruskalAlgorithm::createTable() {
    tableColor = new int [gr->getVerticesNumber()];
    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        tableColor[i]= i;
    }
}

void KruskalAlgorithm::findMSTbyMatrix() {

    int x_min;
    int y_min;
    // size - 1 bo zakladamy że nie wystepuja petle
    for (int i = 0; i < gr->getMatrix()->getSize() - 1; i++) {
        for (int j = i + 1; j < gr->getMatrix()->getSize(); j++) {

        }
    }
}

void KruskalAlgorithm::findMSTbyList() {

}
