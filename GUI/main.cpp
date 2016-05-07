#include "dashboard.h"
#include <QApplication>
#include "addexpense.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dashboard w;
    w.show();
    //AddExpense e;
    //e.show();

    return a.exec();
}
