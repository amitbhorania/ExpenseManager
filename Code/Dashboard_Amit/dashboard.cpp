/*\file	dashboard.cpp
*
* \brief	Dashboard Source file to Display Dashboard & Graph GUI
*
* Revision History  :
*   Date            Author                  Change(Describe the changes made)
*   05.04.2016      Amit Bhorania           Created File and added basic Class defines
*   05.05.2016      Amit Bhorania           Added Code to Display Dashboard GUI
*   05.05.2016      Vrushali Gaikwad        Added Code to Display Graph
*   05.06.2016      Amit Bhorania           Modularized Code into different Methods
*   05.07.2016      Amit & Vrushali         Integrated Graph into Dashboard
*   05.07.2016      Amit & Vrushali         Integrated Add Income & Add Expense into Dashboard
*   05.07.2016      Amit & Vrushali & Ankit Integrated Backend and Database with GUI
*   05.08.2016      Amit Bhorania           Code Clean Up
*/

#include "dashboard.h"
#include "graphdata.h"
#include <iostream>
using namespace std;

#define CURRENCY "US$ "
#define GUI_FONTTYPE  "Helvetica"
//#define GUI_FONTTYPE  "Cambria"
#define GUI_FONTSIZE  11

// Call individual methods to show each part of Dashboard
Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent)
{
    // Add 6 Data into Vector
    for(int i = 0; i < 6; i++) {
        incomeDataDB.push_back(0);
        expenseDataDB.push_back(0);
        incomeData.push_back(0);
        expenseData.push_back(0);
    }

    // Get Current Date
    getCurrentDate();

    // Display User Name
    showUserName();

    // Display Timeline Selection Combo Box
    showTimeline();

    // Display Buttons
    showButtons();

    // Combine Layouts
    combineTimelineButtons();

    // Display Figures
    showFigures();

    // Combine Layouts
    combineFiguresTimelineButtons();

    // Display Graph
    showGraph();

    // Combine Layouts
    combineGraphFiguresTimelineButtons();

    // Display Main Layout containing all the child Layouts
    showMainLayout();

    // Connect Signals with its appropriate Actions for GUI
    connect(timelineCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(getTimeline(int)));
    connect(addExpenseButton, SIGNAL(clicked()), this, SLOT(showExpenseWindow()));
    connect(addIncomeButton, SIGNAL(clicked()), this, SLOT(showIncomeWindow()));
}

// Get Current Date to use it in other code
void Dashboard::getCurrentDate() {
    // Get Current Date
    currentDate = QDate::currentDate();

    // Set Current Date into Date Class
    date.setDay(currentDate.day());
    date.setMonth(currentDate.month());
    date.setYear(currentDate.year());
}

// Show User Name in Dashboard
void Dashboard::showUserName() {
    userNameLabel = new QLabel("Dov Kruger");
    userNameLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    //userNameLabel->setStyleSheet("QLabel { background-color : rgb(0, 128, 128); color : white; }");
    userNameLabel->setStyleSheet("QLabel { color : rgb(0, 128, 128); }");
    userNameBox = new QGroupBox();
    userNameLayout = new QHBoxLayout();
    userNameLayout->addWidget(userNameLabel);
    userNameBox->setLayout(userNameLayout);
}

// Show Timeline in Dashboard
void Dashboard::showTimeline() {
    timelineLabel = new QLabel("Timeline:");
    timelineLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    timelineCombo = new QComboBox();
    timelineCombo->addItem("Daily");
    timelineCombo->addItem("Monthly");
    timelineCombo->addItem("Yearly");

    // Default Time Line set to Monthly
    timelineCombo->setCurrentIndex(1);
    timelineVal = 1;

    timelineBox = new QGroupBox();
    timelineLayout = new QHBoxLayout();
    timelineLayout->addWidget(timelineLabel,0,Qt::AlignLeft);
    timelineLayout->addWidget(timelineCombo,0,Qt::AlignLeft);
    timelineBox->setLayout(timelineLayout);
}

// Show Buttons in Dashboard
void Dashboard::showButtons() {
    addIncomeButton = new QPushButton("Income");
    //addIncomeButton->setFont(QFont("Cambria", 13, QFont::Normal));
    addExpenseButton = new QPushButton("Expense");
    //addExpenseButton->setFont(QFont("Cambria", 13, QFont::Normal));
    viewTransactionButton = new QPushButton("View Transaction");
    //viewTransactionButton->setFont(QFont("Cambria", 13, QFont::Normal));
    buttonsBox = new QGroupBox();
    buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(addIncomeButton,0,0);
    buttonsLayout->addWidget(addExpenseButton,0,1);
    //buttonsLayout->addWidget(viewTransactionButton,1,0,1,2);
    buttonsBox->setLayout(buttonsLayout);
}

