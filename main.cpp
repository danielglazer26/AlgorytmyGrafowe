#include <iostream>
#include "Header/MinimalSpanningTree/KruskalAlgorithm.h"
#include "Header/MinimalSpanningTree/PrimAlgorithm.h"
#include "Header/TheShortestPath/DijkstraAlgorithm.h"
#include "Header/TheShortestPath/BellmanFordAlgorithm.h"

void menu(){

}
int main() {
    /*GraphRepresentation * graphRepresentation1 = new GraphRepresentation(false);
    KruskalAlgorithm *kruskalAlgorithm= new KruskalAlgorithm(graphRepresentation1);
    kruskalAlgorithm->findMSTbyList();
    kruskalAlgorithm->showMST();
    PrimAlgorithm * primAlgorithm = new PrimAlgorithm(graphRepresentation1);
    primAlgorithm->findMSTbyMatrix();
    primAlgorithm->showMST();*/

    GraphRepresentation *graphRepresentation = new GraphRepresentation(true);
    DijkstraAlgorithm *dijkstraAlgorithm = new DijkstraAlgorithm(graphRepresentation);
    dijkstraAlgorithm->findMinimalPathByList();
    dijkstraAlgorithm->showPath();
    BellmanFordAlgorithm *bellmanFordAlgorithm = new BellmanFordAlgorithm(graphRepresentation);
    bellmanFordAlgorithm->findMinimalPathByMatrix();
    bellmanFordAlgorithm->showPath();

    return 0;

}
