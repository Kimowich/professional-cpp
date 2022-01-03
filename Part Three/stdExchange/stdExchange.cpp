// stdExchange.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>

int main()
{
    // This function can help implement the move assignemnt operator.

    int a{ 11 };
    int b{ 22 };
    std::cout << "Before exchange: " << "a=" << a << " b=" << b << std::endl;
    int returnedValue{ std::exchange(a,b) };
    std::cout << "After exchange: " << "a = " << a << " b = " << b << std::endl;
    std::cout << "exchange returned: " << returnedValue << std::endl;
    return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
