#include <iostream>
#include "Header/MinimalSpanningTree/KruskalAlgorithm.h"
#include "Header/MinimalSpanningTree/PrimAlgorithm.h"
#include "Header/TheShortestPath/DijkstraAlgorithm.h"
#include "Header/TheShortestPath/BellmanFordAlgorithm.h"
#include "Test/Tests.h"

bool checkFile(GraphRepresentation *gr) {
    if (gr != nullptr)
        if (gr->getCombinedList() != nullptr)
            return true;
    return false;
}

void mstMenu() {
    int b;
    GraphRepresentation *unDirected = nullptr;
    do {
        std::cout << "1. Wczytaj plik \n"
                  << "2. Wyswietl macierz \n"
                  << "3. Wyswietl liste \n"
                  << "4. Algorytm Kruskala \n"
                  << "5. Algorytm Prima \n"
                  << "6. Wyjscie \n"
                  << "Opcja:";

        std::cin >> b;
        switch (b - 1) {
            case 0:
                if (checkFile(unDirected))
                    delete unDirected;
                    unDirected = new GraphRepresentation(false);
                break;
            case 1:
                if (checkFile(unDirected))
                    unDirected->getMatrix()->showMatrixWages();
                break;
            case 2:
                if (checkFile(unDirected))
                    unDirected->getCombinedList()->showList();
                break;
            case 3:
                if (checkFile(unDirected)) {
                    KruskalAlgorithm *kam = new KruskalAlgorithm(unDirected);
                    std::cout << "Rozwiazanie na macierzy \n";
                    kam->findMSTbyMatrix();
                    kam->showMST();
                    KruskalAlgorithm *kal = new KruskalAlgorithm(unDirected);
                    std::cout << "Rozwiazanie na liscie \n";
                    kal->findMSTbyList();
                    kal->showMST();
                    delete kal;
                }
                break;
            case 4:
                if (checkFile(unDirected)) {
                    PrimAlgorithm *pam = new PrimAlgorithm(unDirected);
                    std::cout << "Rozwiazanie na macierzy \n";
                    pam->findMSTbyMatrix();
                    pam->showMST();
                    delete pam;
                    PrimAlgorithm *pal = new PrimAlgorithm(unDirected);
                    std::cout << "Rozwiazanie na liscie \n";
                    pal->findMSTbyList();
                    pal->showMST();
                    delete pal;
                }
                break;
            case 5:
                if (checkFile(unDirected))
                    delete unDirected;

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
                  << "6. Wyjscie \n"
                  << "Opcja:";

        std::cin >> b;
        switch (b - 1) {
            case 0:
                if (checkFile(directed))
                    delete directed;
                    directed = new GraphRepresentation(true);
                break;
            case 1:
                if (checkFile(directed))
                    directed->getMatrix()->showMatrixWages();
                break;
            case 2:
                if (checkFile(directed))
                    directed->getCombinedList()->showList();
                break;
            case 3:
                if (checkFile(directed)) {
                    DijkstraAlgorithm *dam = new DijkstraAlgorithm(directed);
                    std::cout << "Rozwiazanie na macierzy \n";
                    dam->findMinimalPathByMatrix();
                    dam->showPathTable();
                    dam->showPath();
                    delete dam;
                    DijkstraAlgorithm *dal = new DijkstraAlgorithm(directed);
                    std::cout << "Rozwiazanie na liscie \n";
                    dal->findMinimalPathByList();
                    dal->showPathTable();
                    dal->showPath();
                    delete dal;
                }
                break;
            case 4:
                if (checkFile(directed)) {
                    BellmanFordAlgorithm *bfam = new BellmanFordAlgorithm(directed);
                    std::cout << "Rozwiazanie na macierzy \n";
                    bfam->findMinimalPathByMatrix();
                    bfam->showPathTable();
                    bfam->showPath();
                    BellmanFordAlgorithm *bfal = new BellmanFordAlgorithm(directed);
                    std::cout << "Rozwiazanie na liscie \n";
                    bfal->findMinimalPathByList();
                    bfal->showPathTable();
                    bfal->showPath();
                    delete bfal;
                }
                break;
            case 5:
                if (checkFile(directed))
                    delete directed;

        }

    } while (b != 6);
}

void menu() {
    int a;
    do {
        std::cout << "\n1. Minimalne drzewo rozpinajace \n"
                  << "2. Najkrotsza sciezka \n"
                  << "3. Testy\n"
                  << "4. Wyjscie \n"
                  << "Opcja:";
        std::cin >> a;
        switch (a - 1) {
            case 0:
                mstMenu();
                break;
            case 1:
                spMenu();
                break;
            case 2:
                (new Tests)->startTests();
                break;
        }

    } while (a != 4);

}

int main() {
    menu();

    return 0;

}
