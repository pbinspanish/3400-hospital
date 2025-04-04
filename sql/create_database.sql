DROP TABLE IF EXISTS nurses_treating;
DROP TABLE IF EXISTS nurses;
DROP TABLE IF EXISTS doctors_treating;
DROP TABLE IF EXISTS patients;
DROP TABLE IF EXISTS doctors;
DROP TABLE IF EXISTS billing;
DROP TABLE IF EXISTS shipments;
DROP TABLE IF EXISTS pharmacies;
DROP TABLE IF EXISTS hospitals;

CREATE TABLE hospitals (
    id INTEGER PRIMARY KEY,
    location VARCHAR
);

CREATE TABLE pharmacies (
    id INTEGER PRIMARY KEY,
    name VARCHAR
);

CREATE TABLE shipments (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    pharmacy_id INTEGER NOT NULL,
    hospital_id INTEGER NOT NULL,
    date DATE,
    FOREIGN KEY (pharmacy_id) REFERENCES pharmacies(id),
    FOREIGN KEY (hospital_id) REFERENCES hospitals(id)
);

CREATE TABLE billing (
    id INTEGER PRIMARY KEY,
    hospital_id INTEGER NOT NULL,
    date DATE,
    amount REAL,
    FOREIGN KEY (hospital_id) REFERENCES hospitals(id)
);

CREATE TABLE doctors (
    id INTEGER PRIMARY KEY,
    name VARCHAR,
    working_at INTEGER NOT NULL,
    FOREIGN KEY (working_at) REFERENCES hospitals(id)
);

CREATE TABLE patients (
    id INTEGER PRIMARY KEY,
    first_name VARCHAR,
    last_name VARCHAR,
    phone_number VARCHAR,
    disease VARCHAR,
    treatment VARCHAR,
    admission_date DATE,
    discharge_date DATE,
    admitted_to INTEGER,
    primary_doctor INTEGER,
    FOREIGN KEY (admitted_to) REFERENCES hospitals(id),
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
    FOREIGN KEY (working_at) REFERENCES hospitals(id)
);

CREATE TABLE nurses_treating (
    nurse_id INTEGER NOT NULL,
    patient_id INTEGER NOT NULL,
    FOREIGN KEY (nurse_id) REFERENCES nurses(id),
    FOREIGN KEY (patient_id) REFERENCES patients(id),
    PRIMARY KEY (nurse_id, patient_id)
);

CREATE TABLE IF NOT EXISTS prescription_requests (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    hospital_id INTEGER,
    pharmacy_name VARCHAR,
    drug_name VARCHAR,
    status TEXT DEFAULT 'pending',
    request_date DATETIME DEFAULT CURRENT_TIMESTAMP
);
