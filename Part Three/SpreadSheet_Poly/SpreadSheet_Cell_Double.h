#pragma once
#include "SpreadSheet_Cell.h"
#include <optional>

class SpreadSheet_Cell_Double :
    public SpreadSheet_Cell
{
public:
    
    virtual void set(double value);
    void set(std::string_view value) override;
    std::string getString() const override;
private:
    static std::string doubleToString(double value);
    static double stringToDouble(std::string_view value);    
    std::optional<double> m_value;
};

