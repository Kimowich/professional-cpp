#include <database.h>

namespace Records{

    DataBase::DataBase(/* args */)
    {
    }
    
    DataBase::~DataBase()
    {
    }

    Employee& DataBase::addEmployee(  const std::string firstName,
                            const std::string lastName)
    {
        Employee emp{firstName,lastName};
        emp.setEmployeeNumber(nextEmployeeNumber++);
        emp.hire();
        employees.push_back(emp);
        return employees.back();
    }

    Employee& DataBase::getEmployee( int employeeNumber)
    {
        for (auto &employee : employees)
        {
            if (employee.getEmployeeNumber()==employeeNumber)
            {
                return employee;
            }
            
        }
        throw std::logic_error{"no employee found"};
    }

    Employee& DataBase::getEmployee( const std::string firstName,
                            const std::string lastName)
    {
        for (auto &employee : employees)
        {
            if (employee.getFirstName()==firstName
                && employee.getLastName()==lastName)
            {
                return employee;
            }
            
        }
        throw std::logic_error{"no employee found"};
    }

    void DataBase::displayAll() const
    {
        for (auto &employee : employees)
        {
            employee.display();
        }
    }

    void DataBase::displayCurrent() const
    {
        for (auto &employee : employees)
        {
            if(employee.isHired())
            {
                employee.display();
            }
        }
    }

    void DataBase::displayFormer() const
    {
        for (auto &employee : employees)
        {
            if(!employee.isHired())
            {
                employee.display();
            }
        }  
    }
}