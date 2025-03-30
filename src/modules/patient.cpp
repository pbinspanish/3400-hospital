#include "patient.h"
#include <iostream>
Patient::Patient(int id, const std::string &first_name, const std::string &last_name, const std::string &phone, const std::string &disease, const std::string &treatment) : P_id(id), P_fname(first_name), P_lname(last_name), P_phoneNumber(phone), P_disease(disease), P_treatment(treatment) {}



// void Patient::save(Database& db) const {
//     std::string sql = "INSERT INTO patients (P_id, P_fname, P_lname, P_phoneNumber, P_disease, P_treatment) VALUES ('" + to_std::string(P_id) + "', '" + P_fname + "', '" + P_lname + "', '" + P_phoneNumber + "', '" + P_disease + "', '" + P_treatment + "');";
//     db.executeSQL(sql);
// }

// Patient Patient::getPatient(Database& db, int id) {
//     while (true) {
//         std::string sql = "SELECT P_id, P_fname, P_lname, P_phoneNumber, P_disease, P_treatment FROM patients WHERE P_id = " + to_std::string(id) + ";";
//         vector<vector<std::string>> result = db.executeQuery(sql);

//         if (!result.empty()) {
//             int P_id = stoi(result[0][0]);
//             std::string P_fname = result[0][1];
//             std::string P_lname = result[0][2];
//             std::string P_phoneNumber = result[0][3];
//             std::string P_disease = result[0][4];
//             std::string P_treatment = result[0][5];

//             return Patient(P_id, P_fname, P_lname, P_phoneNumber, P_disease, P_treatment);
//         }
//         cout << "No patient found with ID: " << id << ". Please enter a valid patient ID: ";
//         cin >> id;
//     }
// }
