#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include <vector>
#include <SQLiteCpp/SQLiteCpp.h>

#include "database.h"
#include "patient.h"
#include "doctor.h"
#include "nurse.h"

class Hospital
{
public:
    int id;
    std::string location;

    // list of 20 admitted patients
    std::vector<Patient> patients;

    // min 3
    std::vector<Doctor> doctors;
    
    // min 5
    std::vector<Nurse> nurses;

    // Constructor
    Hospital(int id = 0, const std::string& location = "");

    
    
    // Patient Management
    void addPatient(const Patient& patient);
    void removePatient(const Patient& patient);

    Patient getPatient(int id);

    void relocatePatient(Patient& patient, Hospital& new_hospital);



    // Doctor Management
    void addDoctor(const Doctor& doctor);
    void removeDoctor(const Doctor& doctor);

    Doctor getDoctor(int id);

    void relocatedDoctor(const Doctor& doctor, const Hospital& hospital);



    // Nurse Management
    void addNurse(const Nurse& nurse);
    void removeNurse(const Nurse& nurse);

    Nurse getNurse(int id);

    void relocateNurse(const Nurse& nurse, const Hospital& hospital);
};

#endif // HOSPITAL_H