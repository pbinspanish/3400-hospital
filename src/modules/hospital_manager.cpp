#include "hospital_manager.h"

void HospitalManager::addNewHospital(const int id, const std::string& location)
{
	Hospital new_hospital(id, location);
	
	hospitals.push_back(new_hospital);
}

void HospitalManager::addNewPharmacy(const int id, const std::string& name)
{
	Pharmacy new_pharmacy(id, name);
	
	pharmacies.push_back(new_pharmacy);
}

void HospitalManager::hospitalManagementMenu() {
	// get the id of the hospital to manage
	int hospital_id;
	std::cout << "\nEnter the ID of the hospital to manage:\n";
	
	for (size_t i = 0; i < getAllHospitals().size(); ++i) {
		std::cout << i + 1 << ". " << getAllHospitals()[i].location << std::endl;
	}
	std::cin >> hospital_id;

	// check if the hospital exists
	if (hospital_id < 1 || hospital_id > getAllHospitals().size()) {
		std::cout << "Invalid hospital ID" << std::endl;
		return;
	}

	// manage the hospital
	getAllHospitals()[hospital_id - 1].hospitalMenu();
}