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
    Doctor(int id, const string& name);

    void save(Database& db) const;

    void requestOrder(Database& db, const string& prescription);
    
    void primary(Database& db, Patient& patient) const;

    void attend(Database& db, Patient& patient);

    void discharge(Database& db, Patient& patient) const;

    void doctorMenu(Database& db);
};
