#include <iostream>
#include <format>
#include "Derived.h"
int main()
{
	// static cast
	int i{ 3 };
	int j{ 4 };
	double result{ static_cast<double>(i) / j };
	std::cout << std::format("result is cast to double: {}, but this is not: {}", result, i/j) <<std::endl;
	// result is cast to double: 0.75, but this is not: 0

	// Downcast 
	Base* b{ nullptr };
	Derived* d{ new Derived };
	b = d; // going up in hierarchy;
	// d = b; // this is not allowed;
	d = static_cast<Derived*>(b); // need to use cast;

	Base base;
	Derived derived;
	Base& br{ derived };
	Derived& dr{ static_cast<Derived&>(br) };

	// reinterpret_cast
	class X
	{};
	class Y
	{};
	X x;
	Y y;

	X* xp{ &x };
	Y* yp{ &y };

	//xp = static_cast<X*>(yp); not allowed
	xp = reinterpret_cast<X*>(yp);

	void* p{ xp };

	xp = reinterpret_cast<X*>(p);

	X& xr{ x };
	Y& yr{ reinterpret_cast<Y&>(x) };
	return 0;
}