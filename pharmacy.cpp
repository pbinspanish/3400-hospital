#include "pharmacy.h"
#include <iostream>

using namespace std;

Pharmacy::Pharmacy(const string& name) : name(name) {}

void Pharmacy::shipDrugs() {
    // added by F: to add to sql database
    // string sql = "INSERT INTO shipments (pharmacyName, shipmentDate) VALUES ('" + name + "', datetime('now'));";
    // db.executeSQL(sql);
    cout << "Pharmacy " << name << " is shipping drugs..." << endl;
}

void Pharmacy::billHospital() {
    // added by F: to add to sql database
    // string sql = "INSERT INTO billing (pharmacyName, billAmount, billingDate) VALUES ('" + name + "', " + to_string(amount) + ", datetime('now'));";
    // db.executeSQL(sql);
    cout << "Billing hospital for drugs from " << name << "..." << endl;
}
