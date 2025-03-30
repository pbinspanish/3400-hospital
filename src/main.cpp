#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <fstream>
#include <string>
#include <vector>

#include <SQLiteCpp/SQLiteCpp.h>

#include "database.h"
#include "hospital.h"

int main ()
{
    Database db;
    db.createDatabase();

    // list of 5 hospitals
    std::vector<Hospital> hospitals = {
        Hospital(1, "Windsor"),
        Hospital(2, "Essex"),
        Hospital(3, "Tecumseh"),
        Hospital(4, "LaSalle"),
        Hospital(5, "Amherstburg")
    };

    // list of 20 pharmacies
    // std::vector<Pharmacy> pharmacies = {
    //     Pharmacy("Pharmacy A"),
    //     Pharmacy("Pharmacy B"),
    //     Pharmacy("Pharmacy C"),
    //     Pharmacy("Pharmacy D"),
    //     Pharmacy("Pharmacy E"),
    //     Pharmacy("Pharmacy F"),
    //     Pharmacy("Pharmacy G"),
    //     Pharmacy("Pharmacy H"),
    //     Pharmacy("Pharmacy I"),
    //     Pharmacy("Pharmacy J"),
    //     Pharmacy("Pharmacy K"),
    //     Pharmacy("Pharmacy L"),
    //     Pharmacy("Pharmacy M"),
    //     Pharmacy("Pharmacy N"),
    //     Pharmacy("Pharmacy O"),
    //     Pharmacy("Pharmacy P"),
    //     Pharmacy("Pharmacy Q"),
    //     Pharmacy("Pharmacy R"),
    //     Pharmacy("Pharmacy S"),
    //     Pharmacy("Pharmacy T")
    // };
    


    // create a patient and add it
    Patient patient(1, "John", "Doe", "1234567890", "Flu", "Rest and hydration");
    // test
    hospitals[0].addPatient(patient);

    hospitals[0].relocatePatient(patient, hospitals[1]);

    // print out the names of all patients in hospital 1
    std::cout << "Patients in hospital 1:" << std::endl;
    for (const auto& p : hospitals[0].patients) {
        std::cout << p.getFullName() << std::endl;
    }
    // print out the names of all patients in hospital 2
    std::cout << "Patients in hospital 2:" << std::endl;
    for (const auto& p : hospitals[1].patients) {
        std::cout << p.getId() << std::endl;
    }

    Patient test = hospitals[1].getPatient(1);
    std::cout << "Patient ID: " << test.getId() << std::endl;


    remove("hms.db3");
}