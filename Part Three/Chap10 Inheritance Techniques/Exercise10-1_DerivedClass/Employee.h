#pragma once
#include "Person.h"
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
	private:
		int m_id{0};
	};

}

