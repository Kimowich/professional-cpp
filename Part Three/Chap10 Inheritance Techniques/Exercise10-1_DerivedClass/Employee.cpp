#include "Employee.h"

namespace HR
{
	Employee::Employee(std::string_view firstName, std::string_view lastName, int id)
		: Person{ firstName, lastName }, m_id{ id }
	{
	}
	void Employee::setID(const int id)
	{
		m_id = id;
	}
	int Employee::getID()
	{
		return m_id;
	}
}