// Combine TimeLine & Buttons Layout in Dashboard
void Dashboard::combineTimelineButtons() {
    groupTimelineButtonsLayout = new QVBoxLayout();
    groupTimelineButtonsLayout->addWidget(timelineBox, 0);
    groupTimelineButtonsLayout->addWidget(buttonsBox, 0);
}

// Display Income & Expense Figures in the Dashboard
void Dashboard::showFigures() {
    monthLabel = new QLabel("Month:");
    monthLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
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
    currentMonthBalanceLabel = new QLabel("Current Balance");
    currentMonthBalanceLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    currentMonthBalanceValueLabel = new QLabel("US$ 150.00");
    currentMonthBalanceValueLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    totalBalanceLabel = new QLabel("Total Balance");
    totalBalanceLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    totalBalanceValueLabel = new QLabel("US$ 337.00");
    totalBalanceValueLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));

    // Add widgets in Layout
    figureBox = new QGroupBox();
    figureLayout = new QGridLayout();
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
    figureBox->setLayout(figureLayout);
}

// Combine Figures & Timeline-Buttons Layout
void Dashboard::combineFiguresTimelineButtons() {
    groupFiguresTimelineButtonsLayout = new QHBoxLayout();
    groupFiguresTimelineButtonsLayout->addWidget(figureBox, 0);
    groupFiguresTimelineButtonsLayout->addLayout(groupTimelineButtonsLayout, 0);
}

