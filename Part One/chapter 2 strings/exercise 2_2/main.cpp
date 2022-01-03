#include <iostream>
#include <fstream>
#include <string>

/*  Exercise 2-2: Write a program that asks the user for a source string (= haystack), 
    a string to find (= needle) in the source string, and a replacement string. 
    Write a function with three parameters—the haystack, needle, 
    and replacement string—that returns a copy of the haystack with all needles replaced with the replacement string. 
    Use only std::string, no string_view. What kind of parameter types will you use and why? 
    Call this function from main() and print out all the strings for verification.

    Gregoire, Marc. Professional C++ (p. 110). Wiley. Kindle Edition. 
*/

std::string replaceAllNeedlesInHaystack(std::string& haystack, const std::string& needle, const std::string& replace)
{
    size_t pos;
    do
    {
        pos = haystack.find(needle);
        if (pos!=std::string::npos)
        {
            haystack.replace(pos,needle.size(),replace);
        }
    } while (pos!=std::string::npos);
    
    return haystack;
}

int main() {
    std::string haystack{""};
    std::string needle{""};
    std::string replaceString{""};

    std::getline(std::cin, haystack);
    std::getline(std::cin, needle);
    std::getline(std::cin, replaceString);

    std::cout << replaceAllNeedlesInHaystack(haystack,needle,replaceString);    
    
}
