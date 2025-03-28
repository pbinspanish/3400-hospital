#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <fstream>
#include <string>

#include <SQLiteCpp/SQLiteCpp.h>

int main ()
{
    try
    {
        // Open a database file in create/write mode
        SQLite::Database db("hms.db3", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
        std::cout << "SQLite database file '" << db.getFilename().c_str() << "' opened successfully\n";

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
            return EXIT_FAILURE;
        }

        // Execute SQL query without results
        db.exec(sql.c_str());

        // read sql file to insert test data
        sql = "";
        file.open("../sql/test_data.sql");
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
            return EXIT_FAILURE;
        }
        
        std::cout << sql << std::endl;
        // Execute SQL query without results
        db.exec(sql);

        SQLite::Statement query(db, "SELECT * FROM hospital");
        std::cout << "SELECT * FROM hospital :\n";
        while (query.executeStep())
        {
            std::cout << "row (" << query.getColumn(0) << ", \"" << query.getColumn(1) << "\")\n";
        }

        // // Create a new table with an explicit "id" column aliasing the underlying rowid
        // db.exec("DROP TABLE IF EXISTS test");
        // db.exec("CREATE TABLE test (id INTEGER PRIMARY KEY, value TEXT)");

        // // first row
        // int nb = db.exec("INSERT INTO test VALUES (NULL, \"test\")");
        // std::cout << "INSERT INTO test VALUES (NULL, \"test\")\", returned " << nb << std::endl;

        // // second row
        // nb = db.exec("INSERT INTO test VALUES (NULL, \"second\")");
        // std::cout << "INSERT INTO test VALUES (NULL, \"second\")\", returned " << nb << std::endl;

        // // update the second row
        // nb = db.exec("UPDATE test SET value=\"second-updated\" WHERE id='2'");
        // std::cout << "UPDATE test SET value=\"second-updated\" WHERE id='2', returned " << nb << std::endl;

        // // Check the results : expect two row of result
        // SQLite::Statement   query(db, "SELECT * FROM test");
        // std::cout << "SELECT * FROM test :\n";
        // while (query.executeStep())
        // {
        //     std::cout << "row (" << query.getColumn(0) << ", \"" << query.getColumn(1) << "\")\n";
        // }

        // db.exec("DROP TABLE test");
    }
    catch (std::exception& e)
    {
        std::cout << "SQLite exception: " << e.what() << std::endl;
        return EXIT_FAILURE; // unexpected error : exit the example program
    }
    remove("test.db3");

    std::cout << "everything ok, quitting\n";

    return EXIT_SUCCESS;
}