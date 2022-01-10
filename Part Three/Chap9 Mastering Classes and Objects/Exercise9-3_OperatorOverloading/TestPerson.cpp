#include "Person.h"
#include <format>
#include <iostream>
/* Exercise 9-3: 
Before C++20, adding support for all six comparison operators required a bit more lines of code. 
Start from the Person class from Exercise 9-2, remove the operator<=>, 
and add the necessary code to add all comparison operators to compare two Person objects without using <=>. 
Perform the same set of tests as you've implemented for Exercise 9-2.

Gregoire, Marc. Professional C++ (p. 335). Wiley. Kindle Edition. */


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

	if (otherPerson == person)
	{
		std::cout << "otherPerson == person" << std::endl;
	}

	if (otherPerson <= person)
	{
		std::cout << "otherPerson <= person" << std::endl;
	}

	if (otherPerson >= person)
	{
		std::cout << "otherPerson >= person" << std::endl;
	}

	if (otherPerson < person)
	{
		std::cout << "otherPerson < person" << std::endl;
	}

	if (otherPerson > person)
	{
		std::cout << "otherPerson > person" << std::endl;
	}

	if (otherPerson != person)
	{
		std::cout << "otherPerson != person" << std::endl;
	}

	return 0;
}