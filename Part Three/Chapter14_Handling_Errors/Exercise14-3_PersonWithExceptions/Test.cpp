#include "Person.h"
#include "Database.h"
#include <format>
#include <iostream>
#include <sstream>
#include <fstream>
/* Exercise 14-3: 
Add proper error handling using exceptions to your person database solution of Exercise 13-3.

Gregoire, Marc. Professional C++ (p. 533). Wiley. Kindle Edition.  */


int main()
{
	try
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
		registry.add(Person{ "Eugene", "Kraps" });

		registry.outputAll();
		// Test save function
		registry.save("personDatabase.db");

		registry.clear();

		registry.load("personDatabase.db");

		registry.outputAll();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}