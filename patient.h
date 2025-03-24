#include <string>
#include <ctime>
#include <vector>
#include "database.h"

using namespace std;

class Patient { 
    private: 
        int P_id;
        string P_fname;
        string P_lname;
        string P_phoneNumber;
        string P_disease;
        string P_treatment;
        time_t P_admissionDate;
        time_t P_dischargeDate;

public:
    Patient(int id, const string& fn, const string& ln, const string& phone, const string& disease, const string& treatment);
    
    void save(Database& db) const;

    static Patient getPatient(Database& db, int id);

    int getId() const { return P_id; }
    string getFullName() const { return P_fname + " " + P_lname; }
    string getPhone() const { return P_phoneNumber; }
    string getDisease() const { return P_disease; }
    string getTreatment() const { return P_treatment; }
    time_t getAdmission() const { return P_admissionDate; }
    time_t getDischarge() const { return P_dischargeDate; }
};
