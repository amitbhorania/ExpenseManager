#include "menu.h"
#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    char moreAction = 'y';

    QCoreApplication a(argc, argv);
    cout << "\n\nExpense Manager Application";
    cout << "\n===========================";

    Menu menu;

    menu.show();
    while(moreAction == 'y' || moreAction == 'Y') {
        menu.getchoice();
        menu.performAction();
        moreAction = menu.askForMoreAction();
    }

    cout << "Application Completed";

    return a.exec();
}
