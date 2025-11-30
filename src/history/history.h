#ifndef HISTORY_H
#define HISTORY_H

#include "../patient.h"

struct HistoryNode {
    Patient data;
    HistoryNode* next;

    HistoryNode(Patient p) {
        data = p;
        next = nullptr;
    }
};

class HistoryList {
private:
    HistoryNode* head;
    HistoryNode* tail;

public:
    HistoryList();
    void add(Patient p);
    void display();
};

#endif

