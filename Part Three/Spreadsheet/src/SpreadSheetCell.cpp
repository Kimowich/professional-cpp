#include "SpreadSheetCell.h"

SpreadSheetCell::SpreadSheetCell(double initialValue) : value(initialValue)
{
	//std::cout << "Object Constructed\n";
	set(initialValue);
}

SpreadSheetCell::SpreadSheetCell(std::string_view initialValue)
{
	//std::cout << "Object Constructed\n";
	set(initialValue);
}

SpreadSheetCell operator+(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return SpreadSheetCell{ lhs.getValue() + rhs.getValue() };
}

SpreadSheetCell operator-(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return SpreadSheetCell{ lhs.getValue() - rhs.getValue() };
}
SpreadSheetCell operator*(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return SpreadSheetCell{ lhs.getValue() * rhs.getValue() };
}

SpreadSheetCell operator/(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	if (rhs.getValue() == 0)
	{
		throw std::invalid_argument{ "Dividing by zero" };
	}
		
	return SpreadSheetCell{ lhs.getValue() / rhs.getValue() };
}
bool operator==(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{

	return (lhs.getValue() == rhs.getValue());
}
bool operator<(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return (lhs.getValue()<rhs.getValue());
}
bool operator>(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return (lhs.getValue()>rhs.getValue());
}
bool operator!=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return !(lhs.getValue()==rhs.getValue());
}
bool operator<=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return !(lhs<rhs);
}
bool operator>=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return !(lhs>rhs);
}
SpreadSheetCell::~SpreadSheetCell()
{
}

/* This operator can be omitted, since the compiler creates it. */
SpreadSheetCell& SpreadSheetCell::operator=(const SpreadSheetCell& rhs)
{
	if (this == &rhs)
	{
		value = rhs.value;
		return *this;
	}
}

SpreadSheetCell& SpreadSheetCell::operator+=(const SpreadSheetCell& rhs)
{
	set(getValue() + rhs.getValue());
	return *this;
}

SpreadSheetCell& SpreadSheetCell::operator-=(const SpreadSheetCell& rhs)
{
	set(getValue() - rhs.getValue());
	return *this;
}

SpreadSheetCell& SpreadSheetCell::operator*=(const SpreadSheetCell& rhs)
{
	set(getValue() * rhs.getValue());
	return *this;
}

SpreadSheetCell& SpreadSheetCell::operator/=(const SpreadSheetCell& rhs)
{
	if (rhs.getValue() == 0)
		throw std::invalid_argument("Dividing by zero");
	set(getValue() + rhs.getValue());
	return *this;
}

void SpreadSheetCell::set(double value)
{
	this->value = value;
}

double SpreadSheetCell::getValue() const
{
	return this->value;
}

void SpreadSheetCell::set(std::string_view value)
{
	this->value = stringToDouble(value);
}

std::string SpreadSheetCell::getString() const
{
	return doubleToString(this->value);
}

void SpreadSheetCell::setColor(const Color color)
{
	this->color = color;
}

SpreadSheetCell::Color SpreadSheetCell::getColor() const
{
	return this->color;
}

std::string SpreadSheetCell::doubleToString(double value) const
{
	return std::to_string(value);
}

double SpreadSheetCell::stringToDouble(std::string_view value) const
{
	double number{ 0 };
	// Does not work in C++ 17
	//std::from_chars(value.data(),value.data()+value.size(),number);

	//C++ 17 solution
	return std::stod(value.data());
	//return number;
}
