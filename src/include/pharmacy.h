#ifndef PHARMACY_H
#define PHARMACY_H

#include <string>
#include "hospital.h"
#include "database.h"

class Pharmacy
{
public:
    int id;
    std::string pharmacy_name; // unique identification for the pharmacies

    Pharmacy(const int id, const std::string &pharmacy_name);

    void shipDrugs(Database& db, int hospital_id);
    void billHospital(Database& db, double amount, int hospital_id);
};

#endif

