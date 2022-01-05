#include "SpreadSheetCell.h"

int main(int, char**) {
    SpreadSheetCell a1{ 4.0 }, a2{ 5.0 };
    SpreadSheetCell a3{ a1 + a2 };
    a3 = a1 + 5.6;
    a3 = 5 + 4.5;
    a3 = 5 - 4.5;
    a3 += 4.0;
    a3 /= 3;
    a3 -= 1;
    a3 *= 2;
    bool b{ a3 == a1 };
    b = a1 < a3 ;
    b = a1 <= a3;
    b = a1 >= a3;
    b = a1 != a3;
    return EXIT_SUCCESS;
}