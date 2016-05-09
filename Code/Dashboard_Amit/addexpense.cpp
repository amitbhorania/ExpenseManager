#include "addexpense.h"
#include "transaction.h"
#include "enums.h"

AddExpense::AddExpense(QWidget *parent) : QWidget(parent)
{
    setFixedSize(300, 200);
    setWindowTitle("Add Expense");

    // Show Date of Transaction
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

    // Show Transaction Description
    description = new QLabel("Description:");
    descriptionValue = new QLineEdit();

    // Show Transaction Category
    category = new QLabel("Category:");
    categoryBox = new QComboBox();
    categoryBox->addItem("Travelling");
    categoryBox->addItem("Food");
    categoryBox->addItem("Shopping");
    categoryBox->addItem("Education");
    categoryBox->addItem("Rent");
    categoryBox->addItem("Medical");
    categoryBox->addItem("Other");

    // Show Transaction Amount
    amount = new QLabel("Amount:");
    amountValue = new QLineEdit();

    // Show Payment Box
    paymentType = new QLabel("Payment Type:");
    paymentBox = new QComboBox();
    paymentBox->addItem("Cash");
    paymentBox->addItem("Cheque");
    paymentBox->addItem("Online Banking");
    paymentBox->addItem("Credit");
    paymentBox->addItem("Debit");
    paymentBox->addItem("Other");

    // Buttons
    addButton = new QPushButton("ADD");
    cancelButton = new QPushButton("CANCEL");

    // Layouts
    QVBoxLayout* vbox = new  QVBoxLayout(this);
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

    hbox5 -> addWidget(paymentType,1);
    hbox5 -> addWidget(paymentBox,3);

    hbox6 -> addWidget(addButton, 1, Qt::AlignCenter);
    hbox6 -> addWidget(cancelButton, 1, Qt::AlignCenter);

    vbox->addLayout(hbox1);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox3);
    vbox->addLayout(hbox4);
    vbox->addLayout(hbox5);
    vbox->addLayout(hbox6);
    vbox->setSpacing(15);
    setLayout(vbox);

    // Connect Signals to Action functions
    connect(addButton, SIGNAL(clicked()), this, SLOT(OnAdd()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(OnCancel()));
}

void AddExpense::OnCancel()
{
    this->close();
}

void AddExpense::OnAdd()
{
    int monthChoice = dateMonthBox->currentIndex() + 1;
    int dayChoice = dateDayBox->currentIndex() + 1;
    int yearChoice = dateYearBox->currentIndex() + 2010;
    QString des = descriptionValue->text();
    int catChoice = categoryBox->currentIndex();
    QString price = amountValue->text();
    int paymentChoice = paymentBox->currentIndex();

    Transaction entry(EXPENSE,price.toDouble(),des.toStdString(),(TranCategory_t)catChoice, (PaymentType_t)paymentChoice, monthChoice, dayChoice, yearChoice);
    entry.sendTransactionToDatabase();

    this->close();

    // Set Default
    dateMonthBox->setCurrentIndex(0);
    dateDayBox->setCurrentIndex(0);
    dateYearBox->setCurrentIndex(0);
    descriptionValue->clear();
    categoryBox->setCurrentIndex(0);
    amountValue->clear();
    paymentBox->setCurrentIndex(0);
}

AddExpense::~AddExpense() {}
