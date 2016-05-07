#ifndef ADDEXPENSE_H
#define ADDEXPENSE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QString>
#include <QDateTime>
#include <QComboBox>

class AddExpense : public QWidget
{
    Q_OBJECT
public:
    explicit AddExpense(QWidget *parent = 0);
    ~AddExpense();

private:
    QComboBox *categoryBox;
    QComboBox *DateBox;
    QComboBox *DateDayBox;
    QComboBox *DateYearBox;

    QLabel* userDate;
    QLabel* todaysDate;
    QLineEdit* userLineDate;

    QLabel* userCategory;
    QLineEdit* userLineCat;

    QLabel* userPrice;
    QLineEdit* userLinePrice;

    QComboBox *PaymentBox;

    QLabel* userPayment;
    QLineEdit* userLinePayment;

    QLabel* userDescription;
    QLineEdit* userLineDescription;

    QPushButton* addButton;
    QPushButton* cancelButton;

signals:

public slots:
    void OnCancel();
    void OnAdd();
};

#endif // ADDEXPENSE_H
