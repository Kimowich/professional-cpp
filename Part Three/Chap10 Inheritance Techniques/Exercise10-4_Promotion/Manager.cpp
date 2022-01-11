#include "Manager.h"

std::string HR::Manager::toString() const
{
    return std::format("Manager data: \n\t {}", Employee::toString());
}
