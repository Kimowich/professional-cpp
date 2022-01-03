#include <employee.h>
#include <database.h>
#include <userinterface.h>

int main() {
    UserInterface ui;
    Records::DataBase employeeDb;
    bool done{false};
    while (!done)
    {
        int selection{ui.displayMenu()};
        switch (selection)
        {
        case 0:
            done=true;
            break;
        case 1:
            ui.doHire(employeeDb);
            break;
        case 2:
            ui.doFire(employeeDb);
            break;
        case 3:
            ui.doPromote(employeeDb);
            break;
        case 4:
            employeeDb.displayAll();
            break;
        case 5:
            employeeDb.displayCurrent();
            break;
        case 6:
            employeeDb.displayFormer();
            break;
        default:
            std::cerr << "Unknown command." << std::endl;
            break;
        }
    }
}
