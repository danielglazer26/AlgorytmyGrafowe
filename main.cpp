#include <iostream>
#include "Header/GraphRepresentation.h"

int main() {

    GraphRepresentation * gr = new GraphRepresentation(false);
    gr->getList()->showList();
    return 0;

}
