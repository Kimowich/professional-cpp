#include <userinterface.h>

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
}

int UserInterface::displayMenu()
{
    int selection{0};
    std::cout << std::endl;
    std::cout << "Employee Databse" << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << "1) Hire a new employee" << std::endl;
    std::cout << "2) Fire an employee" << std::endl;
    std::cout << "3) Promote an employee" << std::endl;
    std::cout << "4) List all employees" << std::endl;
    std::cout << "5) List all current employees" << std::endl;
    std::cout << "6) List all former employees" << std::endl;
    std::cout << "0) Quit" << std::endl;
    std::cout << std::endl;
    std::cout << "--->";
    std::cin >> selection;
    return selection;
}

void UserInterface::doHire(Records::DataBase& db)
{
    std::string firstName{""};
    std::string lastName{""};

    std::cout << "First name?";
    std::cin >> firstName;

    std::cout << "Last name?";
    std::cin >> lastName;

    auto& employee{db.addEmployee(firstName,lastName)};
    std::cout << "Hired employee " << firstName << " " << lastName 
                << " with employee number " << employee.getEmployeeNumber() << std::endl;
}

void UserInterface::doFire(Records::DataBase& db)
{
    int employeeNumber;
    std::cout << "Employee number?";
    std::cin >> employeeNumber;

    try
    {
        auto& employee{db.getEmployee(employeeNumber)};
        employee.fire();
        std::cout << "Employee " << employeeNumber << " terminated." << std::endl;
    }
    catch(const std::logic_error& e)
    {
        std::cerr << "Unable to terminate employee: "<< employeeNumber << e.what() << '\n';
    }
}

void UserInterface::doPromote(Records::DataBase& db)
{
    int employeeNumber;
    std::cout << "Employee number?";
    std::cin >> employeeNumber;
    int raiseAmount;
    std::cout << "How much of a raise?";
    std::cin >> raiseAmount;

    try
    {
        auto& employee{db.getEmployee(employeeNumber)};
        employee.promote(raiseAmount);
    }
    catch(const std::logic_error& e)
    {
        std::cerr << "Unable to promote employee " << employeeNumber << e.what() << '\n';
    }
    
}