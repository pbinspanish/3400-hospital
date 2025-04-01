#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <ctime>
#include <vector>
#include "database.h"

class Patient {
private:
    int P_id;
    std::string P_fname;
    std::string P_lname;
    std::string P_phoneNumber;
    std::string P_disease;
    std::string P_treatment;
    time_t P_admissionDate;
    time_t P_dischargeDate;

public:
    Patient() : P_id(0), P_fname(""), P_lname(""), P_phoneNumber(""), P_disease(""), P_treatment("") {}

    Patient(int id, const std::string &first_name, const std::string &last_name,
            const std::string &phone, const std::string &disease, const std::string &treatment);
            
    int hospital_id;
    void save(Database& db) const;
    static Patient getPatient(Database& db, int id);
    int getId() const { return P_id; }
    std::string getFullName() const { return P_fname + " " + P_lname; }
    std::string getFirstName() const { return P_fname; }
    std::string getLastName() const { return P_lname; }
    std::string getPhone() const { return P_phoneNumber; }
    std::string getDisease() const { return P_disease; }
    std::string getTreatment() const { return P_treatment; }
    time_t getAdmission() const { return P_admissionDate; }
    time_t getDischarge() const { return P_dischargeDate; }

};

#endif
