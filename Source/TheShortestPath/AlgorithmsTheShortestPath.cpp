
#include <iostream>
#include "../../Header/TheShortestPath/AlgorithmsTheShortestPath.h"

//wyswietlanie sciezki dla problemu najkrotszej sciezki w grafie
void AlgorithmsTheShortestPath::showPath() {

    if (cycleDetector <= gr->getEdgesNumber()) {
        std::cout << "Start= " << gr->getStartingVertex() << "\nEnd Dist  Path" << std::endl;
        for (int i = 0; i < gr->getVerticesNumber(); i++) {
            showPath(i);
        }
    } else
        std::cout << "Wystapil cykl ujemny" << std::endl;

}

//obliczanie dlugosci
void AlgorithmsTheShortestPath::showPath(int k) {

    bool exception = false;
    int i = k;
    int *stack = new int[gr->getVerticesNumber()];
    int stackIterator = 0;
    while (pathTable[i][1] != -1) {
        stack[stackIterator++] = i;
        i = pathTable[i][1];
        if (stackIterator > gr->getVerticesNumber() - 1) {
            exception = true;
            break;
        }

    }
    if (exception)
        std::cout << "Wynik moze byc niepoprawny\n";

    std::cout << " " << k << " | ";
    if (pathTable[k][0] != INT32_MAX) {
        std::cout << pathTable[k][0] << " | " << gr->getStartingVertex() << " ";
        while (stackIterator) {
            std::cout << stack[--stackIterator] << " ";
        }
    } else
        std::cout << "Brak polaczenia";
    std::cout << std::endl;


}

//wyswietlanie tablicy sciezek
void AlgorithmsTheShortestPath::showPathTable() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < gr->getVerticesNumber(); j++) {
            if (i == 0)
                std::cout << j << " ";
            else
                std::cout << pathTable[j][i - 1] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}

//usuwanie tablic
void AlgorithmsTheShortestPath::deleteTables() {
    for (int i = 0; i < gr->getVerticesNumber(); i++) {
        delete pathTable[i];
    }
    delete pathTable;
    delete visitedTable;
}

void AlgorithmsTheShortestPath::createTable() {

    pathTable = new int *[gr->getVerticesNumber()];
    visitedTable = new bool[gr->getVerticesNumber()];
    for (int i = 0; i < gr->getVerticesNumber(); i++) {

        pathTable[i] = new int[2];
        pathTable[i][0] = INT32_MAX; //odpowiednik nieskonczonosci
        pathTable[i][1] = -1;
        visitedTable[i] = false;
    }
    pathTable[gr->getStartingVertex()][0] = 0;
}
