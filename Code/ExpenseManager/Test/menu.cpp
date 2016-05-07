#include "menu.h"
#include "transaction.h"
#include <iostream>
using namespace std;

// Constructor
Menu::Menu()
{
    // Nothing to Do
}

// Method to show the Menu of Actions
void Menu::show()
{
    cout << "\n\nExpense Manager";
    cout << "\n===============";
    cout << "\n\t1. Add Transaction";
    cout << "\n\t2. View Transaction";
    cout << "\n\t3. Plot Graph";
    cout << "\n\t4. Show Income Expense Figures";
    cout << "\n\t5. Reset User Account";
}

void Menu::getchoice()
{
    cout << "\n\nPlease Enter Your Choice....";
    cin >> choice;
}

void Menu::performAction()
{
    switch(choice) {
    case 1:
    {
        cout << "\nChoice 1 Add Transaction Selected";
        Transaction entry1(EXPENSE, 100, "Bus Fare", TRAVELLING, DEBIT_CARD, 4, 24, 2016);
        Transaction entry2;
        entry1.sendTransactionToDatabase();
        entry2.sendTransactionToDatabase();
    }
        break;

    case 2:
    {
        cout << "\nChoice 2 View Transaction Selected";
        Transaction entry1;
        Transaction entry2;
        entry1.getTransactionDetails();
        //entry2.getTransactionDetails();
    }
        break;
    case 3:
        cout << "\nChoice 3 Plot Graph Selected";
        break;
    case 4:
        cout << "\nChoice 4 Show Income Expense Figures Selected";
        break;
    case 5:
        cout << "\nChoice 5 Reset User Account Selected";
        break;
    default:
        cout << "\nInvalid Choice";
        break;
    }
}

char Menu::askForMoreAction()
{
    char moreAction;

    cout << "\nDo you want to perform any More Actions?";
    cout << "\nPress 'y' or 'n'....";
    cin >> moreAction;

    return moreAction;
}
