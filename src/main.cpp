#include <iostream>
#include "patient.h"
#include "bst/bst.h"
#include "queue/queue.h"
#include "history/history.h"

using namespace std;

long long currentTime = 0;

int main() {
    BST tree;
    CircularQueue queue(100);
    HistoryList history;

    int choice;

    while (true) {
        cout << "\n===== Hospital Management System =====\n";
        cout << "1. Register Patient\n";
        cout << "2. Send Next Patient\n";
        cout << "3. Show BST (severity)\n";
        cout << "4. Show Queue\n";
        cout << "5. Show History\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, severity;
            string name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter severity: ";
            cin >> severity;

            Patient p(id, name, severity, currentTime++);
            tree.insert(p);
            queue.enqueue(p);

        } else if (choice == 2) {
            Patient p;
            if (tree.removeMax(p)) {
                cout << "Sending patient: " << p.name << endl;
                history.add(p);
            } else {
                cout << "No patients in BST.\n";
            }
        } else if (choice == 3) {
            tree.display();
        } else if (choice == 4) {
            queue.display();
        } else if (choice == 5) {
            history.display();
        } else if (choice == 0) {
            break;
        }
    }

    return 0;
}

