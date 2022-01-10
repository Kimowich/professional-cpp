#pragma once
#include <string>
#include <string_view>

class Person
{
public:
	Person();
	Person(std::string_view firstName, std::string_view lastName);
	Person(const Person& src);
	~Person();

	Person& operator=(const Person& rhs);

	void set(const std::string_view firstName, const std::string_view lastName);
	std::string getFirstName() const;
	std::string getLastName() const;

private:
	std::string m_firstName;
	std::string m_lastName;
};

