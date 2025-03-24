#include "nurse.h"
#include <iostream>

Nurse::Nurse(const std::string& name) : name(name), patientCount(0) {
    assignedPatients[0] = nullptr;
    assignedPatients[1] = nullptr;
}

bool Nurse::assignPatient(Patient* patient) { // Change to accept Patient*
    if (patientCount < 2) {
        assignedPatients[patientCount] = patient;
        patientCount++;
        std::cout << "Assigned patient " << patient->getFullName() << " to Nurse " << name << ".\n";
        return true;
    } else {
        std::cout << "Nurse " << name << " already has 2 patients assigned.\n";
        return false;
    }
}

void Nurse::listPatients() const {
    std::cout << "Nurse " << name << " is caring for:\n";
    if (patientCount == 0) {
        std::cout << "No patients currently assigned.\n";
        return;
    }

    for (int i = 0; i < patientCount; ++i) {
        if (assignedPatients[i]) {
            std::cout << "- " << assignedPatients[i]->getFullName()
                      << " (Disease: " << assignedPatients[i]->getDisease() << ")\n";
        }
    }
}

std::string Nurse::getName() const {
    return name;
}
