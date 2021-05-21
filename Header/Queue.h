

#ifndef ALGORYTMYGRAFOWE_QUEUE_H
#define ALGORYTMYGRAFOWE_QUEUE_H


class Queue {
private:
    struct ListElement {
        int number;
        ListElement *previous;
        ListElement *next;
    };

    ListElement *head = nullptr;
    ListElement *tail = nullptr;

    bool headIsNotNULL(int numberToAdd);


public:

    void beginAddElementToQueue(int numberToAdd);

    void push(int numberToAdd);

    int *getFirst();

    void pop();
};


#endif //ALGORYTMYGRAFOWE_QUEUE_H
