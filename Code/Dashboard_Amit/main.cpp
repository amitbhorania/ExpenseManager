#include "dashboard.h"
#include <QApplication>
#include "addexpense.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <direct.h>
#include <QDebug>

#define FILENAME    "ExpenseManager.csv"

// Global Variable to access the Data file
string dir;

string exePath() {
    char buffer[MAX_PATH];
    wchar_t *wString =  new wchar_t [MAX_PATH];
    GetModuleFileName( NULL, wString, MAX_PATH);
    wcstombs(buffer, wString, 500);
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Get the Current Directory and Add File Name to it
    dir = exePath() + "\\" + FILENAME;

    // Run the Dashboard
    Dashboard w;
    w.show();

    return a.exec();
}
