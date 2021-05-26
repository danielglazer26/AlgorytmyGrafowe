#include <iostream>
#include "Header/MinimalSpanningTree/KruskalAlgorithm.h"
#include "Header/MinimalSpanningTree/PrimAlgorithm.h"
#include "Header/TheShortestPath/DijkstraAlgorithm.h"
#include "Header/TheShortestPath/BellmanFordAlgorithm.h"

void mstMenu() {
    int b;
    GraphRepresentation *unDirected = nullptr;
    do {
        std::cout << "1. Wczytaj plik \n"
                  << "2. Wyswietl macierz \n"
                  << "3. Wyswietl liste \n"
                  << "4. Algorytm Kruskala \n"
                  << "5. Algorytm Prima \n"
                  << "Opcja:";

        std::cin >> b;
        switch (b - 1) {
            case 0:
                unDirected = new GraphRepresentation(false);
                break;
            case 1:
                if (unDirected != nullptr)
                    unDirected->getMatrix()->showMatrixWages();
                break;
            case 2:
                if (unDirected != nullptr)
                    unDirected->getCombinedList()->showList();
                break;
            case 3:
                if (unDirected != nullptr) {
                    KruskalAlgorithm *ka = new KruskalAlgorithm(unDirected);
                    std::cout << "Rozwiazanie na macierzy \n";
                    ka->findMSTbyMatrix();
                    ka->showMST();
                    std::cout << "Rozwiazanie na liscie \n";
                    ka->findMSTbyList();
                    ka->showMST();
                    delete ka;
                }
                break;
            case 4:
                if (unDirected != nullptr) {
                    PrimAlgorithm *pa = new PrimAlgorithm(unDirected);
                    std::cout << "Rozwiazanie na macierzy \n";
                    pa->findMSTbyMatrix();
                    pa->showMST();
                    std::cout << "Rozwiazanie na liscie \n";
                    pa->findMSTbyList();
                    pa->showMST();
                    delete pa;
                }
                break;

        }

    } while (b != 6);
}

void spMenu() {
    int b;
    GraphRepresentation *directed = nullptr;
    do {
        std::cout << "\n1. Wczytaj plik \n"
                  << "2. Wyswietl macierz \n"
                  << "3. Wyswietl liste \n"
                  << "4. Algorytm Dijkstry \n"
                  << "5. Algorytm Bellmana-Forda \n"
                  << "Opcja:";

        std::cin >> b;
        switch (b - 1) {
            case 0:
                directed = new GraphRepresentation(true);
                break;
            case 1:
                if (directed != nullptr)
                    directed->getMatrix()->showMatrixWages();
                break;
            case 2:
                if (directed != nullptr)
                    directed->getCombinedList()->showList();
                break;
            case 3:
                if (directed != nullptr) {
                    DijkstraAlgorithm *da = new DijkstraAlgorithm(directed);
                    std::cout << "Rozwiazanie na macierzy \n";
                    da->findMinimalPathByMatrix();
                    da->showPath();
                    std::cout << "Rozwiazanie na liscie \n";
                    da->findMinimalPathByList();
                    da->showPath();
                }
                break;
            case 4:
                if (directed != nullptr) {
                    BellmanFordAlgorithm *bfa = new BellmanFordAlgorithm(directed);
                    std::cout << "Rozwiazanie na macierzy \n";
                    bfa->findMinimalPathByMatrix();
                    bfa->showPath();
                    std::cout << "Rozwiazanie na liscie \n";
                    bfa->findMinimalPathByList();
                    bfa->showPath();
                }
                break;

        }

    } while (b != 6);
}

void menu() {
    GraphRepresentation *unDirected = nullptr, *directed = nullptr;
    int a, b;
    do {
        std::cout << "\n1. Minimalne drzewo rozpinajace \n"
                  << "2. Najkrotsza sciezka \n"
                  << "3. Maksymalny przeplyw \n"
                  << "Opcja:";
        std::cin >> a;
        switch (a - 1) {
            case 0:
                mstMenu();
                break;
            case 1:
                spMenu();
                break;
        }

    } while (a != 4);

}

int main() {
    menu();
    /*GraphRepresentation * graphRepresentation1 = new GraphRepresentation(false);
    KruskalAlgorithm *kruskalAlgorithm= new KruskalAlgorithm(graphRepresentation1);
    kruskalAlgorithm->findMSTbyList();
    kruskalAlgorithm->showMST();
    PrimAlgorithm * primAlgorithm = new PrimAlgorithm(graphRepresentation1);
    primAlgorithm->findMSTbyMatrix();
    primAlgorithm->showMST();*/

    GraphRepresentation *graphRepresentation = new GraphRepresentation(true);
    DijkstraAlgorithm *dijkstraAlgorithm = new DijkstraAlgorithm(graphRepresentation);
    dijkstraAlgorithm->findMinimalPathByMatrix();
    dijkstraAlgorithm->showPath();
    BellmanFordAlgorithm *bellmanFordAlgorithm = new BellmanFordAlgorithm(graphRepresentation);
    bellmanFordAlgorithm->findMinimalPathByMatrix();
    bellmanFordAlgorithm->showPath();

    return 0;

}
