#pragma once
#include <string>
#include <string_view>
#include <memory>
class Person
{
public:
	Person();
	Person(std::string_view firstName, std::string_view lastName);
	Person(std::string_view firstName, std::string_view lastName, std::string_view initials);

	void set(const std::string_view firstName, const std::string_view lastName);
	void setInitials(const std::string_view initials);

	//std::string getFirstName() const;
	//std::string getLastName() const;
	//std::string getInitials() const;
private:
	class Impl;
	std::unique_ptr<Impl> m_impl;
};

