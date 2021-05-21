#include "../Header/Queue.h"

//dodanie elementu na poczatek
void Queue::beginAddElementToQueue(int numberToAdd) {

    if (headIsNotNULL(numberToAdd)) {
        head->previous = new ListElement();
        head->previous->next = head;
        head = head->previous;
        head->number = numberToAdd;
    }

}

//dodanie elementu do kolejki
void Queue::push(int numberToAdd) {

    if (headIsNotNULL(numberToAdd)) {
        tail->next = new ListElement();
        tail = tail->next;
        tail->number = numberToAdd;
    }
}

//pobranie elementu z kolejki
int * Queue::getFirst() {
    return &head->number;
}

void Queue::pop() {
    ListElement *pointer;
    if (head != tail) {
        pointer = head->next;
        delete head;
        head = pointer;
    } else {
        delete head;
        head = tail = nullptr;
    }
}

//sprawdzenie czy do glowy jest przypisany jakis wskaznik
//czy jest jakis element w liscie
bool Queue::headIsNotNULL(int numberToAdd) {

    if (head == nullptr) {
        head = new ListElement();
        head->number = numberToAdd;
        tail = head;
        return false;
    }
    return true;
}

