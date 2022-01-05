#pragma once

#include<iostream>
#include<string>
#include<string_view>
#include<charconv>

class SpreadSheetCell
{
	enum class Color { Red = 1, Green, Blue, Yellow };

private:
	/* data */
	double value{ 0.0 };
	Color color{ Color::Red };
public:
	SpreadSheetCell() = default;
	SpreadSheetCell(double initialValue);
	explicit SpreadSheetCell(std::string_view initialValue);

	~SpreadSheetCell();

	SpreadSheetCell& operator=(const SpreadSheetCell& rhs);
	friend SpreadSheetCell operator+(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
	friend SpreadSheetCell operator-(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
	friend SpreadSheetCell operator*(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
	friend SpreadSheetCell operator/(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);

	SpreadSheetCell& operator+=(const SpreadSheetCell& rhs);
	SpreadSheetCell& operator-=(const SpreadSheetCell& rhs);
	SpreadSheetCell& operator*=(const SpreadSheetCell& rhs);
	SpreadSheetCell& operator/=(const SpreadSheetCell& rhs);

	friend bool operator==(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
	friend bool operator<(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
	friend bool operator>(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
	friend bool operator!=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
	friend bool operator<=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
	friend bool operator>=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);

	void set(double value);
	void set(int value) = delete;
	void set(std::string_view value);
	void setColor(const Color color);

	double getValue() const;
	std::string getString() const;
	SpreadSheetCell::Color getColor() const;

	std::string doubleToString(double value) const;
	double stringToDouble(std::string_view value) const;
};
