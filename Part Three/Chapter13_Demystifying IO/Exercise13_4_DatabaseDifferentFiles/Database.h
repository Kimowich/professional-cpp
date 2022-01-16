#pragma once
#include "Person.h"
#include <vector>
#include <filesystem>
/* Contains a list of people in the database*/
class Database
{
public:
	Database() = default;
	~Database() = default;

	void add(const Person& person);
	void save(const std::filesystem::path fileName) const;
	void load(const std::filesystem::path fileName);
	void clear();
	void outputAll();

private:
	std::vector<Person> m_listOfPeople;
};

