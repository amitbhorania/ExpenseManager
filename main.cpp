#include "mainwindow.h"
#include "logino.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* mainWindow = new MainWindow();
    Logino* logino = new Logino(mainWindow);
    logino->show();
    mainWindow->show();

    return a.exec();
}
