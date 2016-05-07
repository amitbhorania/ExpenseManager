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

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    Dashboard(QWidget *parent = 0);
    ~Dashboard();
    void showUserName();
    void showTimeline();
    void showButtons();
    void combineTimelineButtons();
    void showFigures();
    void combineFiguresTimelineButtons();
    void showGraph();
    void combineGraphFiguresTimelineButtons();
    void showMainLayout();
    void updateGraph(int timeline);
    void updateFigures(int timeline);
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
#if 0
    QString *monthStr;
    QString *prevBalanceStr;
    QString *currentIncomeStr;
    QString *currentExpenseStr;
    QString *currentMonthBalanceStr;
    QString *totalBalanceStr;
#endif

public slots:
    void getTimeline(int index) {
        timelineVal = index;
        updateGraph(timelineVal);
        updateFigures(timelineVal);
    };
    void showExpenseWindow() {
        //QWidget *window = new QWidget();
        //expenseWindow = new AddExpense();
        //expenseWindow->show();
        expenseWindow.show();
    };
    void showIncomeWindow() {
        //QWidget *window = new QWidget();
        //expenseWindow = new AddExpense();
        //expenseWindow->show();
        incomeWindow.show();
    };
};

#endif // DASHBOARD_H
