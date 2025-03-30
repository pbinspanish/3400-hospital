-- Hospitals
INSERT INTO hospitals (location) VALUES
('City General Hospital'),
('County Medical Center'),
('State University Hospital'),
('Regional Community Hospital'),
('Downtown Urgent Care');

-- Pharmacies
INSERT INTO pharmacies (name) VALUES
('City Pharmacy'), ('County Drugs'), ('State Meds'), ('Regional Rx'), ('Downtown Pharmacy'),
('Central Pharmacy'), ('Uptown Drugs'), ('Hilltop Meds'), ('Valley Rx'), ('Lakeside Pharmacy'),
('Northside Pharmacy'), ('Southside Drugs'), ('Eastside Meds'), ('Westside Rx'), ('Midtown Pharmacy'),
('Parkside Pharmacy'), ('Riverside Drugs'), ('Oceanview Meds'), ('Mountainview Rx'), ('Forest Pharmacy');

-- Doctors
INSERT INTO doctors (working_at) VALUES
(1), (1), (1), (1), (1), (1), (1), (1), (1), (1),
(2), (2), (2), (2), (2), (2), (2), (2), (2), (2),
(3), (3), (3), (3), (3), (3), (3), (3), (3), (3),
(4), (4), (4), (4), (4), (4), (4), (4), (4), (4),
(5), (5), (5), (5), (5), (5), (5), (5), (5), (5);

-- Nurses
INSERT INTO nurses (working_at) VALUES
(1), (1), (1), (1), (1), (1), (1), (1), (1), (1), (1), (1),
(2), (2), (2), (2), (2), (2), (2), (2), (2), (2), (2), (2),
(3), (3), (3), (3), (3), (3), (3), (3), (3), (3), (3), (3),
(4), (4), (4), (4), (4), (4), (4), (4), (4), (4), (4), (4),
(5), (5), (5), (5), (5), (5), (5), (5), (5), (5), (5), (5);

-- Patients (20 patients per hospital)
-- Hospital 1 Patients
INSERT INTO patients (first_name, last_name, phone_number, disease, treatment, admission_date, discharge_date, admitted_to, primary_doctor) VALUES
('Alice', 'Smith', '123-456-7890', 'Flu', 'Rest and fluids', '2023-10-26', NULL, 1, 1),
('Bob', 'Johnson', '987-654-3210', 'Broken leg', 'Cast and pain medication', '2023-10-26', NULL, 1, 2),
('Charlie', 'Williams', '555-123-4567', 'Pneumonia', 'Antibiotics', '2023-10-26', NULL, 1, 3),
('David', 'Brown', '111-222-3333', 'Heart condition', 'Medication and monitoring', '2023-10-26', NULL, 1, 4),
('Eve', 'Davis', '444-555-6666', 'Appendicitis', 'Surgery', '2023-10-26', NULL, 1, 5),
('Frank', 'Miller', '777-888-9999', 'Migraine', 'Pain medication', '2023-10-27', NULL, 1, 6),
('Grace', 'Wilson', '222-333-4444', 'Asthma', 'Inhaler', '2023-10-27', NULL, 1, 7),
('Henry', 'Moore', '666-777-8888', 'Diabetes', 'Insulin', '2023-10-27', NULL, 1, 8),
('Ivy', 'Taylor', '999-000-1111', 'Kidney stones', 'Pain medication and fluids', '2023-10-27', NULL, 1, 9),
('Jack', 'Anderson', '333-444-5555', 'Lyme disease', 'Antibiotics', '2023-10-27', NULL, 1, 10),
('Kelly', 'Thomas', '888-999-0000', 'Bronchitis', 'Cough medicine', '2023-10-28', NULL, 1, 1),
('Liam', 'Jackson', '123-987-6543', 'Concussion', 'Rest and observation', '2023-10-28', NULL, 1, 2),
('Mia', 'White', '456-321-7890', 'Food poisoning', 'Fluids and rest', '2023-10-28', NULL, 1, 3),
('Noah', 'Harris', '789-654-1230', 'Gout', 'Pain medication', '2023-10-28', NULL, 1, 4),
('Olivia', 'Martin', '321-987-4560', 'High blood pressure', 'Medication', '2023-10-28', NULL, 1, 5),
('Peter', 'Thompson', '654-321-9870', 'Hypothyroidism', 'Medication', '2023-10-29', NULL, 1, 6),
('Quinn', 'Garcia', '987-123-6540', 'Insomnia', 'Sleep medication', '2023-10-29', NULL, 1, 7),
('Ryan', 'Martinez', '123-789-4560', 'Jaundice', 'Treatment depends on cause', '2023-10-29', NULL, 1, 8),
('Sophia', 'Robinson', '456-987-1230', 'Knee injury', 'Physical therapy', '2023-10-29', NULL, 1, 9),
('Tyler', 'Clark', '789-321-6540', 'Lupus', 'Medication', '2023-10-29', NULL, 1, 10);

-- Repeat similar insertion patterns for hospitals 2-5, changing patient names, diseases, etc., and using the appropriate hospital and doctor IDs.

-- Doctors_treating
INSERT INTO doctors_treating (doctor_id, patient_id) VALUES
(1, 1), (2, 2), (3, 3), (4, 4), (5, 5), (6, 6), (7, 7), (8, 8), (9, 9), (10, 10),
(1, 11), (2, 12), (3, 13), (4, 14), (5, 15), (6, 16), (7, 17), (8, 18), (9, 19), (10, 20);

-- Repeat for all patients.

-- Nurses_treating
INSERT INTO nurses_treating (nurse_id, patient_id) VALUES
(1, 1), (1, 2), (2, 3), (2, 4), (3, 5), (3, 6), (4, 7), (4, 8), (5, 9), (5, 10),
(6,11),(6,12),(7,13),(7,14),(8,15),(8,16),(9,17),(9,18),(10,19),(10,20);

--Repeat for all hospitals. Make sure each nurse has at most 2 patients.