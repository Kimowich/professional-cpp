#include "SpreadSheet_Cell_Double.h"

void SpreadSheet_Cell_Double::set(double value)
{
	m_value = value;
}

void SpreadSheet_Cell_Double::set(std::string_view value)
{
	m_value = stringToDouble(value);
}

std::string SpreadSheet_Cell_Double::getString() const
{
	return (m_value.has_value()?doubleToString(m_value.value()):"");
}

std::string SpreadSheet_Cell_Double::doubleToString(double value)
{
	return std::to_string(value);
}

double SpreadSheet_Cell_Double::stringToDouble(std::string_view value)
{
	double number{ 0 };
	return std::stod(value.data());
}