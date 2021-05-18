#include <iostream>
#include "Header/MinimalSpanningTree/KruskalAlgorithm.h"
#include "Header/MinimalSpanningTree/PrimAlgorithm.h"
#include "Header/TheShortestPath/DijkstraAlgorithm.h"
#include "Header/TheShortestPath/BellmanFordAlgorithm.h"

void menu(){

}
int main() {


    GraphRepresentation *graphRepresentation = new GraphRepresentation(true);
   // DijkstraAlgorithm *dijkstraAlgorithm = new DijkstraAlgorithm(graphRepresentation);
   //dijkstraAlgorithm->createTable();
   //dijkstraAlgorithm->findMinimalPathByMatrix();
    BellmanFordAlgorithm *bellmanFordAlgorithm = new BellmanFordAlgorithm(graphRepresentation);
    bellmanFordAlgorithm->createTable();
    bellmanFordAlgorithm->findMinimalPathByMatrix();
    bellmanFordAlgorithm->showPath();
    return 0;

}
