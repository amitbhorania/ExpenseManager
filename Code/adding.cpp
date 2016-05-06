//Vrushali Gaikwad

#include "adding.h"


Adding::Adding(QWidget* parent)
    : QDialog(parent)
{
    setFixedSize(300, 300);
    setWindowTitle("Add Income");
    setModal(true);
    setAttribute(Qt::WA_DeleteOnClose);

    QDateTime dateTime = QDateTime::currentDateTime();
    QString todaysdate = dateTime.toString();

    categoryBox = new QComboBox();
    categoryBox->addItem("TRAVELLING");
    categoryBox->addItem("FOOD");
    categoryBox->addItem("SHOPPING");
    categoryBox->addItem("EDUCATION");
    categoryBox->addItem("RENT");
    categoryBox->addItem("MEDICAL");
    categoryBox->addItem("OTHER");

    userDate = new QLabel("Date:");
    todaysDate = new QLabel(todaysdate);

    userCategory = new QLabel("Category:");
    userLineCat = new QLineEdit();

    userPrice = new QLabel("Price:");
    userLinePrice = new QLineEdit();

    userPayment = new QLabel("Payment Type:");
    userLinePayment = new QLineEdit();

    addButton = new QPushButton("ADD");
    cancelButton = new QPushButton("CANCEL");

    QVBoxLayout* vbox = new QVBoxLayout(this);
    QHBoxLayout* hbox1 = new QHBoxLayout();
    QHBoxLayout* hbox2 = new QHBoxLayout();
    QHBoxLayout* hbox3 = new QHBoxLayout();
    QHBoxLayout* hbox4 = new QHBoxLayout();
    QHBoxLayout* hbox5 = new QHBoxLayout();


    hbox1 -> addWidget(userDate,1);
    hbox1 -> addWidget(todaysDate,2);

    hbox2 -> addWidget(userCategory,1);
    hbox2 -> addWidget(categoryBox,2);
    //hbox2 -> addWidget(userLineCat,2);

    hbox3 -> addWidget(userPrice,1);
    hbox3 -> addWidget(userLinePrice,2);

    hbox4 -> addWidget(userPayment,1);
    hbox4 -> addWidget(userLinePayment,2);

    hbox5 -> addWidget(addButton,1,Qt::AlignCenter);
    hbox5 -> addWidget(cancelButton,2,Qt::AlignCenter);

    vbox->addLayout(hbox1);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox3);
    vbox->addLayout(hbox4);
    vbox->addLayout(hbox5);

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
    QString catChoice = categoryBox->currentText();


    this->close();
    parentWidget()->close();
}


Adding::~Adding() {}
