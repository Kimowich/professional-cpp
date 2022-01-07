#include <string>
#include <iostream>
#include <utility>

class Person
{
private:
	std::string firstName{ "" };
	std::string lastName{ "" };
	std::string initials{ "" };
public:
	Person(std::string_view firstName, std::string_view lastName);
	Person(std::string_view firstName, std::string_view lastName, std::string_view initials);
	Person() = default;
	Person(const Person& src);
	~Person();

	void setFirstName(std::string_view firstName);
	void setLastname(std::string_view lastName);
	void setInitials(std::string_view initials);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getinitials() const;
	void swap(Person& other) noexcept;
	Person& operator=(const Person& rhs);
};


