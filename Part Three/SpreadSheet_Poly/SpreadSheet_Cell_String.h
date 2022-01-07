#pragma once
#include "SpreadSheet_Cell.h"
#include "SpreadSheet_Cell_Double.h"
#include <optional>

class SpreadSheet_Cell_String :
    public SpreadSheet_Cell
{
public:
    SpreadSheet_Cell_String() = default;
    SpreadSheet_Cell_String(const SpreadSheet_Cell_Double& cell) : m_value{ cell.getString() } {}
    void set(std::string_view value) override;
    std::string getString() const override;

    //friend SpreadSheetCell operator+(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
    friend SpreadSheet_Cell_String operator+(const SpreadSheet_Cell_String& lhs, const SpreadSheet_Cell_String& rhs);
private:
    std::optional<std::string> m_value;
};

