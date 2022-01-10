#pragma once
#include <string>
#include <string_view>
class Person
{
public:
	Person() = default;
	Person(std::string_view firstName, std::string_view lastName) : m_firstName{firstName}, m_lastName{lastName}{};

	void set(const std::string_view firstName, const std::string_view lastName);
	std::string getFirstName() const;
	std::string getLastName() const;

private:
	std::string m_firstName;
	std::string m_lastName;
};

