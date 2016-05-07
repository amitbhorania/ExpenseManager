#include "dashboard.h"

#define GUI_FONTTYPE  "Helvetica"
//#define GUI_FONTTYPE  "Cambria"
#define GUI_FONTSIZE  11

Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent)
{
    // UserName Display
    userNameLabel = new QLabel("Amit Bhorania");
    userNameLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    userNameLabel->setStyleSheet("QLabel { background-color : rgb(0, 128, 128); color : white; }");
    //userNameLabel->setStyleSheet("QLabel { color : rgb(0, 128, 128); }");
    QGroupBox *userNameBox = new QGroupBox();
    QHBoxLayout *userNameLayout = new QHBoxLayout();
    userNameLayout->addWidget(userNameLabel);
    userNameBox->setLayout(userNameLayout);

    // TimeLine Selection
    timelineLabel = new QLabel("Timeline:");
    timelineLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    timelineCombo = new QComboBox();
    timelineCombo->addItem("Daily");
    timelineCombo->addItem("Monthly");
    timelineCombo->addItem("Yearly");
    QGroupBox *timelineBox = new QGroupBox();
    QHBoxLayout *timelineLayout = new QHBoxLayout();
    timelineLayout->addWidget(timelineLabel);
    timelineLayout->addWidget(timelineCombo);
    timelineBox->setLayout(timelineLayout);

    // Figures
    monthLabel = new QLabel("Month:");
    monthLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    //monthStr = new QString();
    //monthStr->setRawData("May");
    //*monthStr = QString::fromStdString("May");
    monthValueLabel = new QLabel("May");
    monthValueLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    previousBalanceLabel = new QLabel("Previous Balance");
    previousBalanceLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    previousBalanceValueLabel = new QLabel("US$ 187.00");
    previousBalanceValueLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    currentIncomeLabel = new QLabel("Income");
    currentIncomeLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    currentIncomeValueLabel = new QLabel("US$ 200.00");
    currentIncomeValueLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    currentExpenseLabel = new QLabel("Expense");
    currentExpenseLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    currentExpenseValueLabel = new QLabel("US$ 50.00");
    currentExpenseValueLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    currentMonthBalanceLabel = new QLabel("Current Month Balance");
    currentMonthBalanceLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    currentMonthBalanceValueLabel = new QLabel("US$ 150.00");
    currentMonthBalanceValueLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    totalBalanceLabel = new QLabel("Total Balance");
    totalBalanceLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    totalBalanceValueLabel = new QLabel("US$ 337.00");
    totalBalanceValueLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    QGroupBox *figureBox = new QGroupBox();
    QGridLayout *figureLayout = new QGridLayout();
    figureLayout->addWidget(monthLabel, 0, 0);
    figureLayout->addWidget(monthValueLabel, 0, 1);
    figureLayout->addWidget(previousBalanceLabel, 1, 0);
    figureLayout->addWidget(previousBalanceValueLabel, 1, 1);
    figureLayout->addWidget(currentIncomeLabel, 2, 0);
    figureLayout->addWidget(currentIncomeValueLabel, 2, 1);
    figureLayout->addWidget(currentExpenseLabel, 3, 0);
    figureLayout->addWidget(currentExpenseValueLabel, 3, 1);
    figureLayout->addWidget(currentMonthBalanceLabel, 4, 0);
    figureLayout->addWidget(currentMonthBalanceValueLabel, 4, 1);
    figureLayout->addWidget(totalBalanceLabel, 5, 0);
    figureLayout->addWidget(totalBalanceValueLabel, 5, 1);
    figureBox->setLayout(figureLayout);

    // Recent Transaction

    // Graph
    customPlot = new QCustomPlot();
    graph = new QCPBarsGroup(customPlot);





    QGroupBox *graphBox = new QGroupBox();
    QVBoxLayout *graphLayout = new QVBoxLayout();
    graphLayout->addWidget(graph);
    graphBox->setLayout(graphLayout);


    // Buttons


    // Main Layout
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(userNameBox);
    mainLayout->addWidget(timelineBox);
    mainLayout->addWidget(figureBox);
    mainLayout->addWidget(graphBox);
    setLayout(mainLayout);
    setWindowTitle("Dash Board");
}

Dashboard::~Dashboard()
{

}
