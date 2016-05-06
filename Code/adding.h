#ifndef ADDING_H
#define ADDING_H


#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QString>
#include <QDateTime>
#include <QComboBox>
//Author - Vrushali Gaikwad

class Adding : public QDialog
{
    Q_OBJECT

public:
    Adding(QWidget* parent = 0);
    ~Adding();

private slots:
    void OnCancel();
    void OnAdd();


private:


    QComboBox *categoryBox;
    QLabel* userDate;
    QLabel* todaysDate;
    QLineEdit* userLineDate;

    QLabel* userCategory;
    QLineEdit* userLineCat;

    QLabel* userPrice;
    QLineEdit* userLinePrice;

    QLabel* userPayment;
    QLineEdit* userLinePayment;
    
    QPushButton* addButton;
    QPushButton* cancelButton;


};
#endif // ADDING_H
