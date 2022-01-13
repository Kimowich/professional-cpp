#pragma once
#include "Person.h"
#include <vector>
/* Contains a list of people in the database*/
class Database
{
public:
	Database() = default;
	~Database() = default;

	void add(const Person& person);
	void save(const std::string_view fileName);
	void load(const std::string_view fileName);
	void clear();
	void outputAll();

private:
	std::vector<Person> listofPeople;
};

