#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <fstream>
#include <string>
#include <vector>

#include <SQLiteCpp/SQLiteCpp.h>

#include "database.h"
#include "hospital.h"
#include "hospital_manager.h"

int main ()
{
    Database db;
    db.createDatabase();

    HospitalManager manager;

    // add 5 hospitals
    manager.addNewHospital(1, "Windsor");
    manager.addNewHospital(2, "Essex");
    manager.addNewHospital(3, "Tecumseh");
    manager.addNewHospital(4, "LaSalle");
    manager.addNewHospital(5, "Amherstburg");

    // list of 20 pharmacies
    manager.addNewPharmacy(1, "Pharmacy A");
    manager.addNewPharmacy(2, "Pharmacy B");
    manager.addNewPharmacy(3, "Pharmacy C");
    manager.addNewPharmacy(4, "Pharmacy D");
    manager.addNewPharmacy(5, "Pharmacy E");
    manager.addNewPharmacy(6, "Pharmacy F");
    manager.addNewPharmacy(7, "Pharmacy G");
    manager.addNewPharmacy(8, "Pharmacy H");
    manager.addNewPharmacy(9, "Pharmacy I");
    manager.addNewPharmacy(10, "Pharmacy J");
    manager.addNewPharmacy(11, "Pharmacy K");
    manager.addNewPharmacy(12, "Pharmacy L");
    manager.addNewPharmacy(13, "Pharmacy M");
    manager.addNewPharmacy(14, "Pharmacy N");
    manager.addNewPharmacy(15, "Pharmacy O");
    manager.addNewPharmacy(16, "Pharmacy P");
    manager.addNewPharmacy(17, "Pharmacy Q");
    manager.addNewPharmacy(18, "Pharmacy R");
    manager.addNewPharmacy(19, "Pharmacy S");
    manager.addNewPharmacy(20, "Pharmacy T");
    

    int input;

    do
    {
        std::cout << "\nWelcome to the Hospital Management System! \n";
        std::cout << "1. Manage Hospitals\n";
        std::cout << "2. Manage Patients\n";
        std::cout << "3. Manage Doctors\n";
        std::cout << "4. Manage Nurses\n";
        std::cout << "5. Manage Pharmacies\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter: ";
        std::cin >> input;

        switch (input)
        {
            case 1:
                manager.hospitalManagementMenu();
                break;
            case 2:
                // manage patients
                break;
            case 3:
                // manage doctors
                break;
            case 4:
                // manage nurses
                break;
            case 5:
                // manage pharmacies
                break;
            case 6:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid input" << std::endl;
                break;
        }
    } while (input != 6);
}