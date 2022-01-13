#include "Database.h"
#include <iostream>
/* 
	Adds persons to database.
*/
void Database::add(const Person& person)
{
	listofPeople.push_back(person);
}
/*
	Saves all persons to a file
*/
void Database::save(const std::string_view fileName)
{

}
/*
	Loads all persons from a file
*/
void Database::load(const std::string_view fileName)
{

}
/*
	Clears all persons from database
*/
void Database::clear()
{
	listofPeople.clear();
}
/*
	Output all persons, using Person::output method
*/
void Database::outputAll()
{
	std::cout << "\nList of all people \n";
	for (auto& person : listofPeople)
	{
		person.output(std::cout);
	}
	std::cout << "\n";
}
