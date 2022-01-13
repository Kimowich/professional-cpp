#include "Person.h"
#include <format>
#include <iostream>
/* Exercise 13-1: 
Let's revisit the Person class you developed during exercises in previous chapters. 
Take your implementation from Exercise 9-2 and add an output() method that writes the details of a person to the standard output console.

Gregoire, Marc. Professional C++ (p. 494). Wiley. Kindle Edition.  */


int main()
{
	Person person{ "Spongebob","Squarepants" };
	
	person.output();

	return 0;
}