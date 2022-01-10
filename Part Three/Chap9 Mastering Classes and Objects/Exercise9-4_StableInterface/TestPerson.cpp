#include "Person.h"
#include <format>
#include <iostream>
/* Exercise 8-4: Remove the copy constructor, assignment operator, and destructor from your Person class, 
because the default compiler-generated versions are exactly what you need for this simple class. 
Next, add a new data member to store the initials of a person, and provide a getter and setter. 
Add a new constructor that accepts three parameters, a first and last name, and a person's initials. 
Modify the original two-parameter constructor to automatically generate initials for a given first and last name, 
and delegate the actual construction work to the new three-parameter constructor.

Gregoire, Marc. Professional C++ (p. 282). Wiley. Kindle Edition.  */
int main()
{
	// stack person
	Person person{ "John", "Doe" };
	return 0;
}