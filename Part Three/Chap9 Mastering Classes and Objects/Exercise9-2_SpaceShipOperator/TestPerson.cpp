#include "Person.h"
#include <format>
#include <iostream>
/* Exercise 9-2: 
Based on the Person class from Exercise 8-4, add full support for all six comparison operators to compare two Person objects. 
Try to implement this support in the least amount of code. Test your implementation by performing all kinds of comparisons in main().
How are Persons ordered? Is the ordering happening based on the first name, or based on the last name, or based on a combination?

Gregoire, Marc. Professional C++ (p. 335). Wiley. Kindle Edition.  */


int main()
{
	Person person{ "Bob","Builder" };
	Person otherPerson{ "Spongebob","Squarepants" };

	if (person == otherPerson)
	{
		std::cout << "Person == person" << std::endl;
	}

	if (person <= otherPerson)
	{
		std::cout << "Person <= otherPerson" << std::endl;
	}

	if (person >= otherPerson)
	{
		std::cout << "Person >= otherPerson" << std::endl;
	}

	if (person < otherPerson)
	{
		std::cout << "Person < otherPerson" << std::endl;
	}

	if (person > otherPerson)
	{
		std::cout << "Person > otherPerson" << std::endl;
	}

	if (person != otherPerson)
	{
		std::cout << "Person != otherPerson" << std::endl;
	}


	return 0;
}