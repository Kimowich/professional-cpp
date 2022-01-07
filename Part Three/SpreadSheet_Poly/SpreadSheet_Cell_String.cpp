#include "SpreadSheet_Cell_String.h"

void SpreadSheet_Cell_String::set(std::string_view value)
{
	m_value = value;
}

std::string SpreadSheet_Cell_String::getString() const
{
	return m_value.value_or("");
}

SpreadSheet_Cell_String operator+(const SpreadSheet_Cell_String& lhs, const SpreadSheet_Cell_String& rhs)
{
	SpreadSheet_Cell_String cell;
	cell.set(lhs.getString() + rhs.getString());
	return cell;
}
