#ifndef MENU_H
#define MENU_H

class Menu
{
    int choice;
public:
    // Constructor
    Menu();

    // Methods
    void show();
    void getchoice();
    void performAction();
    char askForMoreAction();
};

#endif // MENU_H
