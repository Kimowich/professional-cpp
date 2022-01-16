#include "Database.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
/* 
	Adds persons to database.
*/
void Database::add(const Person& person)
{
	m_listOfPeople.push_back(person);
}
/*
	Saves all persons to a file
*/
void Database::save(const std::filesystem::path fileName) const
{
	std::cout << "Saving database" << std::endl;
	// open file

	for (const auto& person : m_listOfPeople)
	{
		std::filesystem::path personfile{ fileName };
		personfile.append(person.getInitials() + ".person");
		std::ofstream outFile{ personfile, std::ios_base::trunc};
		if (!outFile)
		{
			std::cerr << "Cannot open file: " << personfile << std::endl;
			return;
		}

		outFile << std::quoted(person.getFirstName()) 
			<< std::quoted(person.getLastName()) 
			<< std::quoted(person.getInitials()) << std::endl;
	}
	
}
/*
	Loads all persons from a file
*/
void Database::load(const std::filesystem::path fileName)
{
	// Iterate over all the files in the given folder.
	std::filesystem::directory_iterator begin{ fileName };
	std::filesystem::directory_iterator end{ };
	for (auto iter{ begin }; iter != end; ++iter) {
		auto& entry{ *iter };

		// Skip if there is no extension, or it is not .person
		if (!entry.path().has_extension() ||
			entry.path().extension() != ".person") {
			continue;
		}

		// Parse the file.
		std::cout << "Loading database" << std::endl;
		std::ifstream inFile{ entry.path() };
		if (!inFile)
		{
			std::cerr << "Cannot open file: " << entry.path() << std::endl;
			return;
		}

		while (inFile)
		{
			std::string line;
			std::getline(inFile, line);
			if (line.empty())
			{
				continue;
			}

			std::istringstream inLine{ line };
			std::string firstName, lastName, initials;

			if (inLine.bad())
			{
				std::cerr << "Error reading person. Ignoring." << std::endl;
			}
			inLine >> std::quoted(firstName) >> std::quoted(lastName) >> std::quoted(initials);

			// create a new person object and push to database
			m_listOfPeople.push_back(Person{ std::move(firstName), std::move(lastName), std::move(initials) });
		}
	}
}
/*
	Clears all persons from database
*/
void Database::clear()
{
	std::cout << "Clearing database" << std::endl;
	m_listOfPeople.clear();
}
/*
	Output all persons, using Person::output method
*/
void Database::outputAll()
{
	std::cout << "\nList of all people \n";
	for (auto& person : m_listOfPeople)
	{
		person.output(std::cout);
	}
	std::cout << "\n";
}
