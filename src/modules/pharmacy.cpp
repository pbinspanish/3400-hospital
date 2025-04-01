#include "pharmacy.h"
#include <iostream>


Pharmacy::Pharmacy(const string& pharmacy_name) : pharmacy_name(pharmacy_name) {}

void Pharmacy::shipDrugs(Database& db) {
    std::string sql = "INSERT INTO shipments (pharmacyName, shipmentDate) VALUES ('" + pharmacy_name + "', datetime('now'));";
    db.executeSQL(sql);
    std::cout << "Pharmacy " << pharmacy_name << " is shipping drugs..." << std::endl;
}

void Pharmacy::billHospital(Database& db, double amount) {
    std::string sql = "INSERT INTO billing (pharmacyName, billAmount, billingDate) VALUES ('" + pharmacy_name + "', " + std::to_string(amount) + ", datetime('now'));";
    db.executeSQL(sql);
    std::cout << "Billing hospital for drugs from " << pharmacy_name << " ($" << amount << ")" << std::endl;
}


