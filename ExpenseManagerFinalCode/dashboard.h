/*\file	dashboard.h
*
* \brief	Dashboard Header file to Display Dashboard & Graph GUI
*
* Revision History  :
*   Date            Author                  Change(Describe the changes made)
*   05.04.2016      Amit Bhorania           Created File and added Class defines
*   05.05.2016      Amit Bhorania           Added Members & Methods for Dashboard and GUI
*   05.05.2016      Vrushali Gaikwad        Added Members & Methods for Graph
*   05.07.2016      Amit & Vrushali         Integrated Graph into Dashboard
*   05.07.2016      Amit & Vrushali         Integrated Add Income & Add Expense into Dashboard
*   05.07.2016      Amit & Vrushali & Ankit Integrated Backend and Database with GUI
*   05.08.2016      Amit Bhorania           Code Clean Up
*/

#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QComboBox>
#include "qcustomplot.h"
#include "addexpense.h"
#include "addincome.h"
#include <QDate>
#include "date.h"
#include "graphdata.h"
#include <vector>

// Dashboard Class to display Username, Figures, Graph etc
class Dashboard : public QWidget
{
    Q_OBJECT

public:
    Dashboard(QWidget *parent = 0);

    ~Dashboard();

    // Get Current Date to use it in other code
    void getCurrentDate();

    // Show User Name in Dashboard
    void showUserName();

    // Show Timeline in Dashboard
    void showTimeline();

    // Show Buttons in Dashboard
    void showButtons();

    // Combine TimeLine & Buttons Layout in Dashboard
    void combineTimelineButtons();

    // Display Income & Expense Figures in the Dashboard
    void showFigures();

    // Combine Figures & Timeline-Buttons
    void combineFiguresTimelineButtons();

    // Plot Graph in the Dashboard
    void showGraph();

    // Combine Figure-Button-Timeline and Graph Layout
    void combineGraphFiguresTimelineButtons();

    // Add all the created layouts in the main layout
    void showMainLayout();

    // Update the Graphs on change in the Transaction file
    void updateGraph(int timeline);

    // Update the Figures on change in the Transaction file
    void updateFigures(int timeline);

    // Return Current Timeline Selected
    int getCurrentTimelineValue();

private:
    // Variables for User Name Display
    QLabel *userNameLabel;
    QGroupBox *userNameBox;
    QHBoxLayout *userNameLayout;

    // Variables for Timeline Display
    QLabel *timelineLabel;
    QComboBox *timelineCombo;
    QGroupBox *timelineBox;
    QHBoxLayout *timelineLayout;

    // Variables for Button Display
    QPushButton *addIncomeButton;
    QPushButton *addExpenseButton;
    QPushButton *viewTransactionButton;
    QGroupBox *buttonsBox;
    QGridLayout *buttonsLayout;

    // Variable to combine Timeline and Buttons
    QVBoxLayout *groupTimelineButtonsLayout;

    // Variables for Figures Display
    QLabel *monthLabel;
    QLabel *monthValueLabel;
    QLabel *previousBalanceLabel;
    QLabel *previousBalanceValueLabel;
    QLabel *currentIncomeLabel;
    QLabel *currentIncomeValueLabel;
    QLabel *currentExpenseLabel;
    QLabel *currentExpenseValueLabel;
    QLabel *currentMonthBalanceLabel;
    QLabel *currentMonthBalanceValueLabel;
    QLabel *totalBalanceLabel;
    QLabel *totalBalanceValueLabel;
    QGroupBox *figureBox;
    QGridLayout *figureLayout;

    // Variable to combine Figures, Timeline and Buttons
    QHBoxLayout *groupFiguresTimelineButtonsLayout;

    // Variables for Graph Display
    QCustomPlot *customPlot;
    QLabel *graphLabel;
    QCPBarsGroup *graph;
    QCPBars *incomeGraph;
    QCPBars *expenseGraph;
    QVector<QString> labels;
    QVector<double> ticks;

    // Timeline_Value
    // 0 - Daily
    // 1 - Monthly
    // 2 - Yearly
    int timelineVal;

    // Income and Expense Data to show in Graph
    QVector<double> incomeData, expenseData;
    vector<double> incomeDataDB, expenseDataDB;
    double maxY;

    QGroupBox *graphBox;
    QVBoxLayout *graphLayout;

    // Variable to combine Graph, Figures, Timeline and Buttons
    QVBoxLayout *groupGraphFiguresTimelineButtonsLayout;

    // Variable to display Main layout
    QVBoxLayout *mainLayout;

    // Expense Window
    AddExpense expenseWindow;

    // Income Window
    AddIncome incomeWindow;

    // Current Date
    QDate currentDate;
    Date date;

    // Graph Data Object to access its methods
    GraphData graphData;

public slots:
    void getTimeline(int index) {
        timelineVal = index;
        updateGraph(timelineVal);
        updateFigures(timelineVal);
    };

    void showExpenseWindow() {
        expenseWindow.show();
    };

    void showIncomeWindow() {
        incomeWindow.show();
    };

    void redrawGraph() {
        updateGraph(timelineVal);
        updateFigures(timelineVal);
    };

};

#endif // DASHBOARD_H
