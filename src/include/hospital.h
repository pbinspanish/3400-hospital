// hospital.h
#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include <vector>
#include <SQLiteCpp/SQLiteCpp.h>

class Hospital {
public:
    int id;
    std::string location;

    Hospital(int id = 0, const std::string& location = "");

    void readFromDatabase(SQLite::Database& db);
    void writeToDatabase(SQLite::Database& db);

    static std::vector<Hospital> getAllHospitals(SQLite::Database& db);
    static Hospital getHospitalById(SQLite::Database& db, int hospitalId);

    static bool locationExists(SQLite::Database& db, const std::string& location);

};

#endif // HOSPITAL_H