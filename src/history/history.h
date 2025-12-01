#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class PatientHistory {
private:
    class Node {
    public:
        int id;
        string name;
        int severity;
        string timeServed;
        Node* next;

        Node(int _id, const string& _name, int _sev, const string& _time)
            : id(_id), name(_name), severity(_sev), timeServed(_time), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t count;

    string getCurrentTime() const {
        time_t now = time(0);
        char* dt = ctime(&now);
        string s(dt);
        if (!s.empty() && s.back() == '\n') s.pop_back();
        return s;
    }

public:
    PatientHistory() : head(nullptr), tail(nullptr), count(0) {}
    ~PatientHistory() { clear(); }

    void addRecord(int id, const string& name, int severity) {
        string timeStamp = getCurrentTime();
        Node* newNode = new Node(id, name, severity, timeStamp);

        if (!head) head = tail = newNode;
        else { tail->next = newNode; tail = newNode; }

        ++count;
    }

    void displayHistory() const {
        if (!head) { cout << "\n--- No patient history available ---\n"; return; }

        cout << "\n=========== PATIENT VISIT HISTORY ===========\n";
        Node* cur = head;
        while (cur) {
            cout << "ID: " << cur->id
                 << " | Name: " << cur->name
                 << " | Severity: " << cur->severity
                 << " | Served At: " << cur->timeServed << "\n";
            cur = cur->next;
        }
        cout << "=============================================\n";
    }

    void clear() {
        Node* cur = head;
        while (cur) { Node* nxt = cur->next; delete cur; cur = nxt; }
        head = tail = nullptr; count = 0;
    }

    size_t size() const { return count; }
    bool empty() const { return head == nullptr; }
};
