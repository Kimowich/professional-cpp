#pragma once
#include "Employee.h"

namespace HR
{
    class Manager :
        public Employee
    {
    public:
        using Employee::Employee;

        Manager(const Employee& employee) : Employee{ employee } {};

        virtual std::string toString() const;
    };
}

