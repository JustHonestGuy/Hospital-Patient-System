#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "../patient.h"

class CircularQueue {
private:
    Patient* arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int capacity);
    ~CircularQueue();

    bool isFull();
    bool isEmpty();
    void enqueue(Patient p);
    Patient dequeue();
    void display();
};

#endif

