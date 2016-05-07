//Vrushali Gaikwad

#include "adding.h"


Adding::Adding(QWidget* parent)
    : QDialog(parent)
{
    setFixedSize(300, 200);
    setWindowTitle("Add Income");
    setModal(true);
    setAttribute(Qt::WA_DeleteOnClose);

  //  QDateTime dateTime = QDateTime::currentDateTime();
   // QString todaysdate = dateTime.toString();

    categoryBox = new QComboBox();
    categoryBox->addItem("FRIEND");
    categoryBox->addItem("SALARY");
    categoryBox->addItem("PENSION");
    categoryBox->addItem("OTHER");

    DateBox = new QComboBox();
    DateBox->addItem("Jan");
    DateBox->addItem("Feb");
    DateBox->addItem("Mar");
    DateBox->addItem("April");
    DateBox->addItem("May");
    DateBox->addItem("June");
    DateBox->addItem("July");
    DateBox->addItem("Aug");
    DateBox->addItem("Sep");
    DateBox->addItem("Oct");
    DateBox->addItem("Nov");
    DateBox->addItem("Dec");

    DateDayBox = new QComboBox();
    DateDayBox->addItem("1");
    DateDayBox->addItem("2");
    DateDayBox->addItem("3");
    DateDayBox->addItem("4");
    DateDayBox->addItem("5");
    DateDayBox->addItem("6");
    DateDayBox->addItem("7");
    DateDayBox->addItem("8");
    DateDayBox->addItem("9");
    DateDayBox->addItem("10");
    DateDayBox->addItem("11");
    DateDayBox->addItem("12");
    DateDayBox->addItem("13");
    DateDayBox->addItem("14");
    DateDayBox->addItem("15");
    DateDayBox->addItem("16");
    DateDayBox->addItem("17");
    DateDayBox->addItem("18");
    DateDayBox->addItem("19");
    DateDayBox->addItem("20");
    DateDayBox->addItem("21");
    DateDayBox->addItem("22");
    DateDayBox->addItem("23");
    DateDayBox->addItem("24");
    DateDayBox->addItem("25");
    DateDayBox->addItem("26");
    DateDayBox->addItem("27");
    DateDayBox->addItem("28");
    DateDayBox->addItem("29");
    DateDayBox->addItem("30");
    DateDayBox->addItem("31");

    DateYearBox = new QComboBox();
    DateYearBox->addItem("2010");
    DateYearBox->addItem("2011");
    DateYearBox->addItem("2012");
    DateYearBox->addItem("2013");
    DateYearBox->addItem("2014");
    DateYearBox->addItem("2015");
    DateYearBox->addItem("2016");



    userDate = new QLabel("Date:");
    userLineCat = new QLineEdit();

    userCategory = new QLabel("Category:");
    userLineCat = new QLineEdit();

    userPrice = new QLabel("Price:");
    userLinePrice = new QLineEdit();

    userPayment = new QLabel("Payment Type:");
    userLinePayment = new QLineEdit();

    userDescription = new QLabel("Description:");
    userLineDescription = new QLineEdit();

    addButton = new QPushButton("ADD");
    cancelButton = new QPushButton("CANCEL");

    QVBoxLayout* vbox = new QVBoxLayout(this);
    QHBoxLayout* hbox1 = new QHBoxLayout();
    QHBoxLayout* hbox2 = new QHBoxLayout();
    QHBoxLayout* hbox3 = new QHBoxLayout();
    QHBoxLayout* hbox4 = new QHBoxLayout();
    QHBoxLayout* hbox5 = new QHBoxLayout();
    QHBoxLayout* hbox6 = new QHBoxLayout();

    hbox6 -> addWidget(addButton,1,Qt::AlignCenter);
    hbox6 -> addWidget(cancelButton,1,Qt::AlignCenter);


    hbox1 -> addWidget(userDate,1);
    hbox1 -> addWidget(DateBox,1);
    hbox1 -> addWidget(DateDayBox,1);
    hbox1 -> addWidget(DateYearBox,1);


    hbox2 -> addWidget(userCategory,1);
    hbox2 -> addWidget(categoryBox,3);

    hbox3 -> addWidget(userPrice,1);
    hbox3 -> addWidget(userLinePrice,3);

    hbox4 -> addWidget(userPayment,1);
    hbox4 -> addWidget(userLinePayment,3);

    hbox5 -> addWidget(userDescription,1);
    hbox5 -> addWidget(userLineDescription,3);



    vbox->addLayout(hbox1);
    vbox->addLayout(hbox5);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox3);
    vbox->addLayout(hbox4);
    vbox->addLayout(hbox6);
    vbox->setSpacing(15);

    connect(addButton, SIGNAL(clicked()), this, SLOT(OnAdd()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(OnCancel()));

}

void Adding::OnCancel()
{
    this->close();
    parentWidget()->close();
}

void Adding::OnAdd()
{

    QString uPrice = userLinePrice->text();
    QString uPaymentType = userLinePayment->text();
    QString uDescriptionType = userLineDescription->text();
    QString catChoice = categoryBox->currentText();
    QString DatChoice = DateBox->currentText();


    this->close();
    parentWidget()->close();
}


Adding::~Adding() {}
