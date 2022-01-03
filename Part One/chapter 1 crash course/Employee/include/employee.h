#pragma once
#include <string>
#include <iostream>
namespace Records{
    const int defaultStartingSalary{30000};
    const int defaultRaiseAndDemeritAmount{1000};

    class Employee
    {
    private:
        std::string firstName;
        std::string lastName;
        int employeeNumber{-1};
        int salary{defaultStartingSalary};
        bool hired{false};
    public:
        Employee(const std::string& firstName, const std::string& lastName);
        ~Employee();

        void promote(int raiseAmount = defaultRaiseAndDemeritAmount);
        void demote(int demeritAmount = defaultRaiseAndDemeritAmount);
        void hire();
        void fire();
        void display() const;
        void setFirstName(const std::string& firstName);
        std::string getFirstName() const;
        void setLastname(const std::string& lastName);
        std::string getLastName() const;
        void setEmployeeNumber(int employeeNumber);
        int getEmployeeNumber() const;
        void setSalary(int newSalary);
        int getSalary() const;
        bool isHired() const;
        //TODO - Implement more employee data, vacation, total time employed...
    };    
}