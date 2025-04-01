#ifndef HOSPITAL_MANAGER_H
#define HOSPITAL_MANAGER_H

#include <string>
#include <vector>
#include "hospital.h"
#include "pharmacy.h"

class HospitalManager
{
private:
	std::vector<Hospital> hospitals;
	std::vector<Pharmacy> pharmacies;
public:
	void addNewHospital(const int id, const std::string& location);
	void addNewPharmacy(const int id, const std::string& name);

	std::vector<Hospital> getAllHospitals() { return hospitals; }
	std::vector<Pharmacy> getAllPharmacies() { return pharmacies; }

	void hospitalManagementMenu();
};

#endif