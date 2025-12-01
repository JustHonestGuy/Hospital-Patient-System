#include <iostream>
#include "history.h"

int main() {

    PatientHistory h;

    h.addRecord(1, "Ali", 9);
    h.addRecord(2, "Mira", 7);

    h.displayHistory();
    return 0;
}
