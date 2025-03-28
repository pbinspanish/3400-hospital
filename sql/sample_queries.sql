-- Display all hospitals
SELECT * FROM hospital;

-- Display all pharmacies
SELECT * FROM pharmacies;

-- Display all doctors and their working hospital
SELECT doctors.id, doctors.working_at, hospital.location
FROM doctors
JOIN hospital ON doctors.working_at = hospital.id;

-- Display all patients and their primary doctor's name
SELECT patients.first_name, patients.last_name, doctors.id AS doctor_id, doctors.working_at, hospital.location
FROM patients
JOIN doctors ON patients.primary_doctor = doctors.id
JOIN hospital ON doctors.working_at = hospital.id;

-- Display all nurses and their working hospital
SELECT nurses.id, nurses.working_at, hospital.location
FROM nurses
JOIN hospital ON nurses.working_at = hospital.id;

-- Display all doctor-patient relationships
SELECT doctors.id AS doctor_id, patients.first_name, patients.last_name
FROM doctors_treating
JOIN doctors ON doctors_treating.doctor_id = doctors.id
JOIN patients ON doctors_treating.patient_id = patients.id;

-- Display all nurse-patient relationships
SELECT nurses.id AS nurse_id, patients.first_name, patients.last_name
FROM nurses_treating
JOIN nurses ON nurses_treating.nurse_id = nurses.id
JOIN patients ON nurses_treating.patient_id = patients.id;

-- Display patients admitted to a specific hospital (e.g., hospital ID 1)
SELECT * FROM patients WHERE admitted_to = 1;

-- Display doctors working at a specific hospital (e.g., hospital ID 2)
SELECT * FROM doctors WHERE working_at = 2;

-- Display patients with a specific disease (e.g., 'Flu')
SELECT * FROM patients WHERE disease = 'Flu';

-- Display patients admitted within a specific date range
SELECT * FROM patients WHERE admission_date BETWEEN '2023-10-26' AND '2023-10-28';

-- Display the number of patients per hospital
SELECT hospital.location, COUNT(patients.id) AS patient_count
FROM patients
JOIN hospital ON patients.admitted_to = hospital.id
GROUP BY hospital.location;

-- Display the number of doctors per hospital
SELECT hospital.location, COUNT(doctors.id) AS doctor_count
FROM doctors
JOIN hospital ON doctors.working_at = hospital.id
GROUP BY hospital.location;

-- Display the number of nurses per hospital
SELECT hospital.location, COUNT(nurses.id) AS nurse_count
FROM nurses
JOIN hospital ON nurses.working_at = hospital.id
GROUP BY hospital.location;

-- Display the patients each doctor is treating.
SELECT doctors.id, doctors.working_at, patients.first_name, patients.last_name
FROM doctors
JOIN doctors_treating ON doctors.id = doctors_treating.doctor_id
JOIN patients ON doctors_treating.patient_id = patients.id;

-- Display the patients each nurse is treating.
SELECT nurses.id, nurses.working_at, patients.first_name, patients.last_name
FROM nurses
JOIN nurses_treating ON nurses.id = nurses_treating.nurse_id
JOIN patients ON nurses_treating.patient_id = patients.id;