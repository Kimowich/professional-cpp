#pragma once
#include <string>
#include <string_view>

class Person
{
public:
	Person();
	Person(std::string_view firstName, std::string_view lastName);
	Person(std::string_view firstName, std::string_view lastName, std::string_view initials);

	void set(const std::string_view firstName, const std::string_view lastName);
	void setInitials(const std::string_view initials);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getInitials() const;

	friend std::ostream& operator<<(std::ostream& os, const Person& src);

	_NODISCARD std::partial_ordering operator<=>(const Person& rhs) const = default;

private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_initials;
};

