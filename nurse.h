#ifndef NURSE_H
#define NURSE_H

#include <string>
#include "patient.h"

class Nurse {
public:
    Nurse(const std::string& name);
    bool assignPatient(Patient* patient); // Change to accept Patient*
    void listPatients() const;
    std::string getName() const;

private:
    std::string name;
    int patientCount;
    Patient* assignedPatients[2];
};

#endif // NURSE_H