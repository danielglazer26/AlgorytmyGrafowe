#include "../Header/LoadFromFile.h"
#include <iostream>

bool LoadFromFile::openFile(){
    std::string nameOfFile = "testk.txt";

    /*std::cout << "Podaj nazwe pliku" << std::endl;
    std::cin >> nameOfFile;*/

    file.open(nameOfFile);
    if(!file.is_open())
        return false;
    else
        return true;
}

int LoadFromFile::getDataFromFile() {

    int number;

    file >> number;

    return number;

}

