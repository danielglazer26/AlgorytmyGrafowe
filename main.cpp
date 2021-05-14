#include <iostream>
#include "Header/KruskalAlgorithm.h"

void menu(){

}
int main() {


    GraphRepresentation *graphRepresentation = new GraphRepresentation(false);
    KruskalAlgorithm *kruskalAlgorithm = new KruskalAlgorithm(graphRepresentation);
    kruskalAlgorithm->findMSTbyList();
    kruskalAlgorithm->showMST();
    kruskalAlgorithm->findMSTbyMatrix();
    kruskalAlgorithm->showMST();
    return 0;

}
