#ifndef ALGORYTMYGRAFOWE_TESTS_H
#define ALGORYTMYGRAFOWE_TESTS_H


#include "../Header/RepresentationOfGraph/GraphRepresentation.h"

class Tests {
private:
    long long int frequency, start, elapsed;

    static long long int read_QPC();

    double kruskalTest(int typeOfStructure, int size, float density);

    double primTest(int typeOfStructure, int size, float density);

    double dijkstraTest(int typeOfStructure, int size, float density);

    double bellmanFordTest(int typeOfStructure, int size, float density);

    void writeToFile(double *results);

    void writeToFile(std::string words);

public:
    void startTests();
};


#endif //ALGORYTMYGRAFOWE_TESTS_H
