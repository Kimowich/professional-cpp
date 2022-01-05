#include "SpreadSheetCell.h"

int main(int, char**) {
    SpreadSheetCell a1{ 4.0 }, a2{ 5.0 };
    SpreadSheetCell a3{ a1 + a2 };
    a3 = a1 + 5.6;
    a3 = 5 + 4.5;
    return EXIT_SUCCESS;
}