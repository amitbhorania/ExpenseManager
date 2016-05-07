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
    QComboBox *DateBox;
    QComboBox *DateDayBox;
    QComboBox *DateYearBox;
    QComboBox *categoryBox;
    QLabel* userDate;
    QLabel* todaysDate;
    QLineEdit* userLineDate;
    QComboBox *PaymentTypeBox;

    QLabel* userCategory;
    QLineEdit* userLineCat;

    QLabel* userPaymentType;
    QLineEdit* userLinePayment;

    QLabel* userPrice;
    QLineEdit* userLinePrice;

    QLabel* userPayment;

    QLabel* userDescription;
    QLineEdit* userLineDescription;

    QPushButton* addButton;
    QPushButton* cancelButton;

signals:

public slots:
    void OnCancel();
    void OnAdd();
};

#endif // ADDINCOME_H