// Plot Graph in the Dashboard
void Dashboard::showGraph() {
    graphLabel = new QLabel("Graph");
    graphLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    graphLabel->setStyleSheet("QLabel { color : rgb(0, 128, 128); }");

    customPlot = new QCustomPlot();
    graph = new QCPBarsGroup(customPlot);

    // Income Bar Graph
    incomeGraph = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    // Expense Bar Graph
    expenseGraph = new QCPBars(customPlot->xAxis, customPlot->yAxis);

    customPlot->addPlottable(incomeGraph);
    customPlot->addPlottable(expenseGraph);
    graph->insert(1,incomeGraph);
    graph->insert(2,expenseGraph);

    // Legend Display
    QPen pen;
    pen.setWidthF(0.5);

    incomeGraph->setName("Income");
    pen.setColor(QColor(255, 131, 0));
    incomeGraph->setPen(pen);
    incomeGraph->setBrush(QColor(255, 131, 0, 50));
    incomeGraph->setWidth(0.2);

    expenseGraph->setName("Expense");
    pen.setColor(QColor(1, 92, 191));
    expenseGraph->setPen(pen);
    expenseGraph->setBrush(QColor(1, 92, 191, 50));
    expenseGraph->setWidth(0.2);

    // Add Ticks
    ticks << 1 << 2 << 3 << 4 << 5 << 6;

    // Clear the Data
    for(int k = 0; k < 6; k++) {
        incomeDataDB[k] = 0;
        expenseDataDB[k] = 0;
        incomeData[k] = 0;
        expenseData[k] = 0;
    }

    // Prepare X Axis
    if(timelineVal == 0) {
        // Daily
        // Set Ticks Label Value according to cuurent Date
        int i = currentDate.dayOfWeek();
        for(int j = 0; j < 6; j++) {
            labels.insert(0, currentDate.shortDayName(i));
            i--;
            if(i == 0)
                i = 7;
        }

        // Get Last Six days Income & Expense Data from Database
        graphData.LastSixDays(expenseDataDB, incomeDataDB, date);

        // Find Out the Max value and store the Vector data into QVector data in reverse order
        maxY = 0;
        for(int i = 5, j = 0; i >= 0; i--, j++) {
            incomeData[j] = incomeDataDB[i];
            expenseData[j] = expenseDataDB[i];
            if (maxY < incomeDataDB[i])
                maxY = incomeDataDB[i];
            if (maxY < expenseDataDB[i])
                maxY = expenseDataDB[i];
        }
    }
    else if(timelineVal == 2) {
        // Yearly
        qDebug() << "By Default Graph Years";
        // Set Ticks Label Value according to cuurent Date
        int i = currentDate.year();
        for(int j = 0; j < 6; j++) {
            labels.insert(0, QString::number(i));
            i--;
        }

        // Get Last Six Year Income & Expense Data from Database
        graphData.LastSixYears(expenseDataDB, incomeDataDB, date);

        // Find Out the Max value and store the Vector data into QVector data in reverse order
        maxY = 0;
        for(int i = 5, j = 0; i >= 0; i--, j++) {
            incomeData[j] = incomeDataDB[i];
            expenseData[j] = expenseDataDB[i];
            if (maxY < incomeDataDB[i])
                maxY = incomeDataDB[i];
            if (maxY < expenseDataDB[i])
                maxY = expenseDataDB[i];
        }
    }
    else {
        // Monthly
        // Set Ticks Label Value according to cuurent Date
        int i = currentDate.month();
        for(int j = 0; j < 6; j++) {
            labels.insert(0,currentDate.shortMonthName(i));
            i--;
            if(i == 0)
                i = 12;
        }

        // Get Last Six Months Income & Expense Data from Database
        graphData.LastSixMonths(expenseDataDB, incomeDataDB, date);

        // Find Out the Max value and store the Vector data into QVector data in reverse order
        maxY = 0;
        for(int i = 5, j = 0; i >= 0; i--, j++) {
            incomeData[j] = incomeDataDB[i];
            expenseData[j] = expenseDataDB[i];
            if (maxY < incomeDataDB[i])
                maxY = incomeDataDB[i];
            if (maxY < expenseDataDB[i])
                maxY = expenseDataDB[i];
        }
    }

    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickVector(ticks);
    customPlot->xAxis->setTickVectorLabels(labels);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTickCount(0);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->setRange(0, 7);

    // Prepare Y Axis
    customPlot->yAxis->setRange(0, maxY);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Amount");
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Load Data into Graph
    incomeGraph->setData(ticks, incomeData);
    expenseGraph->setData(ticks, expenseData);

    //legends
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    customPlot->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    customPlot->legend->setBorderPen(legendPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    graphBox = new QGroupBox();
    graphLayout = new QVBoxLayout();
    graphLayout->addWidget(graphLabel,0,Qt::AlignTop);
    graphLayout->addWidget(customPlot,20);
    graphBox->setLayout(graphLayout);
}

// Combine Figure-Button-Timeline and Graph Layout
void Dashboard::combineGraphFiguresTimelineButtons() {
    groupGraphFiguresTimelineButtonsLayout = new QVBoxLayout();
    groupGraphFiguresTimelineButtonsLayout->addLayout(groupFiguresTimelineButtonsLayout);
    groupGraphFiguresTimelineButtonsLayout->addWidget(graphBox);
}

// Add all the created layouts in the main layout
void Dashboard::showMainLayout() {
    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(userNameBox, 0, Qt::AlignTop);
    mainLayout->addLayout(groupGraphFiguresTimelineButtonsLayout, 10);
    setLayout(mainLayout);
    setWindowTitle("Dash Board");
    setFixedSize(500,500);
}

// Update the Graphs on change in the Transaction file
void Dashboard::updateGraph(int timeline) {
    ticks.clear();
    labels.clear();

    //clear the data
    for(int k = 0; k < 6; k++) {
        incomeData[k] = 0;
        expenseData[k] = 0;
        incomeDataDB[k] = 0;
        expenseDataDB[k] = 0;
    }

    ticks << 1 << 2 << 3 << 4 << 5 << 6;
    if(timeline == 0) {
        // Daily
        // Set Ticks Label Value according to cuurent Date
        int i = currentDate.dayOfWeek();
        for(int j = 0; j < 6; j++) {
            labels.insert(0, currentDate.shortDayName(i));
            i--;
            if(i == 0)
                i = 7;
        }

        // Get Last Six days Income & Expense Data from Database
        graphData.LastSixDays(expenseDataDB, incomeDataDB, date);

        // Find Out the Max value and store the Vector data into QVector data in reverse order
        maxY = 0;
        for(int i = 5, j = 0; i >= 0; i--, j++) {
            incomeData[j] = incomeDataDB[i];
            expenseData[j] = expenseDataDB[i];
            if (maxY < incomeDataDB[i])
                maxY = incomeDataDB[i];
            if (maxY < expenseDataDB[i])
                maxY = expenseDataDB[i];
        }
    }
    else if(timeline == 2) {
        qDebug() << "Update Graph Years";
        // Yearly
        // Set Ticks Label Value according to cuurent Date
        int i = currentDate.year();
        for(int j = 0; j < 6; j++) {
            labels.insert(0, QString::number(i));
            i--;
        }

        // Get Last Six Years Income & Expense Data from Database
        graphData.LastSixYears(expenseDataDB, incomeDataDB, date);

        // Find Out the Max value and store the Vector data into QVector data in reverse order
        maxY = 0;
        for(int i = 5, j = 0; i >= 0; i--, j++) {
            incomeData[j] = incomeDataDB[i];
            expenseData[j] = expenseDataDB[i];
            if (maxY < incomeDataDB[i])
                maxY = incomeDataDB[i];
            if (maxY < expenseDataDB[i])
                maxY = expenseDataDB[i];
        }
    } else {
        // Monthly
        // Set Ticks Label Value according to cuurent Date
        int i = currentDate.month();
        for(int j = 0; j < 6; j++) {
            labels.insert(0, currentDate.shortMonthName(i));
            i--;
            if(i == 0)
                i = 12;
        }

        // Get Last Six Months Income & Expense Data from Database
        graphData.LastSixMonths(expenseDataDB, incomeDataDB, date);

        // Find Out the Max value and store the Vector data into QVector data in reverse order
        maxY = 0;
        for(int i = 5, j = 0; i >= 0; i--, j++) {
            incomeData[j] = incomeDataDB[i];
            expenseData[j] = expenseDataDB[i];
            if (maxY < incomeDataDB[i])
                maxY = incomeDataDB[i];
            if (maxY < expenseDataDB[i])
                maxY = expenseDataDB[i];
        }
    }

    customPlot->xAxis->setTickVector(ticks);
    customPlot->xAxis->setTickVectorLabels(labels);
    customPlot->yAxis->setRange(0, maxY);
    incomeGraph->setData(ticks, incomeData);
    expenseGraph->setData(ticks, expenseData);
    customPlot->replot();
}

// Method to Update the Figures in the Dashboard
void Dashboard::updateFigures(int timeline) {
    double prev_bal;
    double cur_income;
    double cur_expense;
    double cur_balance;

    // Calculate Figures from Database Vectors
    prev_bal = incomeDataDB[1] - expenseDataDB[1];
    cur_income = incomeDataDB[0];
    cur_expense = expenseDataDB[0];
    cur_balance = cur_income - cur_expense;

    QString time_value;

    if(timeline == 0) {
        // Daily
        monthLabel->setText("Day:");
        time_value = currentDate.shortDayName(currentDate.dayOfWeek());
    }
    else if (timeline == 1) {
        // Monthly
        monthLabel->setText("Month:");
        time_value = currentDate.shortMonthName(currentDate.month());
    }
    else {
        // Yearly
        monthLabel->setText("Year:");
        time_value = QString::number(currentDate.year());
    }

    // Update figures in the Dashboard
    monthValueLabel->setText(time_value);
    previousBalanceValueLabel->setText(CURRENCY +QString::number(prev_bal));
    currentIncomeValueLabel->setText(CURRENCY +QString::number(cur_income));
    currentExpenseValueLabel->setText(CURRENCY +QString::number(cur_expense));
    currentMonthBalanceValueLabel->setText(CURRENCY +QString::number(cur_balance));
}

// Return Current Timeline Selected
int Dashboard::getCurrentTimelineValue() {
    return timelineVal;
}

// Destructor to delete all the dynamically assigned memories for Dashboard
Dashboard::~Dashboard()
{
    // Delete the dynamically assigned variables
    delete userNameLabel;
    delete userNameBox;
    delete timelineLabel;
    delete timelineCombo;
    delete userNameLayout;
    delete timelineBox;
    delete timelineLayout;
    delete addIncomeButton;
    delete addExpenseButton;
    delete viewTransactionButton;
    delete buttonsBox;
    delete buttonsLayout;
    delete groupTimelineButtonsLayout;
    delete monthLabel;
    delete monthValueLabel;
    delete previousBalanceLabel;
    delete previousBalanceValueLabel;
    delete currentIncomeLabel;
    delete currentIncomeValueLabel;
    delete currentExpenseLabel;
    delete currentExpenseValueLabel;
    delete currentMonthBalanceLabel;
    delete currentMonthBalanceValueLabel;
    delete totalBalanceLabel;
    delete totalBalanceValueLabel;
    delete figureBox;
    delete figureLayout;
    delete groupFiguresTimelineButtonsLayout;
    delete graphLabel;
    delete customPlot;
    delete graph;
    delete incomeGraph;
    delete expenseGraph;
    delete graphBox;
    delete graphLayout;
    delete groupGraphFiguresTimelineButtonsLayout;
    delete mainLayout;
}
