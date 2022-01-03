#include <SpreadSheet.h>
#include <vector>
void printSpreadSheet(SpreadSheet sheet){
    // This function deletes the data that s1 is pointing too
;
}

SpreadSheet createObject()
{
    return SpreadSheet{ 3,2 };
}

int main(int, char**) {
    std::vector<SpreadSheet> vec;
    for (size_t i = 0; i < 2; i++)
    {
        std::cout << "Iteration: " << i << std::endl;
        vec.push_back(SpreadSheet{ 100,100 });
        std::cout << std::endl;
    }

    SpreadSheet s1{ 2,3 };
    s1 = createObject();

    SpreadSheet s2{ 5,6 };
    s2 = s1;

    return EXIT_SUCCESS;
}