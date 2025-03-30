#include <iostream>
#include <sstream>

#include "hospital.h"

// Constructor
Hospital::Hospital(int id, const std::string& location) : id(id), location(location) {
    patients = std::vector<Patient>();

    // write to the database
    std::string sql = "INSERT INTO hospitals (id, location) VALUES (" + std::to_string(id) + ", '" + location + "');";
    Database::executeSQL(sql);
    std::cout << "Hospital " << location << " has been created with ID: " << id << std::endl;
}



// Patient Management
void Hospital::addPatient(const Patient& patient) {
    patients.push_back(patient);
}
void Hospital::removePatient(const Patient& patient) {
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (it->getId() == patient.getId()) {
            patients.erase(it);
            break;
        }
    }
}

Patient Hospital::getPatient(int patient_id) {
    for (Patient patient : patients) {
        if (patient.getId() == patient_id) {
            return patient;
        }
    }

    throw std::runtime_error("Patient not found");
}

void Hospital::relocatePatient(Patient &patient, Hospital &new_hospital)
{
    // Add patient to the new hospital
    new_hospital.addPatient(patient); // TODO: make sure we don't overflow the hospital

    // Remove patient from the old hospital
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (it->getId() == patient.getId()) {
            patients.erase(it);
            break;
        }
    }

    // Update the patient's hospital ID
    patient.hospital_id = new_hospital.id;

    // Update the database
    std::string sql = "UPDATE patients SET admitted_to = " + std::to_string(new_hospital.id) + " WHERE id = " + std::to_string(patient.getId()) + ";";
    Database::executeSQL(sql);

    std::cout << "Patient " << patient.getFullName() << " has been relocated to " << new_hospital.location << std::endl;
    
}



// Doctor Management
void Hospital::addDoctor(const Doctor& doctor) {
    doctors.push_back(doctor);
}
void Hospital::removeDoctor(const Doctor& doctor) {
    for (auto it = doctors.begin(); it != doctors.end(); ++it) {
        if (it->getId() == doctor.getId()) {
            doctors.erase(it);
            break;
        }
    }
}

Doctor Hospital::getDoctor(int doctor_id) {
    for (Doctor doctor : doctors) {
        if (doctor.getId() == doctor_id) {
            return doctor;
        }
    }

    throw std::runtime_error("Doctor not found");
}

void Hospital::relocatedDoctor(const Doctor& doctor, const Hospital& hospital) {
    // Add doctor to the new hospital
    doctors.push_back(doctor); // TODO: make sure we don't overflow the hospital

    // Remove doctor from the old hospital
    for (auto it = doctors.begin(); it != doctors.end(); ++it) {
        if (it->getId() == doctor.getId()) {
            doctors.erase(it);
            break;
        }
    }

    // Update the database
    std::string sql = "UPDATE doctors SET working_at = " + std::to_string(hospital.id) + " WHERE id = " + std::to_string(doctor.getId()) + ";";
    Database::executeSQL(sql);

    std::cout << "Doctor " << doctor.getId() << " has been relocated to " << hospital.location << std::endl;
}



// Nurse Management
void Hospital::addNurse(const Nurse& nurse) {
    nurses.push_back(nurse);
}
void Hospital::removeNurse(const Nurse& nurse) {
    for (auto it = nurses.begin(); it != nurses.end(); ++it) {
        if (it->id == nurse.id) {
            nurses.erase(it);
            break;
        }
    }
}

Nurse Hospital::getNurse(int nurse_id) {
    for (Nurse nurse : nurses) {
        if (nurse.id == nurse_id) {
            return nurse;
        }
    }

    throw std::runtime_error("Nurse not found");
}

void Hospital::relocateNurse(const Nurse& nurse, const Hospital& hospital) {
    // Add nurse to the new hospital
    nurses.push_back(nurse); // TODO: make sure we don't overflow the hospital

    // Remove nurse from the old hospital
    for (auto it = nurses.begin(); it != nurses.end(); ++it) {
        if (it->id == nurse.id) {
            nurses.erase(it);
            break;
        }
    }

    // Update the database
    std::string sql = "UPDATE nurses SET working_at = " + std::to_string(hospital.id) + " WHERE id = " + std::to_string(nurse.id) + ";";
    Database::executeSQL(sql);

    std::cout << "Nurse " << nurse.getName() << " has been relocated to " << hospital.location << std::endl;
}