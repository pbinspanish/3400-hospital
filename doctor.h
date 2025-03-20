#include <string>
#include <ctime>
#include "database.h"
#include "patient.h"

using namespace std;

class Doctor { 
    private: 
        int D_id;
        string D_name;

public:
    Doctor(int id, string& name) : D_id(id), D_name(name) {}

    void save(Database& db) const;

    void Doctor::requestOrder(Database& db, const string& prescription);
    
    void primary(Database& db, Patient& patient) const;

    void Doctor::attend(Database& db, Patient& patient);    

    void discharge(Database& db, Patient& patient) const;

    void doctorMenu(Database& db, Doctor& doctor);
}
