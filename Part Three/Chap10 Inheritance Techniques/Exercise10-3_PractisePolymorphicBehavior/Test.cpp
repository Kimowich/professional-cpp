#include "Person.h"
#include "Employee.h"
#include "Manager.h"
#include "Director.h"
#include <format>
#include <iostream>
#include <vector>
#include <memory>
/* Exercise 10-3: 
Practise polymorphic behavior of the classes in your Person hierarchy from Exercise 10-2. 
Define a vector to store a mix of employees, managers, and directors, and fill it with some test data. 
Finally, use a single range-based for loop to call toString() on all of the elements in the vector.

Gregoire, Marc. Professional C++ (p. 395). Wiley. Kindle Edition.  */


int main()
{
	std::vector<std::unique_ptr<HR::Person>> company;

	company.push_back(std::make_unique<HR::Director>("Eugene","Krabs",1));
	company.push_back(std::make_unique<HR::Manager>("Squidward", "Tentacles", 10));
	company.push_back(std::make_unique<HR::Employee>("SpongeBob", "Squarepants", 100));
	company.push_back(std::make_unique<HR::Employee>("Patric", "Starfish", 101));
	company.push_back(std::make_unique<HR::Employee>("Sandy", "Cheeks", 102));

	for (auto& employee : company)
	{
		std::cout << *employee << std::endl;
	}

	std::vector<HR::Person> otherCompany;

	otherCompany.push_back(HR::Director("Eugene", "Krabs", 1));
	otherCompany.push_back(HR::Manager("Squidward", "Tentacles", 10));
	otherCompany.push_back(HR::Employee("SpongeBob", "Squarepants", 100));
	otherCompany.push_back(HR::Employee("Patric", "Starfish", 101));
	otherCompany.push_back(HR::Employee("Sandy", "Cheeks", 102));

	for (auto& employee : otherCompany)
	{
		std::cout << employee << std::endl;
	}

	return 0;
}