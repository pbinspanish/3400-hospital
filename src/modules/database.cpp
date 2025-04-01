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


std::vector<std::vector<std::string>> Database::executeQuery(const std::string& sql) {
    std::vector<std::vector<std::string>> results;

    try {
        SQLite::Database db("hms.db3", SQLite::OPEN_READWRITE);
        SQLite::Statement query(db, sql);

        while (query.executeStep()) {
            std::vector<std::string> row;
            for (int i = 0; i < query.getColumnCount(); ++i) {
                row.push_back(query.getColumn(i).getString());
            }
            results.push_back(row);
        }
    } catch (std::exception& e) {
        std::cerr << "SQLite error: " << e.what() << std::endl;
    }

    return results;
}
