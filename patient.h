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
    Patient(int id, string& fn, string& ln, string& phone, string& disease, string& treatment);
    
    void save(Database& db) const;

    static Patient getPatient(Database& db, int id);

    int getId() const { return P_id; }

    //Added by H:
    //string getFullName() const { return P_fname + " " + P_lname; }
    //string getDisease() const { return P_disease; }

};
