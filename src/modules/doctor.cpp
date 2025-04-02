#include "doctor.h"
#include <iostream>

Doctor::Doctor(int id, const std::string &name) : D_id(id), D_name(name) {}

void Doctor::save(Database &db, int hospital_id) const {
    std::string sql = "INSERT INTO doctors (id, name, working_at) VALUES (" +
                      std::to_string(D_id) + ", '" + D_name + "', " + std::to_string(hospital_id) + ");";
    db.executeSQL(sql);
}

void Doctor::requestOrder(Database& db, const std::string& prescription) {
    std::string sql = "INSERT INTO prescription_requests (hospital_id, pharmacy_name, drug_name) "
                      "VALUES (1, 'City Pharmacy', '" + prescription + "');";
    db.executeSQL(sql);
    std::cout << "✅ Prescription for '" << prescription << "' sent to City Pharmacy.\n";
}


void Doctor::primary(Database &db, Patient &patient) const {
    std::string sql = "UPDATE patients SET primary_doctor = " +
                      std::to_string(D_id) + " WHERE id = " +
                      std::to_string(patient.getId()) + ";";
    db.executeSQL(sql);
}

void Doctor::attend(Database &db, Patient &patient) {
    std::string checkSql = "SELECT * FROM doctors_treating WHERE doctor_id = " + std::to_string(D_id) +
                           " AND patient_id = " + std::to_string(patient.getId()) + ";";
    auto result = db.executeQuery(checkSql);

    if (!result.empty()) {
        std::cout << "⚠️ Doctor is already attending this patient.\n";
        return;
    }

    std::string sql = "INSERT INTO doctors_treating (doctor_id, patient_id) VALUES (" +
                      std::to_string(D_id) + ", " + std::to_string(patient.getId()) + ");";
    db.executeSQL(sql);
    std::cout << "✅ Doctor is now attending Patient " << patient.getId() << "\n";
}

void Doctor::discharge(Database &db, Patient &patient) const {
    std::string sql = "UPDATE patients SET discharge_date = datetime('now') WHERE id = " +
                      std::to_string(patient.getId()) + ";";
    db.executeSQL(sql);

    std::string deleteSql = "DELETE FROM doctors_treating WHERE patient_id = " +
                            std::to_string(patient.getId()) + ";";
    db.executeSQL(deleteSql);

    std::cout << "✅ Doctor has discharged Patient " << patient.getId() << "\n";
}

void Doctor::relocate(Database& db, int newHospitalId) {
    std::string sql = "UPDATE doctors SET working_at = " + std::to_string(newHospitalId) + " WHERE id = " + std::to_string(D_id) + ";";
    db.executeSQL(sql);

    std::string confirmSql = "SELECT working_at FROM doctors WHERE id = " + std::to_string(D_id) + ";";
    auto result = db.executeQuery(confirmSql);

    if (!result.empty()) {
        std::cout << "✅ Doctor " << getName() << " relocated to hospital ID " << result[0][0] << ".\n";
    } else {
        std::cout << "❌ Failed to confirm relocation.\n";
    }
}

void Doctor::doctorMenu(Database &db)
{
    int input;

    // do
    // {
    //     cout << "\n Welcome, Doctor! \n";
    //     cout << "1. Request Pharmacy Order\n";
    //     cout << "2. Become a Primary Doctor\n";
    //     cout << "3. Attend a Patient\n";
    //     cout << "4. Discharge a Patient\n";
    //     cout << "5. Exit\n";
    //     cout << "Enter: ";
    //     cin >> input;

    //     switch (input)
    //     {
    //     case 1:
    //     {
    //         string prescription;
    //         cout << "Enter prescription request: ";
    //         cin.ignore();
    //         getline(cin, prescription);
    //         doctor.requestOrder(db, prescription);
    //         break;
    //     }
    //     case 2:
    //     {
    //         int P_id;
    //         cout << "Enter the patient's ID to become their Primary Doctor: ";
    //         cin >> P_id;
    //         Patient patient = Patient::getPatient(db, P_id);
    //         primary(db, patient);
    //         break;
    //     }
    //     case 3:
    //     {
    //         int P_id;
    //         cout << "Enter the patient's ID to attend: ";
    //         cin >> P_id;
    //         Patient patient = Patient::getPatient(db, P_id);
    //         attend(db, patient);
    //         break;
    //     }
    //     case 4:
    //     {
    //         int P_id;
    //         cout << "Enter the patient's ID to discharge: ";
    //         cin >> P_id;
    //         Patient patient = Patient::getPatient(db, P_id);
    //         discharge(db, patient);
    //         break;
    //     }
    //     case 5:
    //         cout << "Exiting\n";
    //         break;
    //     default:
    //         cout << "Please try again.\n";
    //     }
    // } while (input != 5);
}
