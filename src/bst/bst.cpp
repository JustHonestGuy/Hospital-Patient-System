#include "bst.h"
#include <iostream>

BST::BST() {
    root = nullptr;
}

Node* BST::insertNode(Node* node, Patient p) {
    if (!node) return new Node(p);

    if (p.severity > node->data.severity ||
       (p.severity == node->data.severity && p.arrivalTime < node->data.arrivalTime))
        node->right = insertNode(node->right, p);
    else
        node->left = insertNode(node->left, p);

    return node;
}

void BST::insert(Patient p) {
    root = insertNode(root, p);
}

Node* BST::removeMaxNode(Node* node, Patient &result) {
    if (!node) return nullptr;
    if (node->right == nullptr) {
        result = node->data;
        return node->left;
    }
    node->right = removeMaxNode(node->right, result);
    return node;
}

bool BST::removeMax(Patient &p) {
    if (!root) return false;
    root = removeMaxNode(root, p);
    return true;
}

void BST::reverseInorder(Node* node) {
    if (!node) return;
    reverseInorder(node->right);
    std::cout << node->data.name << " (sev=" << node->data.severity << ")\n";
    reverseInorder(node->left);
}

void BST::display() {
    reverseInorder(root);
}

