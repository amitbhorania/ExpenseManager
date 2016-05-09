#ifndef ADDINCOME_H
#define ADDINCOME_H

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

class AddIncome : public QWidget
{
    Q_OBJECT
public:
    explicit AddIncome(QWidget *parent = 0);
    ~AddIncome();

private:

    // Variables to Select the Date of Transaction
    QLabel* userDate;
    QComboBox *dateMonthBox;
    QComboBox *dateDayBox;
    QComboBox *dateYearBox;

    // Variables to Get Description of Transaction
    QLabel* description;
    QLineEdit* descriptionValue;

    // Variables to Select Transaction Category
    QLabel* category;
    QComboBox *categoryBox;

    // To get Transaction Amount
    QLabel* amount;
    QLineEdit* amountValue;

    // Variables for Source of Income
    QLabel* incomeSource;
    QComboBox* incomeSourceBox;

    // Buttons for Actions
    QPushButton* addButton;
    QPushButton* cancelButton;

public slots:
    void OnCancel();
    void OnAdd();
};

#endif // ADDINCOME_H
