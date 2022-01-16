#include "Person.h"
#include <iostream>
#include <format>

Person::Person(std::string_view firstName, std::string_view lastName) : m_firstName{ firstName }, m_lastName{ lastName }
{
	m_initials += firstName.at(0);
	m_initials += lastName.at(0);
}

Person::Person(std::string_view firstName, std::string_view lastName, std::string_view initials) : m_firstName{ firstName }, m_lastName{ lastName }, m_initials{initials}
{
}

void Person::set(const std::string_view firstName, const std::string_view lastName)
{
	m_firstName = firstName;
	m_lastName = lastName;
}

void Person::setInitials(const std::string_view initials)
{
	m_initials = initials;
}

std::string Person::getFirstName() const
{
	return m_firstName;
}

std::string Person::getLastName() const
{
	return m_lastName;
}

std::string Person::getInitials() const
{
	return m_initials;
}

void Person::output(std::ostream& os) const
{
	os << format("Name: {} {}\nInitials: {}. \n", getFirstName(), getLastName(), getInitials());
}


std::ostream& operator<<(std::ostream& os, const Person& src)
{
	os << format("{} {}", src.getFirstName(), src.getLastName());
	return os;
}