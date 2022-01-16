#include "Person.h"
#include "Database.h"
#include <format>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
/* Exercise 13-4: 
The Database from Exercise 13-3 stores all persons in a single file. 
To practice the filesystem support library, let's change that to store each person in its own file. 
Modify the save() and load() methods to accept a directory as argument where files should be stored to or loaded from. 
The save() method saves every person in the database to its own file with the person's initials as the name and with a .person extension. 
If a file already exists, overwrite it. The load() method iterates over all .person files in a given directory and loads all of them.

Gregoire, Marc. Professional C++ (p. 494). Wiley. Kindle Edition.  */


int main()
{
	// Create new database
	Database registry;

	// path to program
	std::filesystem::path filepath{ R"(E:\persons)"};
	// add people
	registry.add(Person{ "SpongeBob", "Squarepants" });
	registry.add(Person{ "Patrick", "Starfish" });
	registry.add(Person{ "Sandy", "Cheeks" });
	registry.add(Person{ "Eugene", "Kraps" });

	registry.outputAll();

	registry.save(filepath);

	return 0;
}