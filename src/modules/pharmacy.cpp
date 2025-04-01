#include "pharmacy.h"
#include <iostream>


Pharmacy::Pharmacy(const int id, const string& pharmacy_name) : id(id), pharmacy_name(pharmacy_name) {}

void Pharmacy::shipDrugs(Database& db, int hospital_id) {
    std::string sql = "INSERT INTO shipments (pharmacy_id, hospital_id, date) VALUES (" + std::to_string(id) + ", " + std::to_string(hospital_id) + ", datetime('now'));";
    db.executeSQL(sql);
    std::cout << "Pharmacy " << pharmacy_name << " is shipping drugs..." << std::endl;
}

void Pharmacy::billHospital(Database& db, double amount, int hospital_id) {
    std::string sql = "INSERT INTO billing (hospital_id, amount, date) VALUES (" + std::to_string(hospital_id) + ", " + std::to_string(amount) + ", datetime('now'));";
    db.executeSQL(sql);
    std::cout << "Billing hospital for drugs from " << pharmacy_name << " ($" << amount << ")" << std::endl;
}