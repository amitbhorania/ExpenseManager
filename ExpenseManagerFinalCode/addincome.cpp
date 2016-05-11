/*\file	addincome.cpp
*
* \brief	Add Income Source file to Display Add Income Window
*
* Revision History  :
*   Date            Author                  Change(Describe the changes made)
*   05.01.2016      Vrushali Gaikwad        Created File and added basic Class defines
*   05.03.2016      Vrushali Gaikwad        Added Code to show GUI of Income Window
*   05.06.2016      Vrushali Gaikwad        Added Code to connect Buttons with actions
*   05.06.2016      Amit & Vrushali         Changes According to Integration of GUI, Backend and Database
*   05.08.2016      Amit Bhorania           Code Clean Up
*/

#include "addincome.h"
#include "transaction.h"
#include "enums.h"
#include "dashboard.h"

// Add Combo Boxes and LineEdits to Display Add Income Window to User
AddIncome::AddIncome(QWidget *parent) : QWidget(parent)
{
    // Set Window Appearance
    setFixedSize(300, 200);
    setWindowTitle("Add Income");

    // Select Date of Transaction
    userDate = new QLabel("Date:");

    dateMonthBox = new QComboBox();
    dateMonthBox->addItem("Jan");
    dateMonthBox->addItem("Feb");
    dateMonthBox->addItem("Mar");
    dateMonthBox->addItem("Apr");
    dateMonthBox->addItem("May");
    dateMonthBox->addItem("Jun");
    dateMonthBox->addItem("Jul");
    dateMonthBox->addItem("Aug");
    dateMonthBox->addItem("Sep");
    dateMonthBox->addItem("Oct");
    dateMonthBox->addItem("Nov");
    dateMonthBox->addItem("Dec");

    dateDayBox = new QComboBox();
    dateDayBox->addItem("1");
    dateDayBox->addItem("2");
    dateDayBox->addItem("3");
    dateDayBox->addItem("4");
    dateDayBox->addItem("5");
    dateDayBox->addItem("6");
    dateDayBox->addItem("7");
    dateDayBox->addItem("8");
    dateDayBox->addItem("9");
    dateDayBox->addItem("10");
    dateDayBox->addItem("11");
    dateDayBox->addItem("12");
    dateDayBox->addItem("13");
    dateDayBox->addItem("14");
    dateDayBox->addItem("15");
    dateDayBox->addItem("16");
    dateDayBox->addItem("17");
    dateDayBox->addItem("18");
    dateDayBox->addItem("19");
    dateDayBox->addItem("20");
    dateDayBox->addItem("21");
    dateDayBox->addItem("22");
    dateDayBox->addItem("23");
    dateDayBox->addItem("24");
    dateDayBox->addItem("25");
    dateDayBox->addItem("26");
    dateDayBox->addItem("27");
    dateDayBox->addItem("28");
    dateDayBox->addItem("29");
    dateDayBox->addItem("30");
    dateDayBox->addItem("31");

    dateYearBox = new QComboBox();
    dateYearBox->addItem("2010");
    dateYearBox->addItem("2011");
    dateYearBox->addItem("2012");
    dateYearBox->addItem("2013");
    dateYearBox->addItem("2014");
    dateYearBox->addItem("2015");
    dateYearBox->addItem("2016");
    dateYearBox->addItem("2017");
    dateYearBox->addItem("2018");
    dateYearBox->addItem("2019");
    dateYearBox->addItem("2020");

    // Get the Transaction Description from User
    description = new QLabel("Description:");
    descriptionValue = new QLineEdit();

    // Transaction Category Display
    category = new QLabel("Category:");

    categoryBox = new QComboBox();
    categoryBox->addItem("Friend");
    categoryBox->addItem("Salary");
    categoryBox->addItem("Pension");
    categoryBox->addItem("Other");

    // Get Amount of Transaction
    amount = new QLabel("Amount:");
    amountValue = new QLineEdit();

    // Get Source of Income
    incomeSource = new QLabel("Source of Income:");
    incomeSourceBox = new QComboBox();
    incomeSourceBox->addItem("Cash");
    incomeSourceBox->addItem("Check");
    incomeSourceBox->addItem("Online Banking");
    incomeSourceBox->addItem("Other");

    // Add Button to Store the Transaction
    addButton = new QPushButton("ADD");

    // Cancel Button to Cancel the Transaction
    cancelButton = new QPushButton("CANCEL");

    // Layouts
    QVBoxLayout* vbox = new QVBoxLayout(this);
    QHBoxLayout* hbox1 = new QHBoxLayout();
    QHBoxLayout* hbox2 = new QHBoxLayout();
    QHBoxLayout* hbox3 = new QHBoxLayout();
    QHBoxLayout* hbox4 = new QHBoxLayout();
    QHBoxLayout* hbox5 = new QHBoxLayout();
    QHBoxLayout* hbox6 = new QHBoxLayout();

    hbox1 -> addWidget(userDate,1);
    hbox1 -> addWidget(dateMonthBox,1);
    hbox1 -> addWidget(dateDayBox,1);
    hbox1 -> addWidget(dateYearBox,1);

    hbox2 -> addWidget(description,1);
    hbox2 -> addWidget(descriptionValue,3);

    hbox3 -> addWidget(category,1);
    hbox3 -> addWidget(categoryBox,3);

    hbox4 -> addWidget(amount,1);
    hbox4 -> addWidget(amountValue,3);

    hbox5 -> addWidget(incomeSource,1);
    hbox5 -> addWidget(incomeSourceBox,3);

    hbox6 -> addWidget(addButton,1,Qt::AlignCenter);
    hbox6 -> addWidget(cancelButton,1,Qt::AlignCenter);

    vbox->addLayout(hbox1);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox3);
    vbox->addLayout(hbox4);
    vbox->addLayout(hbox5);
    vbox->addLayout(hbox6);
    vbox->setSpacing(15);

    setLayout(vbox);

    // Connect Signals with Action Functions
    connect(addButton, SIGNAL(clicked()), this, SLOT(OnAdd()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(OnCancel()));
}

// Action Function for Calcel Button
void AddIncome::OnCancel()
{
    // Close Window
    this->close();
}

// Action Function for Add Button
void AddIncome::OnAdd()
{
    int monthChoice = dateMonthBox->currentIndex() + 1;
    int dayChoice = dateDayBox->currentIndex() + 1;
    int yearChoice = dateYearBox->currentIndex() + 2010;
    QString des = descriptionValue->text();
    int catChoice = categoryBox->currentIndex() + MAX_EXPENSECATEGORY + 1;
    QString price = amountValue->text();
    int incomeSourceChoice = incomeSourceBox->currentIndex();

    // Change Value for "Other" according to enum
    if(incomeSourceChoice == 3)
        incomeSourceChoice = 5;

    // Check whether fields are empty or not
    if(des.isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("Please Enter Description"));
        return;
    }

    if(price.isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("Please Enter Amount"));
        return;
    }

    // Write Transaction to Database with all the entered information
    Transaction entry(INCOME,price.toDouble(),des.toStdString(),(TranCategory_t)catChoice, (PaymentType_t)incomeSourceChoice, monthChoice, dayChoice, yearChoice);
    entry.sendTransactionToDatabase();

    // Close Window
    this->close();

    // Set Default
    dateMonthBox->setCurrentIndex(0);
    dateDayBox->setCurrentIndex(0);
    dateYearBox->setCurrentIndex(0);
    descriptionValue->clear();
    categoryBox->setCurrentIndex(0);
    amountValue->clear();
    incomeSourceBox->setCurrentIndex(0);
}

AddIncome::~AddIncome() {}
