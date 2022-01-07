#include "SpreadSheet_Cell_String.h"
#include "SpreadSheet_Cell_Double.h"
#include <vector>
#include <memory>
#include <iostream>
#include <format>

int main()
{
	//SpreadSheet_Cell cell // is not allowed;
	std::vector<std::unique_ptr<SpreadSheet_Cell>> cellArray;
	cellArray.push_back(std::make_unique<SpreadSheet_Cell_String>());
	cellArray.push_back(std::make_unique<SpreadSheet_Cell_String>());
	cellArray.push_back(std::make_unique<SpreadSheet_Cell_Double>());

	cellArray[0]->set("hello");
	cellArray[1]->set("10");
	cellArray[2]->set("18");

	std::cout << std::format("Vector: [{},{},{}]", cellArray[0]->getString(), cellArray[1]->getString(), cellArray[2]->getString())<<std::endl;

	SpreadSheet_Cell_Double celldouble;
	celldouble.set(8.4);
	SpreadSheet_Cell_String result{ celldouble + celldouble };

	return 0;
}