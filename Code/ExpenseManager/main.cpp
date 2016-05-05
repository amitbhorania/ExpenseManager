//Author- Vrushali Gaikwad

#include "mainwindow.h"
#include "addexpense.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* mainWindow = new MainWindow();
    AddExpense* addexp = new AddExpense(mainWindow);
    addexp->show();
    //mainWindow->show();

    return a.exec();
}
