#include "patient.h"

    Patient(int id, string& fn, string& ln, string& phone, string& disease, string& treatment) : P_id(id), P_fname(fn), P_Lname(ln), P_phoneNumber(phone), P_disease(disease), P_treatment(treatment) {}

    void save(Database& db) const {
        string sql = "INSERT INTO patients (P_id, P_fname, P_lname, P_phoneNumber, P_disease, P_treatment) VALUES ('" + to_string(P_id) + "', '" + P_fname + "', '" + P_lname + "', '" + P_phoneNumber + "', '" + P_disease + "', '" + P_treatment + "');";
        db.executeSQL(sql);
    }

    void getPatient(Database& db, int id) {
        string sql = "SELECT * FROM patients WHERE P_id = " + to_string(id) + ";";
        db.executeSQL(sql);
    }
