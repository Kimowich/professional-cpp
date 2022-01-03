#include <iostream>
#include <string>
/*  Write a program that asks the user for two strings and then prints them out in alphabetical order, 
    using the three-way comparison operator. 
    To ask the user for a string, you can use the std::cin stream, briefly introduced in Chapter 1.

    Gregoire, Marc. Professional C++ (p. 110). Wiley. Kindle Edition. 
*/

std::string getStringFromUser()
{
    std::string return_string;
    std::cout << "Enter a string: ";
    std::cin >> return_string;
    return return_string;
}

void printAlphabetical(std::string_view str1, std::string_view str2)
{
    // New C++20 feature, "spaceship" three-way comparison operator
    auto result{str1<=>str2};   
        
        if (result<0)
        {
            //std::cout << str1 << " smaller than " << str2;
            std::cout << str1 << "\n" << str2;
        }else if (result==0)
        {
            //std::cout << a << " equal to " << str2;
            std::cout << str1 << "\n" << str2;
        }else if (result>0)
        {
            //std::cout << str1 << " larger than " << str2;
            std::cout << str2 << "\n" << str1;
        }
}

int main() {
    std::string a{""};
    std::string b{""};

    a=getStringFromUser();
    b=getStringFromUser();

    printAlphabetical(a,b);
}
