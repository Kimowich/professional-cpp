#include "Person.h"
#include <iostream>

class Person::Impl {
public:
	Impl() = default;
	Impl(std::string_view firstName, std::string_view lastName);
	Impl(std::string_view firstName, std::string_view lastName, std::string_view initials);
	~Impl() = default;
	void set(const std::string_view firstName, const std::string_view lastName);
	void setInitials(const std::string_view initials);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getInitials() const;
private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_initials;

};
Person::Person()
	: m_impl{ std::make_unique<Impl>() }
{
}

Person::Impl::Impl(std::string_view firstName, std::string_view lastName) : m_firstName{firstName}, m_lastName{lastName}
{
	m_initials += firstName.at(0);
	m_initials += lastName.at(0);
}

Person::Impl::Impl(std::string_view firstName, std::string_view lastName, std::string_view initials) :
	m_firstName{firstName}, m_lastName{lastName}, m_initials{initials}
{
}

void Person::Impl::set(const std::string_view firstName, const std::string_view lastName)
{
}

void Person::Impl::setInitials(const std::string_view initials)
{
	m_impl->setInitials(std::move(initials));
}

std::string Person::Impl::getFirstName() const
{
	return m_firstName;
}

std::string Person::Impl::getLastName() const
{
	return m_lastName;
}

std::string Person::Impl::getInitials() const
{
	return m_initials;
}
