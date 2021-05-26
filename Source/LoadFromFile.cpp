#include "../Header/LoadFromFile.h"
#include <iostream>

//zaladowanie pliku grafu
bool LoadFromFile::openFile(){
    std::string nameOfFile = "testK.txt";

    /*std::cout << "Podaj nazwe pliku" << std::endl;
    std::cin >> nameOfFile;*/

    file.open(nameOfFile);
    if(!file.is_open())
        return false;
    else
        return true;
}
//pobieranie liczb z plikuw
int LoadFromFile::getDataFromFile() {

    int number;

    file >> number;

    return number;

}

