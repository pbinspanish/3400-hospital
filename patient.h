#include <string>
#include <ctime>
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
    Patient(int id, string& fn, string& ln, string& phone, string& disease, string& treatment) : P_id(id), P_fname(fn), P_lname(ln), P_phoneNumber(phone), P_disease(disease), P_treatment(treatment) {}

    void save(Database& db) const;

    void getPatient(Database& db, int id);
}
