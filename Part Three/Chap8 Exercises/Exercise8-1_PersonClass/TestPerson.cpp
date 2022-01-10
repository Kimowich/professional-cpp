#include "Person.h"

#include <iostream>
#include <format>
#include <memory>

int main()
{
	// stack person
	Person stackPerson{"Bob", "Builder"};

	std::cout << format("Person, on stack, first name is {}", stackPerson.getFirstName()) << std::endl;

	// free store person
	auto freestorePerson{ std::make_unique<Person>("Jesus", "Christ") };

	std::cout << format("Person, in freestore, last name is {}", freestorePerson->getLastName());

}