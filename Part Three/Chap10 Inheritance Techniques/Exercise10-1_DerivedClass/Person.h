#pragma once
#include <string>
#include <string_view>
namespace HR
{
	class Person
	{
	public:
		Person();
		Person(std::string_view firstName, std::string_view lastName);
		Person(std::string_view firstName, std::string_view lastName, std::string_view initials);

		virtual void setFirstName(const std::string_view firstName);
		virtual void setLastName(const std::string_view lastName);
		virtual void setInitials(const std::string_view initials);

		virtual std::string getFirstName() const;
		virtual std::string getLastName() const;
		virtual std::string getInitials() const;
		
		friend std::ostream& operator<<(std::ostream& os, const HR::Person& src);
		
		_NODISCARD std::partial_ordering operator<=>(const Person& rhs) const = default;

	private:
		std::string m_firstName;
		std::string m_lastName;
		std::string m_initials;
	};

}


