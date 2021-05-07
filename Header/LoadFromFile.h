#ifndef ALGORYTMYGRAFOWE_LOADFROMFILE_H
#define ALGORYTMYGRAFOWE_LOADFROMFILE_H


#include <fstream>

class LoadFromFile {
public:
    bool openFile();

    int getDataFromFile();

    ~LoadFromFile() {
        file.close();
    }
private:

    std::fstream file;
};


#endif //ALGORYTMYGRAFOWE_LOADFROMFILE_H
