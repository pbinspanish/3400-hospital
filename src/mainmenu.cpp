#include <iostream>
#include <string>
#include <SQLiteCpp/SQLiteCpp.h>
#include <algorithm>

#include "database.h"
#include "hospital.h"
#include "patient.h"
#include "doctor.h"
#include "nurse.h"
#include "pharmacy.h"

Database db;
void showAllPatients();
void showAllDoctors();
void showAllNurses();


int getIntInput(const std::string& prompt) {
    int input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "❌ Invalid input. Please enter a number.\n";
        } else {
            std::cin.ignore(10000, '\n');
            return input;
        }
    }
}

void doctorMenu();
void nurseMenu();
void pharmacyMenu();
void adminMenu();
void patientMenu();

int main() {
    db.createDatabase();
    db.insertTestData();

    int choice;
    do {
        std::cout << "\n🏥 Hospital Management System\n";
        std::cout << "1. Doctor\n";
        std::cout << "2. Nurse\n";
        std::cout << "3. Patient\n";
        std::cout << "4. Administrator\n";
        std::cout << "5. Pharmacy\n";
        std::cout << "6. Exit\n";

        choice = getIntInput("Enter your role: ");

        switch (choice) {
            case 1: doctorMenu(); break;
            case 2: nurseMenu(); break;
            case 3: patientMenu(); break;
            case 4: adminMenu(); break;
            case 5: pharmacyMenu(); break;
            case 6: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
void doctorMenu() {
    int doctorId;
    while (true) {
        doctorId = getIntInput("Enter doctor ID (1–50): ");
        
        std::string sql = "SELECT id FROM doctors WHERE id = " + std::to_string(doctorId) + ";";
        auto result = db.executeQuery(sql);  // run the query right here
    
        if (!result.empty()) {
            break; // ID found in database
        } else {
            std::cout << "✖️ Doctor ID not found. Please try again.\n";
        }
    }
    Doctor doctor(doctorId, "");
    
    int choice;
    do {
        std::cout << "\n👨‍⚕️ Doctor Menu:\n";
        std::cout << "1. Attend a patient\n";
        std::cout << "2. Discharge a patient\n";
        std::cout << "3. Become primary doctor\n";
        std::cout << "4. Request drug delivery\n";
        std::cout << "5. Back\n";

        choice = getIntInput("Enter your choice: ");

        switch (choice) {
            case 1: {
                int id = getIntInput("Enter patient ID to attend: ");
                try {
                    Patient p = Patient::getPatient(db, id);
                    doctor.attend(db, p);
                } catch (...) {
                    std::cout << "❌ Patient not found.\n";
                }
                break;
            }
            case 2: {
                int id = getIntInput("Enter patient ID to discharge: ");
                try {
                    Patient p = Patient::getPatient(db, id);
                    doctor.discharge(db, p);
                } catch (...) {
                    std::cout << "❌ Patient not found.\n";
                }
                break;
            }
            case 3: {
                int id = getIntInput("Enter patient ID to assign as primary: ");
                try {
                    Patient p = Patient::getPatient(db, id);
                    doctor.primary(db, p);
                } catch (...) {
                    std::cout << "❌ Patient not found.\n";
                }
                break;
            }
            case 4: {
                std::cin.ignore();
                std::string prescription;
                std::cout << "Enter prescription: ";
                std::getline(std::cin, prescription);
                doctor.requestOrder(db, prescription);
                break;
            }
            case 5:
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}
void nurseMenu() {
    std::string nurseName;
    std::cout << "Enter nurse name: ";
    std::cin.ignore();
    std::getline(std::cin, nurseName);
    Nurse nurse(nurseName);
    int choice;
    do {
        std::cout << "\n🧑‍⚕️ Nurse Menu:\n";
        std::cout << "1. Assign patient\n";
        std::cout << "2. View assigned patients\n";
        std::cout << "3. Back\n";

        choice = getIntInput("Enter your choice: ");

        switch (choice) {
            case 1: {
                int id = getIntInput("Enter patient ID to assign: ");
                try {
                    Patient* patient = new Patient(Patient::getPatient(db, id));
                    nurse.assignPatient(patient);
                } catch (...) {
                    std::cout << "❌ Patient not found.\n";
                }
                break;
            }
            case 2:
                nurse.listPatients();
                break;
            case 3:
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 3);
}
void pharmacyMenu() {
    std::string pharmacyName;
    std::cout << "Enter pharmacy name: ";
    std::cin.ignore();
    std::getline(std::cin, pharmacyName);
    Pharmacy ph(pharmacyName);
    int choice;
    do {
        std::cout << "\n💊 Pharmacy Menu:\n";
        std::cout << "1. Ship drugs\n";
        std::cout << "2. Bill hospital\n";
        std::cout << "3. View Orders\n";
        std::cout << "4. Back\n";

        choice = getIntInput("Enter your choice: ");

        switch (choice) {
            case 1:
                ph.shipDrugs(db);
                break;
            case 2: {
                double amount;
                std::cout << "Enter bill amount: ";
                std::cin >> amount;
                ph.billHospital(db, amount);
                break;
            }
            case 3: {
                std::string sql = "SELECT id, hospital_id, drug_name FROM prescription_requests WHERE pharmacy_name = '" + pharmacyName + "' AND status = 'pending';";
                auto results = db.executeQuery(sql);
            
                if (results.empty()) {
                    std::cout << "No pending prescriptions.\n";
                    break;
                }
            
                std::cout << "\n🧾 Pending Prescriptions:\n";
                for (const auto& row : results) {
                    std::cout << "Request ID: " << row[0]
                              << " | Hospital ID: " << row[1]
                              << " | Drug: " << row[2] << "\n";
                }
            
                int requestId = getIntInput("Enter request ID to mark as shipped: ");
            
                std::string updateSql = "UPDATE prescription_requests SET status = 'shipped' WHERE id = " + std::to_string(requestId) + ";";
                db.executeSQL(updateSql);
                std::cout << "✅ Prescription shipped!\n";
                break;
            }
            
            case 4: break;
            default: std::cout << "Invalid option.\n";
        }
    } while (choice != 4);
}
void adminMenu() {
    int choice;
    do {
        std::cout << "\n🧑‍💼 Admin Menu:\n";
        std::cout << "1. Add Doctor\n";
        std::cout << "2. Add Nurse\n";
        std::cout << "3. Add Patient\n";
        std::cout << "4. View All Patients\n";
        std::cout << "5. View All Doctors\n";
        std::cout << "6. View All Nurses\n";
        std::cout << "7. Request Prescription\n";
        std::cout << "8. Back\n";

        choice = getIntInput("Enter your choice: ");

        if (choice == 1) {
            std::cin.ignore();
            std::string doctorName;
            std::cout << "Enter doctor name: ";
            std::getline(std::cin, doctorName);
            int doctorId = getIntInput("Enter doctor ID: ");
            Doctor d(doctorId, doctorName);
            d.save(db);
            std::cout << "Doctor saved.\n";
        } else if (choice == 2) {
            std::cin.ignore();
            std::string nurseName;
            std::cout << "Enter nurse name: ";
            std::getline(std::cin, nurseName);
            Nurse n(nurseName);
            std::cout << "Nurse added (in-memory).\n";
        } else if (choice == 3) {
            std::cin.ignore();
            std::string firstName, lastName, phoneNumber, disease, treatment;

            std::cout << "Enter patient's first name: ";
            std::getline(std::cin, firstName);

            std::cout << "Enter patient's last name: ";
            std::getline(std::cin, lastName);

            std::cout << "Enter patient's phone number (10 digits): ";
            std::getline(std::cin, phoneNumber);
            

            std::cout << "Enter patient's disease: ";
            std::getline(std::cin, disease);

            std::cout << "Enter patient's treatment: ";
            std::getline(std::cin, treatment);

            int patientId = getIntInput("Enter patient ID: ");
            Patient p(patientId, firstName, lastName, phoneNumber, disease, treatment);

            p.save(db);
            std::cout << "Patient saved to database.\n";
        } else if (choice == 4) {
            showAllPatients();
        } else if (choice == 5) {
            showAllDoctors();
        } else if (choice == 6) {
            showAllNurses();
        } else if (choice == 7) {
            int hospitalId = getIntInput("Enter hospital ID requesting prescription: ");
            std::string pharmacyName, drugName;
        
            std::cin.ignore();
            std::cout << "Enter pharmacy name: ";
            std::getline(std::cin, pharmacyName);
        
            std::cout << "Enter drug name: ";
            std::getline(std::cin, drugName);
        
            std::string sql = "INSERT INTO prescription_requests (hospital_id, pharmacy_name, drug_name) VALUES (" +
                              std::to_string(hospitalId) + ", '" + pharmacyName + "', '" + drugName + "');";
        
            db.executeSQL(sql);
            std::cout << "Prescription request sent to " << pharmacyName << " for '" << drugName << "'.\n";
        } else if (choice == 8) {
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 8);
}
void patientMenu() {
    // if (db.getPatientCount() == 0) {
    //     std::cout << "❌ No patients found in the database. Please create some patients first.\n";
    //     return;
    // }

    int id = getIntInput("Enter patient ID to look up: ");

    try {
        Patient p = Patient::getPatient(db, id);
        std::cout << "Patient: " << p.getFullName()
                  << " | Disease: " << p.getDisease()
                  << " | Treatment: " << p.getTreatment()
                  << "\n";
    } catch (...) {
        std::cout << "❌ Patient not found.\n";
    }
}


void showAllPatients() {
    std::string sql = "SELECT id, first_name, last_name, phone_number, disease, treatment FROM patients;";
    auto results = db.executeQuery(sql);

    std::cout << "\n🧑‍🦽 All Patients:\n";
    for (const auto& row : results) {
        std::cout << "ID: " << row[0]
                  << " | Name: " << row[1] << " " << row[2]
                  << " | Phone: " << row[3]
                  << " | Disease: " << row[4]
                  << " | Treatment: " << row[5] << "\n";
    }
}

void showAllDoctors() {
    std::string sql = "SELECT id FROM doctors;";
    auto results = db.executeQuery(sql);

    std::cout << "\n👨‍⚕️ All Doctors:\n";
    for (const auto& row : results) {
        std::cout << "Doctor ID: " << row[0] << "\n";
    }
}

void showAllNurses() {
    std::string sql = "SELECT id FROM nurses;";
    auto results = db.executeQuery(sql);

    std::cout << "\n🧑‍⚕️ All Nurses:\n";
    for (const auto& row : results) {
        std::cout << "Nurse ID: " << row[0] << "\n";
    }
}
