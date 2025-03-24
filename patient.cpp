#include "patient.h"
#include <iostream>
    //Patient::
    Patient(int id, string& fn, string& ln, string& phone, string& disease, string& treatment) 
        : P_id(id), P_fname(fn), P_Lname(ln), P_phoneNumber(phone), P_disease(disease), P_treatment(treatment) {}
                                 //P_lname(ln)?
    void Patient::save(Database& db) const {
        string sql = "INSERT INTO patients (P_id, P_fname, P_lname, P_phoneNumber, P_disease, P_treatment) VALUES ('" + to_string(P_id) + "', '" + P_fname + "', '" + P_lname + "', '" + P_phoneNumber + "', '" + P_disease + "', '" + P_treatment + "');";
        db.executeSQL(sql);
    }

    Patient Patient::getPatient(Database& db, int id) {
        while (true) {
            string sql = "SELECT P_id, P_fname, P_lname, P_phoneNumber, P_disease, P_treatment FROM patients WHERE P_id = " + to_string(id) + ";";
            vector<vector<string>> result = db.executeQuery(sql);
    
            if (!result.empty()) {
                int P_id = stoi(result[0][0]);
                string P_fname = result[0][1];
                string P_lname = result[0][2];
                string P_phoneNumber = result[0][3];
                string P_disease = result[0][4];
                string P_treatment = result[0][5];
    
                return Patient(P_id, P_fname, P_lname, P_phoneNumber, P_disease, P_treatment);
            }     
            cout << "No patient found with ID: " << id << ". Please enter a valid patient ID: ";
            cin >> id;
        }
    }
