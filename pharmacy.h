#ifndef PHARMACY_H
#define PHARMACY_H

#include <string>
#include "hospital.h"
#include "database.h"

class Pharmacy{
    public:
    std::string name; //unique identification for the pharmacies
    //could add extra features like address, pharmacists

    Pharmacy(const std::string& name);

    void billHospital();
    void shipDrugs();
    
};

#endif
