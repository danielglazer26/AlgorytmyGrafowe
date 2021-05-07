
#ifndef ALGORYTMYGRAFOWE_EDGESSORTEDLIST_H

class EdgesSortedList {

private:

    int size;

    int **edgeList;

public:

    EdgesSortedList(int size) {
        this->size = size;
        edgeList = new int *[size];
    }

    ~EdgesSortedList() {
        deleteList();
    }

    void createEdgeList(int i, const int *e);

    void showList();

    void deleteList();

    int getSize() const;

    int **getList();

};


#define ALGORYTMYGRAFOWE_EDGESSORTEDLIST_H


#endif //ALGORYTMYGRAFOWE_EDGESSORTEDLIST_H
