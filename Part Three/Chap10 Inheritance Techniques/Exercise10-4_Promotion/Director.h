#pragma once
#include "Employee.h"

namespace HR
{
	class Director :
		public Employee
	{
	public:
		using Employee::Employee;

		Director(const Employee& employee) : Employee{ employee } {};

		virtual std::string toString() const;
	};
}



