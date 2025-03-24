#include "pharmacy.h"
#include <iostream>

using namespace std;

Pharmacy::Pharmacy(const string& name) : name(name) {}

void Pharmacy::shipDrugs() {
    cout << "Pharmacy " << name << " is shipping drugs..." << endl;
}

void Pharmacy::billHospital() {
    cout << "Billing hospital for drugs from " << name << "..." << endl;
}