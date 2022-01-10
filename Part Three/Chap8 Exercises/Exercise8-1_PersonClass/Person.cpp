#include "Person.h"

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
