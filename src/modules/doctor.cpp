#include "doctor.h"
#include <iostream>

Doctor::Doctor(int id, const string &name) : D_id(id), D_name(name) {}

void Doctor::save(Database &db) const
{
    string sql = "INSERT INTO doctors (D_id, D_name) VALUES ('" + to_string(D_id) + "', '" + D_name + "');";
    db.executeSQL(sql);
}

void Doctor::requestOrder(Database &db, const string &prescription)
{
    string sql = "INSERT INTO drugs (name, pharmacyID) VALUES ('" + prescription + "', 1);";
    db.executeSQL(sql);
}

void Doctor::primary(Database &db, Patient &patient) const
{
    string sql = "UPDATE patients SET primary_doc = " + to_string(D_id) + " WHERE P_id = " + std::to_string(patient.getId()) + ";";
    db.executeSQL(sql);
}

void Doctor::attend(Database &db, Patient &patient)
{
    string sql = "INSERT INTO doctor_patient (doctorID, patientID) VALUES (" + to_string(D_id) + ", " + std::to_string(patient.getId()) + ");";
    db.executeSQL(sql);
}

void Doctor::discharge(Database &db, Patient &patient) const
{
    string sql = "UPDATE patients SET dischargeDate = datetime('now') WHERE P_id = " + std::to_string(patient.getId()) + ";";
    db.executeSQL(sql);
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
