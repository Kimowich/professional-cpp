#include "Person.h"
#include "Employee.h"
#include "Manager.h"
#include "Director.h"
#include <format>
#include <iostream>
/* Exercise 10-1: 
Take the Person class from Exercise 9-2 and add a derived class called Employee. 
You can omit the overload of operator<=> from Exercise 9-2. 
The Employee class adds one data member, an employee ID. 
Provide an appropriate constructor. From Employee, derive two more classes called Manager and Director. 
Put all your classes, including the Person class, in a namespace called HR. 
Note that you can export everything in a namespace as follows:  
	export namespace HR {  }

Gregoire, Marc.Professional C++ (p. 395).Wiley.Kindle Edition. */


int main()
{
	HR::Person person{ "Spongebob","Squarepants" };
	HR::Employee employedPerson{ "Bob","Builder",1 };
	HR::Manager managerEmployee{ "Squidward", "Tentacles",2 };
	HR::Director directorEmployee{ "Eugene ", "Krabs", 3 };
	std::cout << person << std::endl;
	std::cout << employedPerson << std::endl;
	std::cout << managerEmployee << std::endl;
	std::cout << directorEmployee << std::endl;
	return 0;
}