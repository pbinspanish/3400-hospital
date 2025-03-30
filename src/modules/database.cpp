#include "database.h"

// Helper

void Database::createDatabase()
{
	try
	{
		// Open a database file in create/write mode
		SQLite::Database db("hms.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

		// read sql file in to create database
		std::string sql;
		std::string line;
		std::ifstream file("../sql/create_database.sql");
		if (file.is_open())
		{
			while (getline(file, line))
			{
				sql += line;
			}
			file.close();
		}
		else
		{
			std::cerr << "Unable to open file" << std::endl;
			return;
		}

		// Execute SQL query without results
		db.exec(sql.c_str());
	}
	catch (std::exception &e)
	{
		std::cerr << "SQLite error: " << e.what() << std::endl;
	}
}

void Database::insertTestData()
{
	try
	{
		SQLite::Database db("hms.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

		// read sql file to insert test data
		std::string sql;
		std::string line;
		std::ifstream file("../sql/test_data.sql");
		if (file.is_open())
		{
			while (getline(file, line))
			{
				sql += line + "\n";
			}
			file.close();
		}
		else
		{
			std::cerr << "Unable to open file" << std::endl;
			return;
		}

		std::cout << sql << std::endl;
		// Execute SQL query without results
		db.exec(sql);
	}
	catch (std::exception &e)
	{
		std::cerr << "SQLite error: " << e.what() << std::endl;
	}
}

void Database::executeSQL(const std::string &sql)
{
	try
	{
		SQLite::Database db("hms.db3", SQLite::OPEN_READWRITE);
		db.exec(sql);
	}
	catch (const SQLite::Exception &e)
	{
		std::cerr << "SQLite error: " << e.what() << std::endl;
	}
}