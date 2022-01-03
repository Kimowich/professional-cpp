#pragma once
#include <database.h>
#include <employee.h>
#include <iostream>

class UserInterface
{
private:
    /* data */
public:
    UserInterface(/* args */);
    ~UserInterface();
    int displayMenu();
    void doHire(Records::DataBase& db);
    void doFire(Records::DataBase& db);
    void doPromote(Records::DataBase& db);
};