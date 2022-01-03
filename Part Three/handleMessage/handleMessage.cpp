#include<string>
#include<iostream>

void helper(std::string&& message)
{
	//The helper() function needs an rvalue reference, while handleMessage() passes message, which has a name, so it's an lvalue, causing a compilation error. The correct way is to use std::move():

	//Gregoire, Marc.Professional C++ (p. 297).Wiley.Kindle Edition.
}

// lValue reference
void handleMessage(std::string& message)
{
	std::cout << "lValue reference: " << message << std::endl;
}

// rValue reference
void handleMessage(std::string&& message)
{
	std::cout << "rValue reference: " << message << std::endl;
	helper(std::move(message));
}

int main()
{
	std::string a{ "Hello" };
	//handleMessage(a);
	std::string b{ "World" };
	handleMessage(a + b);
	handleMessage(std::move(b));
	return 0;
}