#include<iostream>
#include<string>
#include<string_view>
#include<charconv>

class SpreadSheetCell
{
private:
    /* data */
    double value{0.0};
    std::string doubleToString(double value) const;
    double stringToDouble(std::string_view value) const;
public:
    /* Explicit constructor prevents myCell = "6"sv; */
    SpreadSheetCell()=default;
    explicit SpreadSheetCell(double initialValue);
    explicit SpreadSheetCell(std::string_view initialValue);
    // Copy Constructor
    SpreadSheetCell(const SpreadSheetCell& src);
   
    // Assignment operator
    SpreadSheetCell& operator=(const SpreadSheetCell& rhs);

    //TODO - Print operator <<


    ~SpreadSheetCell();

    void set(double value);
    void set(int value) = delete;
    double getValue() const;

    void set(std::string_view value);
    std::string getString() const;

    // Create a print function by overloading <<
};

/* can be defaulted in class 
SpreadSheetCell::SpreadSheetCell()
{
    //std::cout << "Object Constructed\n";
}
*/
SpreadSheetCell::SpreadSheetCell(double initialValue)
{
    //std::cout << "Object Constructed\n";
    set(initialValue);
}


/* ctor-initializer
SpreadSheetCell::SpreadSheetCell(double initialValue)//:value{initialValue}
{
    //std::cout << "Object Constructed\n";
    setValue(initialValue);
} */

/* Delagating Constructor
 * Only works if it is the only member-initialiser.
SpreadSheetCell::SpreadSheetCell(std::string_view initialValue):SpreadSheetCell{stringToDouble(initialValue)}
{

}
*/

SpreadSheetCell::SpreadSheetCell(std::string_view initialValue)
{
    //std::cout << "Object Constructed\n";
    set(initialValue);
}

SpreadSheetCell::~SpreadSheetCell()
{
}

/* This operator can be omitted, since the compiler creates it. */
SpreadSheetCell& SpreadSheetCell::operator=(const SpreadSheetCell& rhs)
{
    if(this==&rhs)
    {
        value = rhs.value;
        return *this;
    }
}

void SpreadSheetCell::set(double value)
{
    this->value=value;
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

std::string SpreadSheetCell::doubleToString(double value) const
{
    return std::to_string(value);
}

double SpreadSheetCell::stringToDouble(std::string_view value) const
{
    double number{0};
    // Does not work in C++ 17
    //std::from_chars(value.data(),value.data()+value.size(),number);

    //C++ 17 solution
    return std::stod(value.data());
    //return number;
}
