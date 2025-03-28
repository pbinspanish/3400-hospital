DROP TABLE IF EXISTS nurses_treating;
DROP TABLE IF EXISTS nurses;
DROP TABLE IF EXISTS doctors_treating;
DROP TABLE IF EXISTS patients;
DROP TABLE IF EXISTS doctors;
DROP TABLE IF EXISTS pharmacies;
DROP TABLE IF EXISTS hospital;

CREATE TABLE hospital (
    id INTEGER PRIMARY KEY,
    location VARCHAR
);

CREATE TABLE pharmacies (
    id INTEGER PRIMARY KEY,
    name VARCHAR
);

CREATE TABLE doctors (
    id INTEGER PRIMARY KEY,
    working_at INTEGER NOT NULL,
    FOREIGN KEY (working_at) REFERENCES hospital(id)
);

CREATE TABLE patients (
    id INTEGER PRIMARY KEY,
    first_name VARCHAR,
    last_name VARCHAR,
    phone_number VARCHAR,
    disease VARCHAR,
    treatment VARCHAR,
    admission_date DATE NOT NULL,
    discharge_date DATE,
    admitted_to INTEGER NOT NULL,
    primary_doctor INTEGER NOT NULL,
    FOREIGN KEY (admitted_to) REFERENCES hospital(id),
    FOREIGN KEY (primary_doctor) REFERENCES doctors(id)
);

CREATE TABLE doctors_treating (
    doctor_id INTEGER NOT NULL,
    patient_id INTEGER NOT NULL,
    FOREIGN KEY (doctor_id) REFERENCES doctors(id),
    FOREIGN KEY (patient_id) REFERENCES patients(id),
    PRIMARY KEY (doctor_id, patient_id)
);

CREATE TABLE nurses (
    id INTEGER PRIMARY KEY,
    working_at INTEGER NOT NULL,
    FOREIGN KEY (working_at) REFERENCES hospital(id)
);

CREATE TABLE nurses_treating (
    nurse_id INTEGER NOT NULL,
    patient_id INTEGER NOT NULL,
    FOREIGN KEY (nurse_id) REFERENCES nurses(id),
    FOREIGN KEY (patient_id) REFERENCES patients(id),
    PRIMARY KEY (nurse_id, patient_id)
);