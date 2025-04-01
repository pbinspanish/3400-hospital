#ifndef PHARMACY_H
#define PHARMACY_H

#include <string>
#include "hospital.h"
#include "database.h"

class Pharmacy
{
public:
    std::string pharmacy_name; // unique identification for the pharmacies

    Pharmacy(const std::string &pharmacy_name);

    void shipDrugs(Database& db);
    void billHospital(Database& db, double amount);
};

#endif

