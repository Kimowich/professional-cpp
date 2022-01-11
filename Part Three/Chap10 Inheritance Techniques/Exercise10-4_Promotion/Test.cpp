#include "Person.h"
#include "Employee.h"
#include "Manager.h"
#include "Director.h"
#include <format>
#include <iostream>
#include <vector>
#include <memory>
/* Exercise 10-3: 
Practise polymorphic behavior of the classes in your Person hierarchy from Exercise 10-2. 
Define a vector to store a mix of employees, managers, and directors, and fill it with some test data. 
Finally, use a single range-based for loop to call toString() on all of the elements in the vector.

Gregoire, Marc. Professional C++ (p. 395). Wiley. Kindle Edition.  */


int main()
{
	HR::Employee employee{ "Spongebob","Squarepants", 100 };
	std::cout << employee << std::endl;

	// promote to manager;
	HR::Manager manager{ employee };
	std::cout << manager << std::endl;

	return 0;
}