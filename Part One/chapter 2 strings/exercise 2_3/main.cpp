#include <iostream>
#include <fstream>
#include <string>

/*  Exercise 2-3: Modify the program from Exercise 2-2 and use std::string_view on as many places as you can.

    Gregoire, Marc. Professional C++ (p. 110). Wiley. Kindle Edition. 
*/

std::string replaceAllNeedlesInHaystack(std::string& haystack, std::string_view needle, std::string_view replace)
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
