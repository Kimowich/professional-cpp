#include "Person.h"
#include <iostream>
#include <format>

Person::Person()
{
	std::cout << "Default Constructor called" << std::endl;
}

Person::Person(std::string_view firstName, std::string_view lastName) : m_firstName{ firstName }, m_lastName{ lastName }
{
	std::cout << "C-tor initialised" << std::endl;
}
// Copy constructor
Person::Person(const Person& src) : m_firstName{ src.m_firstName }, m_lastName{ src.m_lastName }
{
	std::cout << "Copy constructor called" << std::endl;
}
// Move Constructor, Person&& is a rvalue reference 
Person::Person(Person&& src) noexcept
{
	std::cout << "Move Constructor called" << std::endl;
	swap(src);
}
// Move assignment operator,
Person& Person::operator=(Person&& rhs) noexcept
{
	std::cout << "Move assignment operator called" << std::endl;
	swap(rhs);
	return *this;
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

void Person::swap(Person& rhs) noexcept
{
	std::swap(m_firstName, rhs.m_firstName);
	std::swap(m_lastName, rhs.m_lastName);
}

std::ostream& operator<<(std::ostream& os, const Person& src)
{
	os << format("{} {}", src.getFirstName(), src.getLastName());
	return os;
}
