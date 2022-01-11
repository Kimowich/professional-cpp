#pragma once
#include "Employee.h"

namespace HR
{
	class Director :
		public Employee
	{
		using Employee::Employee;

		virtual std::string toString() const;
	};
}



