#include "Person.h"
#include <iostream>
#include <format>

namespace HR
{
	Person::Person()
	{
		std::cout << "Default Constructor called" << std::endl;
	}

	Person::Person(std::string_view firstName, std::string_view lastName) : m_firstName{ firstName }, m_lastName{ lastName }
	{
		std::cout << "C-tor initialised" << std::endl;
		m_initials += firstName.at(0);
		m_initials += lastName.at(0);
	}

	Person::Person(std::string_view firstName, std::string_view lastName, std::string_view initials) : m_firstName{ firstName }, m_lastName{ lastName }, m_initials{ initials }
	{
	}

	void Person::setFirstName(const std::string_view firstName)
	{
		m_firstName = firstName;
	}

	void Person::setLastName(const std::string_view lastName)
	{
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

	std::ostream& operator<<(std::ostream& os, const HR::Person& src)
	{
		os << format("{} {}", src.getFirstName(), src.getLastName());
		return os;
	}

}

