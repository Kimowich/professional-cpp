#include <iostream>
#include <vector>

/*  Exercise 2-4: Write a program that asks the user to enter an unknown number of floating-point numbers 
    and stores all numbers in a vector. Each number should be typed followed by Enter. 
    Stop asking for more numbers when the user inputs the number 0. 
    To read a floating-point number from the console, use cin in the same way it was used in Chapter 1 to input integer values. 
    Format all numbers in a table with a couple of columns where each column formats a number in a different way. 
    Each row in the table corresponds to one of the inputted numbers.

    Gregoire, Marc. Professional C++ (p. 110). Wiley. Kindle Edition. 
*/

/* 
    Text formatting is not supported by gcc compiler (MinGW) 
*/

int main() {
    std::vector<float> numbers;
    float newNumber{1.0};
    while (newNumber>0)
    {
        std::cin >> newNumber;
        numbers.push_back(newNumber);
    }
    
    for (auto &&number : numbers)
    {
        std::cout << number;
    }
    
    return EXIT_SUCCESS;
}
