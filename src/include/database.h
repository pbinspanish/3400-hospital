#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <SQLiteCpp/SQLiteCpp.h>
#include <vector>

class Database {
	public:
		static void createDatabase();
		static void insertTestData();
		static void executeSQL(const std::string& SQL);
		std::vector<std::vector<std::string>> executeQuery(const std::string& sql);

};

#endif
