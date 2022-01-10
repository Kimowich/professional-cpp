#include "Person.h"
#include <iostream>

Person::Person()
{
	std::cout << "Default Constructor called" << std::endl;
}

Person::Person(std::string_view firstName, std::string_view lastName) : m_firstName{ firstName }, m_lastName{ lastName }
{
	std::cout << "C-tor initialised" << std::endl;
}

Person::Person(const Person& src) : m_firstName{ src.m_firstName }, m_lastName{ src.m_lastName }
{
	std::cout << "Copy constructor called" << std::endl;
}

Person::~Person()
{
	std::cout << "Destructor called" << std::endl;
}

Person& Person::operator=(const Person& rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this == &rhs)
	{
		return *this;
	}
	m_firstName = rhs.getFirstName();
	m_lastName = rhs.getLastName();

	return *this;
		
}

void Person::set(const std::string_view firstName, const std::string_view lastName)
{
	m_firstName = firstName;
	m_lastName = lastName;
}

std::string Person::getFirstName() const
{
	return m_firstName;
}

std::string Person::getLastName() const
{
	return m_lastName;
}
