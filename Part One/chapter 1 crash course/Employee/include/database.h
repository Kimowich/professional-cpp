#pragma once
#include <employee.h>
#include <vector>
#include <stdexcept>

namespace Records{
    const int firstEmployeeNumber{1'000};

    class DataBase
    {
    private:
        std::vector<Employee> employees;
        int nextEmployeeNumber{firstEmployeeNumber};
    public:
        DataBase(/* args */);
        ~DataBase();
        Employee& addEmployee(  const std::string firstName,
                                const std::string lastName);
        Employee& getEmployee(int employeeNumber);
        Employee& getEmployee(  const std::string firstName,
                                const std::string lastName);
        void displayAll() const;
        void displayCurrent() const;
        void displayFormer() const;
    };
    

    
}