#include <iostream>
#include "Header/KruskalAlgorithm.h"

int main() {

    KruskalAlgorithm kruskalAlgorithm;
    kruskalAlgorithm.findMSTbyList();
    kruskalAlgorithm.showMST();
    kruskalAlgorithm.findMSTbyMatrix();
    kruskalAlgorithm.showMST();
    return 0;

}
