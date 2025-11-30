#ifndef PATIENT_H
#define PATIENT_H

#include <string>

struct Patient {
    int id;
    std::string name;
    int severity;
    long long arrivalTime;

    Patient(int id, std::string name, int severity, long long arrivalTime) {
        this->id = id;
        this->name = name;
        this->severity = severity;
        this->arrivalTime = arrivalTime;
    }

    Patient() {}
};

#endif
