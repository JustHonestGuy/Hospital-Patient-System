#include "CircularQueue.h"

CircularQueue::CircularQueue(int capacity) {
    if (capacity <= 0) capacity = 100;
    this->capacity = capacity;
    arr = new Patient[capacity];
    front = rear = size = 0;
}

CircularQueue::~CircularQueue() {
    delete[] arr;
}

bool CircularQueue::isFull() const {
    return size == capacity;
}

bool CircularQueue::isEmpty() const {
    return size == 0;
}

void CircularQueue::enqueue(const Patient& p) {
    if (isFull()) {
        std::cout << "Normal Patient Queue is FULL! Cannot add patient ID: "
                  << p.id << " (" << p.name << ")\n";
        return;
    }

    arr[rear] = p;
    rear = (rear + 1) % capacity;
    size++;

    std::cout << "Patient " << p.name << " (ID: " << p.id
              << ", Severity: " << p.severity << ") added to normal queue.\n";
}

Patient CircularQueue::dequeue() {
    if (isEmpty()) {
        std::cout << "Normal queue is EMPTY! No patient to serve.\n";
        return Patient();  // assuming Patient has default constructor
    }

    Patient served = arr[front];
    front = (front + 1) % capacity;
    size--;

    std::cout << "Patient " << served.name << " (ID: " << served.id
              << ") dequeued from normal queue and sent to doctor.\n";

    return served;
}

void CircularQueue::display() const {
    if (isEmpty()) {
        std::cout << "\n===== Normal Patient Queue (FIFO) =====\n";
        std::cout << "     [ EMPTY - No patients waiting in normal line ]\n\n";
        return;
    }

    std::cout << "\n===== Normal Patient Queue (Arrival Order - FIFO) =====\n";
    int idx = front;
    for (int i = 0; i < size; i++) {
        std::cout << " " << (i + 1) << ". ID: " << arr[idx].id
                  << " | Name: " << arr[idx].name
                  << " | Severity: " << arr[idx].severity
                  << " | Time: " << arr[idx].arrivalTime << "\n";
        idx = (idx + 1) % capacity;
    }
    std::cout << " Total patients in normal queue: " << size << "\n\n";
}
