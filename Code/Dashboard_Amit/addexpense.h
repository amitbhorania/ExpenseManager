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
    // Variables to get Date of Transaction
    QLabel* userDate;
    QComboBox *dateMonthBox;
    QComboBox *dateDayBox;
    QComboBox *dateYearBox;

    // Variables to get Transaction Description
    QLabel* description;
    QLineEdit* descriptionValue;

    // Variables to get Transaction Category
    QLabel* category;
    QComboBox *categoryBox;

    // Variables to get Amount
    QLabel* amount;
    QLineEdit* amountValue;

    // Variables to get Payment Type
    QLabel* paymentType;
    QComboBox *paymentBox;

    // Action Buttons
    QPushButton* addButton;
    QPushButton* cancelButton;

public slots:
    void OnCancel();
    void OnAdd();
};

#endif // ADDEXPENSE_H
