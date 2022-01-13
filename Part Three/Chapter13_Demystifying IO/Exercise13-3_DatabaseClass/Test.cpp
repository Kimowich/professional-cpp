#include "Person.h"
#include "Database.h"
#include <format>
#include <iostream>
#include <sstream>
#include <fstream>
/* Exercise 13-3: Develop a class called Database that stores Persons (from Exercise 13-2) in an std::vector. 
Provide an add() method to add a person to the database. 
Also provide a save() method, accepting the name of a file to which it saves all persons in the database. 
Any existing contents in the file is removed. Add a load() method, accepting the name of a file from which the database loads all persons. 
Provide a clear() method to remove all persons from the database. 
Finally, add a method outputAll() that calls output() on all persons in the database. 

Make sure your implementation works, even if there are spaces in a person's first or last name.

Gregoire, Marc. Professional C++ (p. 494). Wiley. Kindle Edition. */


int main()
{
	// Create new database
	Database registry;
	
	// add a person
	registry.add(Person{ "SpongeBob", "Squarepants" });

	// test output function
	registry.outputAll();

	// test clear function
	registry.clear();

	registry.outputAll();

	// add more people
	registry.add(Person{ "Patrick", "Starfish" });
	registry.add(Person{ "Sandy", "Cheeks" });
	registry.outputAll();
	// test output function

	// clear the database

	// Test output function

	return 0;
}