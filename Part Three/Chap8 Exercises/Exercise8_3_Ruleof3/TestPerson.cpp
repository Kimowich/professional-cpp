#include "Person.h"
#include <format>
#include <iostream>
/* Exercise 9-1: Take your implementation of the Person class from Exercise 8-3 and adapt it to pass strings in the most optimal way you can think of. 
Additionally, add a move constructor and move assignment operator to it. 
In both methods, write a message to the console so you can track when they get called. 
Implement any additional methods you need for implementing the move methods and for improving the implementation of other methods from Exercise 8-3 
to avoid code duplication. Modify main() to test your methods.

Gregoire, Marc. Professional C++ (p. 335). Wiley. Kindle Edition.  */

/*	Move Semantics:
	Pass strings optimal way - string_view by value is pretty optimal 
	Implement Move construtor
	Implement Move assignment operator 
	Write a message to console when each method gets called	*/

int main()
{
	// stack person
	Person stackPerson{ "Bob", "Builder" };


	return 0;
}