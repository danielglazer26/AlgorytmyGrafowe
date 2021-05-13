#include <iostream>
#include "../Header/KruskalAlgorithm.h"

//tworzymy tablice
void KruskalAlgorithm::createTable() {
    tableColor = new int[gr->getVerticesNumber()];
    tabLeMST = new int *[gr->getVerticesNumber() - 1];

    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        tableColor[i] = i;
        if (i != gr->getVerticesNumber() - 1)
            tabLeMST[i] = new int[3];
    }

}

//uruchamiamy rekurencyjnie algorytm
void KruskalAlgorithm::findMSTbyMatrix() {
    createTable();
    findMSTbyMatrix(0);
}

void KruskalAlgorithm::findMSTbyList() {
    createTable();
    findMSTbyList(0);
}

//rekurencyjna wersja algorytmu
void KruskalAlgorithm::findMSTbyMatrix(int k) {

    int x_min;
    int y_min;
    int *w_min = nullptr;
    // size - 1 bo zakladamy że nie wystepuja petle

    //szukamy krawedzi z najmniejsza waga, ktora nie spowoduje cyklu
    for (int i = 0; i < gr->getMatrix()->getSize() - 1; i++) {
        for (int j = i + 1; j < gr->getMatrix()->getSize(); j++) {
            if (gr->getMatrix()->getMatrixWeights()[i][j] != nullptr) {

                if (canAddThisEdge(i, j)) {
                    if (w_min == nullptr || *gr->getMatrix()->getMatrixWeights()[i][j] < *w_min) {
                        w_min = gr->getMatrix()->getMatrixWeights()[i][j];
                        x_min = i;
                        y_min = j;
                    }
                }
            }
        }
    }
    //jesli nie znalezlismy zadnej pasujacej krawedzi
    //to wskaznik na minimalna wage bedzie wskazywal nullpointera
    //wiec znalezlismy MST
    if (addNextEdge(w_min, x_min, y_min, k))
        findMSTbyMatrix(k + 1);


}

void KruskalAlgorithm::findMSTbyList(int k) {

    int x_min;
    int y_min;
    int *w_min = nullptr;

    for (int i = 0; i < gr->getCombinedList()->getSize() - 1; i++) {
        CombinedList::EdgeList *pointer = gr->getCombinedList()->getList()[i];
        while (true) {
            if (canAddThisEdge(i, pointer->vertex)) {
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

    if (addNextEdge(w_min, x_min, y_min, k))
        findMSTbyList(k + 1);

}

bool KruskalAlgorithm::canAddThisEdge(int x, int y) {

    //jesli istnieja dwa wierzcholki w MST to sprawdzamy czy maja taki sam kolor
    if (canAddThisEdge(x)) {
        if (canAddThisEdge(y)) {
            if (tableColor[x] == tableColor[y])
                return false;
        }
    }
    return true;

}

bool KruskalAlgorithm::canAddThisEdge(int x) {

    //sprawdzamy czy wystepuje taki wierzcholek w MST

    for (int i = 0; i < gr->getVerticesNumber() - 1; i++) {
        if (tabLeMST[i][0] == x || tabLeMST[i][1] == x) {
            return true;
        }
    }
    return false;

}


//zamiana kolorow wierzcholkow
void KruskalAlgorithm::changeColor(int x, int y) {


    int colorToChange = tableColor[y];
    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        if (tableColor[i] == colorToChange)
            tableColor[i] = tableColor[x];
    }


}

//wpisujemy nowa krawedz do tabeli MST
bool KruskalAlgorithm::addNextEdge(int *w_min, int x_min, int y_min, int k) {

    if (w_min != nullptr) {
        tabLeMST[k][0] = x_min;
        tabLeMST[k][1] = y_min;
        tabLeMST[k][2] = *w_min;
        changeColor(x_min, y_min);
        return true;
    }
    return false;

}

//zwalnianie pamieci
void KruskalAlgorithm::deleteTables() {
    for (int i = 0; i < gr->getVerticesNumber() - 1; i++) {
        delete[] tabLeMST;
    }
    delete tabLeMST;
    delete tableColor;

}

//wyswietlanie MST
void KruskalAlgorithm::showMST() {


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

//sortuje krawedzie przed wyswietleniem
void KruskalAlgorithm::sortMST() {

    //sortowanie  pozycyjne
    checkedPosition(1);
    checkedPosition(0);


}

//sortowanie bąbelkowe
void KruskalAlgorithm::checkedPosition(int const position) {

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

