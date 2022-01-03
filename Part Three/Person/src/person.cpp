#include<person.h>

/* Exercise 8-1 */
/*
Person::Person(std::string_view firstName, std::string_view lastName)
{
    this->firstName = firstName;
    this->lastName = lastName;
}
*/
void Person::setFirstName(std::string_view firstName)
{
    this->firstName = firstName;
}

std::string Person::getFirstName() const
{
    return this->firstName;
}

void Person::setLastname(std::string_view lastName)
{
    this->lastName = lastName;
}

std::string Person::getLastName() const
{
    return this->lastName;
}

/* Exercise 8-3 */

Person::~Person()
{
}

Person& Person::operator=(const Person& rhs)
{
    return *this;
}

/* Exercise 8-4 */
Person::Person(std::string_view firstName, std::string_view lastName)
{
    std::string firstInitial{};
    std::string lastInitial{};
    firstInitial = firstName.at(0);
    lastInitial = lastName.at(0);
    this->firstName = firstName;
    this->lastName = lastName;
    this->initials = firstInitial+"."+lastInitial;
}

Person::Person(
    std::string_view firstName, 
    std::string_view lastName, 
    std::string_view initials)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->initials = initials;
}

void Person::setInitials(std::string_view initials)
{
    this->initials = initials;
}

std::string Person::getinitials() const
{
    return this->initials;
}