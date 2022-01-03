#include <employee.h>

namespace Records{
    Employee::Employee(const std::string& firstName, const std::string& lastName) :
        firstName{firstName}, lastName{lastName}
    {
    }
    
    Employee::~Employee()
    {
    }

    void Employee::promote(int raiseAmount)
    {
        setSalary(getSalary()+raiseAmount);
    }

    void Employee::demote(int demeritAmount)
    {
        setSalary(getSalary()-demeritAmount);
    }

    void Employee::hire()
    {
        this->hired=true;
    }
    
    void Employee::fire()
    {
        this->hired=false;
    }

    void Employee::display() const
    {
        std::cout << "Employee: " << getLastName() << ", " << getFirstName() <<std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << (isHired()? "Current Employee": "Former Employee")<<std::endl;
        std::cout << "Employee number: " << getEmployeeNumber() << std::endl;
        std::cout << "Salary: " << getSalary() << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << std::endl;
    }

    int Employee::getEmployeeNumber() const
    {
        return employeeNumber;
    }

    void Employee::setEmployeeNumber(int employeeNumber)
    {
        this->employeeNumber = employeeNumber;
    }

    std::string Employee::getFirstName() const
    {
        return firstName;
    }

    void Employee::setFirstName(const std::string& firstName)
    {
        this->firstName=firstName;
    }

    std::string Employee::getLastName() const
    {
        return lastName;
    }

    void Employee::setLastname(const std::string& lastName)
    {
        this->lastName=lastName;
    }

    int Employee::getSalary() const
    {
        return salary;
    }

    void Employee::setSalary(int newSalary)
    {
        this->salary = newSalary;
    }

    bool Employee::isHired() const
    {
        return hired;
    }
}