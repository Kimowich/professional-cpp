#include "Director.h"

std::string HR::Director::toString() const
{
	return std::format("Director data: {} ", Employee::toString());
}
