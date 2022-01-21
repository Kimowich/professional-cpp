#include "Database.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <exception>
#include <format>

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
void Database::save(const std::string_view fileName) const
{
	std::cout << "Saving database" << std::endl;
	// open file
	std::ofstream outFile{ fileName.data(), std::ios_base::trunc };
	if (!outFile && !outFile.eof())
	{
		throw std::runtime_error(std::format(" Cannot open file {}",fileName.data()));
	}

	for (const auto& person : m_listOfPeople)
	{
		outFile << std::quoted(person.getFirstName()) 
			<< std::quoted(person.getLastName()) 
			<< std::quoted(person.getInitials()) << std::endl;
	}	
}

/*
	Loads all persons from a file
*/
void Database::load(const std::string_view fileName)
{
	std::cout << "Loading database" << std::endl;
	std::ifstream inFile{ fileName.data() };
	if (!inFile)
	{
		throw std::runtime_error(std::format(" Cannot open file {}", fileName.data()));
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
			throw std::runtime_error(std::format("Error reading person. Wrong data\n\t{}", inLine.str()));
		}
		inLine >> std::quoted(firstName) >> std::quoted(lastName) >> std::quoted(initials);

		// create a new person object and push to database
		m_listOfPeople.push_back(Person{std::move(firstName), std::move(lastName), std::move(initials) });
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
