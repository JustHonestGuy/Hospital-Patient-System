#include "queue.h"
#include <iostream>

CircularQueue::CircularQueue(int capacity) {
    this->capacity = capacity;
    arr = new Patient[capacity];
    front = rear = size = 0;
}

CircularQueue::~CircularQueue() {
    delete[] arr;
}

bool CircularQueue::isFull() {
    return size == capacity;
}

bool CircularQueue::isEmpty() {
    return size == 0;
}

void CircularQueue::enqueue(Patient p) {
    if (isFull()) {
        std::cout << "Queue full!\n";
        return;
    }
    arr[rear] = p;
    rear = (rear + 1) % capacity;
    size++;
}

Patient CircularQueue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue empty!\n";
        return Patient();
    }
    Patient p = arr[front];
    front = (front + 1) % capacity;
    size--;
    return p;
}

void CircularQueue::display() {
    if (isEmpty()) {
        std::cout << "Queue empty\n";
        return;
    }
    for (int i = 0, idx = front; i < size; i++) {
        std::cout << arr[idx].name << " -> ";
        idx = (idx + 1) % capacity;
    }
    std::cout << "\n";
}

