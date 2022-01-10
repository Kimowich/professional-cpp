#include <iostream>
#include <string>

class Dog
{
public:
	virtual void bark() {
		std::cout << "Woof!" << std::endl;
	}
	virtual void eat() { 
		std::cout << "The dog ate." << std::endl; 
	}
};

class Bird
{
public:
	virtual void chirp() {
		std::cout << "Chirp!" << std::endl;
	}
	virtual void eat() {
		std::cout << "The bird ate." << std::endl;
	}
};

class DogBird : public Dog, public Bird
{
	void eat() override
	{
		Dog::eat(); // overrides the eat method of the parent classes;
	}
};

int main()
{
	DogBird chimera;
	chimera.bark();
	chimera.chirp();
	//chimera.eat(); // cannot be done.
	dynamic_cast<Dog&>(chimera).eat(); // dynamic cast way, with reference to dog class; 
	chimera.Dog::eat(); // disambigues syntax
	dynamic_cast<Bird&>(chimera).eat(); // dynamic cast way, with reference to dog class; However, this does not work if eat is overriden in derived class
	chimera.Bird::eat(); // disambigues syntax
	return 0;
}