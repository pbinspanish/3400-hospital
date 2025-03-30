#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <SQLiteCpp/SQLiteCpp.h>

class Database {
	public:
		static void createDatabase();
		static void insertTestData();
		static void executeSQL(const std::string& sql);
};

#endif