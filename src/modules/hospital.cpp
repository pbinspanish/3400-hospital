// hospital.cpp
#include "../include/hospital.h"
#include <iostream>
#include <sstream>

Hospital::Hospital(int id, const std::string& location) : id(id), location(location) {}

void Hospital::readFromDatabase(SQLite::Database& db) {
    SQLite::Statement query(db, "SELECT location FROM hospital WHERE id = ?");
    query.bind(1, id);

    if (query.executeStep()) {
        location = query.getColumn(0).getString();
    } else {
        std::cerr << "Hospital with ID " << id << " not found." << std::endl;
    }
}

void Hospital::writeToDatabase(SQLite::Database& db) {
    if (id == 0) {
        // Insert new hospital
        SQLite::Statement insertQuery(db, "INSERT INTO hospital (location) VALUES (?)");
        insertQuery.bind(1, location);
        insertQuery.exec();
        id = db.getLastInsertRowid(); // Retrieve the auto-generated ID
    } else {
        // Update existing hospital
        SQLite::Statement updateQuery(db, "UPDATE hospital SET location = ? WHERE id = ?");
        updateQuery.bind(1, location);
        updateQuery.bind(2, id);
        updateQuery.exec();
    }
}

std::vector<Hospital> Hospital::getAllHospitals(SQLite::Database& db) {
    std::vector<Hospital> hospitals;
    SQLite::Statement query(db, "SELECT id, location FROM hospital");

    while (query.executeStep()) {
        int id = query.getColumn(0).getInt();
        std::string location = query.getColumn(1).getString();
        hospitals.emplace_back(id, location);
    }
    return hospitals;
}

Hospital Hospital::getHospitalById(SQLite::Database& db, int hospitalId) {
    Hospital hospital;
    SQLite::Statement query(db, "SELECT id, location FROM hospital WHERE id = ?");
    query.bind(1, hospitalId);

    if (query.executeStep()) {
        hospital.id = query.getColumn(0).getInt();
        hospital.location = query.getColumn(1).getString();
    }
    return hospital;
}

bool Hospital::locationExists(SQLite::Database& db, const std::string& location){
    SQLite::Statement query(db,"SELECT COUNT(*) FROM hospital WHERE location = ?");
    query.bind(1,location);
    if(query.executeStep()){
        return query.getColumn(0).getInt() > 0;
    }
    return false;
}