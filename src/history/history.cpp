#include "history.h"
#include <iostream>

HistoryList::HistoryList() {
    head = tail = nullptr;
}

void HistoryList::add(Patient p) {
    HistoryNode* node = new HistoryNode(p);
    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void HistoryList::display() {
    HistoryNode* cur = head;
    while (cur) {
        std::cout << cur->data.name 
                  << " (sev=" << cur->data.severity << ")\n";
        cur = cur->next;
    }
}

/// hello Olloyor, i am GPT
