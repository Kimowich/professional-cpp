#pragma once
#include "Person.h"
#include <format>
namespace HR
{
	class Employee :
		public Person
	{
	public:
		Employee() = default;
		Employee(std::string_view firstName, std::string_view lastName, int id);
		void setID(const int ID);
		int getID();

		virtual std::string toString() const;
	private:
		int m_id{0};
	};

}

