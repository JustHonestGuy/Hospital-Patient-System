#ifndef BST_H
#define BST_H

#include "../patient.h"

struct Node {
    Patient data;
    Node* left;
    Node* right;

    Node(Patient p) {
        data = p;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* node, Patient p);
    Node* removeMaxNode(Node* node, Patient &result);
    void reverseInorder(Node* node);

public:
    BST();
    void insert(Patient p);
    bool removeMax(Patient &p);
    void display();
};

#endif

