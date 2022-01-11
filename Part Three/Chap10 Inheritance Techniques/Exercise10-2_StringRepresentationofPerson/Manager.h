#pragma once
#include "Employee.h"

namespace HR
{
    class Manager :
        public Employee
    {
        using Employee::Employee;

        virtual std::string toString() const;
    };
}

