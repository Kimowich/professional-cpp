#include "person.h"

Person::Person(std::string_view firstName, std::string_view lastName)
{
	std::string firstInitial{};
	std::string lastInitial{};
	firstInitial = firstName.at(0);
	lastInitial = lastName.at(0);
	this->firstName = firstName;
	this->lastName = lastName;
	this->initials = firstInitial + "." + lastInitial;
}

Person::Person(
	std::string_view firstName,
	std::string_view lastName,
	std::string_view initials)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->initials = initials;
}
/* Copy Constructor */
Person::Person(const Person& src) : firstName{ src.firstName }, lastName{ src.lastName }
{
	std::cout << "Person copy constructor called." << std::endl;
}

Person::~Person()
{
}

void Person::setFirstName(std::string_view firstName)
{
	this->firstName = firstName;
}

void Person::setLastname(std::string_view lastName)
{
	this->lastName = lastName;
}

void Person::setInitials(std::string_view initials)
{
	this->initials = initials;
}

std::string Person::getFirstName() const
{
	return this->firstName;
}

std::string Person::getLastName() const
{
	return this->lastName;
}

std::string Person::getinitials() const
{
	return this->initials;
}

/* Assigment operator */
Person& Person::operator=(const Person& rhs)
{
	std::cout << "Person assignment operator called." << std::endl;
	auto temp{ rhs };
	swap(temp);
	return *this;
}

/* Swap function to avoid dublicate code*/
void Person::swap(Person& other) noexcept
{
	std::swap(firstName, other.firstName);
	std::swap(lastName, other.lastName);
}