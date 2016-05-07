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

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    Dashboard(QWidget *parent = 0);
    ~Dashboard();
    void showUserName();
    void showTimeline();
    void showButtons();

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
    QCustomPlot *customPlot;

    // Graph
    QLabel *graphLabel;
    QCPBarsGroup *graph;
    QCPBars *incomeGraph;
    QCPBars *expenseGraph;

    // Buttons
    QPushButton *addIncomeButton;
    QPushButton *addExpenseButton;
    QPushButton *viewTransactionButton;

#if 0
    QString *monthStr;
    QString *prevBalanceStr;
    QString *currentIncomeStr;
    QString *currentExpenseStr;
    QString *currentMonthBalanceStr;
    QString *totalBalanceStr;
#endif

};

#endif // DASHBOARD_H
