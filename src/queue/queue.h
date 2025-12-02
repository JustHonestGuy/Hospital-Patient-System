#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "../patient.h"
#include <iostream>
#include <string>

class CircularQueue {
private:
    Patient* arr;
    int front, rear, size, capacity;

public:
    // Constructor & Destructor
    CircularQueue(int capacity = 100);  // default size 100
    ~CircularQueue();

    // Core operations
    bool isFull() const;
    bool isEmpty() const;
    void enqueue(const Patient& p);      // pass by const ref (better)
    Patient dequeue();
    void display() const;                // should not modify object

    // Bonus: helpful for debugging
    int getSize() const { return size; }
};

#endif
