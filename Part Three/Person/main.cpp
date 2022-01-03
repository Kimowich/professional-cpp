#include <iostream>
#include <Person.h>
#include <memory>
/*
Exericise 8-1
Implement a Person class storing a first and last name as data members. 
Add a single constructor accepting two parameters, the first and last name. 
Provide appropriate getters and setters. 
Write a small main() function to test your implementation
by creating a Person object on the stack and on the free store.

Gregoire, Marc. Professional C++ (p. 282). Wiley. Kindle Edition. 

Exercise 8-2
With the set of member functions implemented in Exercise 8-1, 
the following line of code does not compile:  
    Person phoneBook[3]; 
Can you explain why this does not compile? 
Modify the implementation of your Person class to make this work.

Gregoire, Marc. Professional C++ (p. 282). Wiley. Kindle Edition. 

Exercise 8-3
Add the following methods to your Person class implementation: 
    a copy constructor, 
    an assignment operator, 
    and a destructor. 
In all of these methods, implement what you think is necessary, 
and additionally, output a line of text to the console so 
you can trace when they are executed. 
Modify your main() function to test these new methods. 
Note: technically, these new methods are not strictly
required for this Person class, because the compiler-generated 
versions are good enough, but this exercise is to practice writing them.

Gregoire, Marc. Professional C++ (p. 282). Wiley. Kindle Edition.  
*/

int main(int, char**) {
    /* Exercise 8-1 */
    Person phoneBookStack{"Jim","Vild"};
    std::cout << "Person 1: " << phoneBookStack.getFirstName() << " " << phoneBookStack.getLastName() << "\n";

    auto phoneBookFreestore{std::make_unique<Person>("John","Doe")};
    std::cout << "Person 2: " << phoneBookFreestore->getFirstName() << " " << phoneBookFreestore->getLastName() << "\n";
    
    /* Exercise 8-2 */
    Person phoneBook[3];

    /* Exercise 8-4 */
    std::cout << "Person 1: " 
        << phoneBookStack.getFirstName() << " " 
        << phoneBookStack.getLastName() << " "
        << phoneBookStack.getinitials() << "\n";
    return EXIT_SUCCESS;
}
