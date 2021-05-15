#include <iostream>
#include "../../Header/MinimalSpanningTree/AlgorithmsMST.h"

//wpisujemy nowa krawedz do tabeli MST
bool AlgorithmsMST::addNextEdge(int *w_min, int x_min, int y_min, int k) {

    //jesli nie znalezlismy zadnej pasujacej krawedzi
    //to wskaznik na minimalna wage bedzie wskazywal nullpointera
    //wiec znalezlismy MST

    if (w_min != nullptr) {
        tabLeMST[k][0] = x_min;
        tabLeMST[k][1] = y_min;
        tabLeMST[k][2] = *w_min;

        return true;
    }
    return false;

}

//sortuje krawedzie przed wyswietleniem
void AlgorithmsMST::sortMST() {

    //sortowanie  pozycyjne
    checkedPosition(1);
    checkedPosition(0);

}
//sortowanie bąbelkowe
void AlgorithmsMST::checkedPosition(int const position) {

    bool changeSomething = false;

    for (int j = 0; j < gr->getVerticesNumber() - 1; j++) {
        for (int i = 0; i < gr->getVerticesNumber() - 2 - j; i++) {
            if (tabLeMST[i][position] > tabLeMST[i + 1][position]) {
                std::swap(tabLeMST[i], tabLeMST[i + 1]);
                changeSomething = true;
            }
        }
        if (!changeSomething)
            break;
        else
            changeSomething = false;
    }

}
//wyswietlanie MST
void AlgorithmsMST::showMST() {

    sortMST();
    int sum = 0;

    std::cout << "Edge   Weight\n";
    for (int i = 0; i < gr->getVerticesNumber() - 1; i++) {
        std::cout << "(" << tabLeMST[i][0] << ", " << tabLeMST[i][1]
                  << ") " << tabLeMST[i][2] << std::endl;
        sum += tabLeMST[i][2];
    }
    std::cout << "Sum: " << sum << std::endl;
    deleteTables();
}

//zwalnianie pamieci
void AlgorithmsMST::deleteTables() {
    for (int i = 0; i < gr->getVerticesNumber() - 1; i++) {
        delete[] tabLeMST;
    }
    delete tabLeMST;

}
