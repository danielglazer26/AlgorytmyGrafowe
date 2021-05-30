#include "Tests.h"
#include "../Header/MinimalSpanningTree/PrimAlgorithm.h"
#include "../Header/MinimalSpanningTree/KruskalAlgorithm.h"
#include "../Header/TheShortestPath/DijkstraAlgorithm.h"
#include "../Header/TheShortestPath/BellmanFordAlgorithm.h"
#include <windows.h>
#include <random>
#include <iostream>


long long int Tests::read_QPC() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return ((long long int) count.QuadPart);
}

void Tests::startTests() {

    QueryPerformanceFrequency((LARGE_INTEGER *) &frequency);

    int sizeOfStructure = 100; //{x, 10x}
    float density;

    //ilosci algorytmow
    for (int i = 0; i < 4; i++) {

        std::string words = "";
        switch (i) {
            case 0:
                words = "---------------------------------\n";
                words += "   Test dla Algorytmu Kruskala\n";
                words += "---------------------------------\n";
                break;
            case 1:
                words = "---------------------------------\n";
                words += "   Test dla Algorytmu Prima\n";
                words += "---------------------------------\n";
                break;
            case 2:
                words = "---------------------------------\n";
                words += "   Test dla Algorytmu Dijkstry\n";
                words += "---------------------------------\n";
                break;
            case 3:
                words = "---------------------------------------\n";
                words += "   Test dla Algorytmu Bellmana-Forda\n";
                words += "---------------------------------------\n";
                break;
        }
        std::cout << words;
        writeToFile(words);


        //wybor gestosci grafu
        for (int j = 0; j < 4; j++) {

            switch (j) {
                case 0:
                    density = 0.25;
                    break;
                case 1:
                    density = 0.5;
                    break;
                case 2:
                    density = 0.75;
                    break;
                case 3:
                    density = 0.99;
                    break;
            }

            std::cout << "---------------------------------\n"
                      << "Gestosc grafu: " << density * 100 << "%\n"
                      << "---------------------------------\n";

            words = "Gestosc grafu: ";
            writeToFile(words);
            words = std::to_string(density * 100);
            words += "%\n";
            writeToFile(words);


            //rozmiar grafu
            for (int k = 0; k < 5; k++) {

                std::cout << "Rozmiar grafu: " << sizeOfStructure + k * sizeOfStructure << std::endl;


                double *results = new double[3];
                results[0] = sizeOfStructure + k * sizeOfStructure;

                //typ struktury
                for (int l = 0; l < 2; l++) {

                    double averageTime = 0;

                    //ilosc testow
                    for (int m = 0; m < 100; m++) {
                        switch (i) {
                            case 0:
                                averageTime += kruskalTest(l, sizeOfStructure + k * sizeOfStructure, density);
                                break;
                            case 1:
                                averageTime += primTest(l, sizeOfStructure + k * sizeOfStructure, density);
                                break;
                            case 2:
                                averageTime += dijkstraTest(l, sizeOfStructure + k * sizeOfStructure, density);
                                break;
                            case 3:
                                averageTime += bellmanFordTest(l, sizeOfStructure + k * sizeOfStructure, density);
                                break;
                        }
                    }
                    switch (l) {
                        case 0:
                            results[1] = averageTime / 100;
                            std::cout << "Czas dla listy: " << results[1] << std::endl;
                            break;
                        case 1:
                            results[2] = averageTime / 100;
                            std::cout << "Czas dla macierzy: " << results[2] << std::endl << std::endl;
                            break;
                    }


                }
                writeToFile(results);
                delete[]results;

            }

        }

    }

}

void Tests::writeToFile(double *results) {

    std::fstream file;
    file.open("wyniki.txt", std::ios::app);
    if (!file) {
        std::cout << "Błąd odczytu pilku!\n";
    } else {
        for (int i = 0; i < 3; i++)
            file << results[i] << " ";
        file << std::endl;
        file.close();
    }
}

void Tests::writeToFile(std::string words) {

    std::fstream file;
    file.open("wyniki.txt", std::ios::app);
    if (!file) {
        std::cout << "Błąd odczytu pilku!\n";
    } else {
        file << words;
        file.close();
    }
}

double Tests::kruskalTest(int typeOfStructure, int size, float density) {

    GraphRepresentation *gr = new GraphRepresentation(false, density, size);
    KruskalAlgorithm *kruskalAlgorithm = new KruskalAlgorithm(gr);

    start = read_QPC();
    if (typeOfStructure == 0)
        kruskalAlgorithm->findMSTbyList();
    else
        kruskalAlgorithm->findMSTbyMatrix();

    elapsed = read_QPC() - start;

    kruskalAlgorithm->deleteTables();
    delete kruskalAlgorithm;
    delete gr;
    return (1000.0 * elapsed) / frequency;
}

double Tests::primTest(int typeOfStructure, int size, float density) {

    GraphRepresentation *gr = new GraphRepresentation(false, density, size);

    PrimAlgorithm *primAlgorithm = new PrimAlgorithm(gr);

    start = read_QPC();

    if (typeOfStructure == 0)
        primAlgorithm->findMSTbyList();
    else
        primAlgorithm->findMSTbyMatrix();

    elapsed = read_QPC() - start;

    primAlgorithm->deleteTables();

    delete primAlgorithm;
    delete gr;
    return (1000.0 * elapsed) / frequency;
}

double Tests::dijkstraTest(int typeOfStructure, int size, float density) {

    GraphRepresentation *gr = new GraphRepresentation(true, density, size);

    DijkstraAlgorithm *dijkstraAlgorithm = new DijkstraAlgorithm(gr);

    start = read_QPC();

    if (typeOfStructure == 0)
        dijkstraAlgorithm->findMinimalPathByList();
    else
        dijkstraAlgorithm->findMinimalPathByMatrix();

    elapsed = read_QPC() - start;

    delete dijkstraAlgorithm;
    delete gr;
    return (1000.0 * elapsed) / frequency;
}

double Tests::bellmanFordTest(int typeOfStructure, int size, float density) {

    GraphRepresentation *gr = new GraphRepresentation(true, density, size);

    BellmanFordAlgorithm *bellmanFordAlgorithm = new BellmanFordAlgorithm(gr);

    start = read_QPC();

    if (typeOfStructure == 0)
        bellmanFordAlgorithm->findMinimalPathByList();
    else
        bellmanFordAlgorithm->findMinimalPathByMatrix();

    elapsed = read_QPC() - start;

    delete bellmanFordAlgorithm;
    delete gr;
    return (1000.0 * elapsed) / frequency;
}

