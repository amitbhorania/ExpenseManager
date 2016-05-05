//Author- Vrushali Gaikwad

#include "mainwindow.h"
#include "Adding.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* mainWindow = new MainWindow();
    Adding* add = new Adding(mainWindow);
    add->show();
    //mainWindow->show();

    return a.exec();
}
