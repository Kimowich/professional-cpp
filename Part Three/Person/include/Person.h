#include<string>

class Person
{
private:
    /* data */
    std::string firstName{""};
    std::string lastName{""};
    std::string initials{""};
public:
    /* Exercise 8-1 */
    Person(std::string_view firstName, std::string_view lastName);
    

    void setFirstName(std::string_view firstName);
    std::string getFirstName() const;

    void setLastname(std::string_view lastName);
    std::string getLastName() const;

    /* Exercise 8-2 */
    Person() = default;

    /* Exercise 8-3 */
    // Copy operator
    Person(const Person& src);
    // assignment operator
    Person& operator=(const Person& rhs);
    // destructor
    ~Person();

    /* Exercise 8-4 */
    Person(std::string_view firstName, 
                    std::string_view lastName, 
                    std::string_view initials);
    void setInitials(std::string_view initials);
    std::string getinitials() const;
};


