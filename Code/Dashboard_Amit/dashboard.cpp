#include "dashboard.h"

#define GUI_FONTTYPE  "Helvetica"
//#define GUI_FONTTYPE  "Cambria"
#define GUI_FONTSIZE  11

// Show User Name in Dashboard
Dashboard::showUserName() {
    userNameLabel = new QLabel("Amit Bhorania");
    userNameLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    //userNameLabel->setStyleSheet("QLabel { background-color : rgb(0, 128, 128); color : white; }");
    userNameLabel->setStyleSheet("QLabel { color : rgb(0, 128, 128); }");
    userNameBox = new QGroupBox();
    userNameLayout = new QHBoxLayout();
    userNameLayout->addWidget(userNameLabel);
    userNameBox->setLayout(userNameLayout);
}

// Show Timeline in Dashboard
Dashboard::showTimeline() {
    timelineLabel = new QLabel("Timeline:");
    timelineLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    timelineCombo = new QComboBox();
    timelineCombo->addItem("Daily");
    timelineCombo->addItem("Monthly");
    timelineCombo->addItem("Yearly");
    QGroupBox *timelineBox = new QGroupBox();
    QHBoxLayout *timelineLayout = new QHBoxLayout();
    timelineLayout->addWidget(timelineLabel,0,Qt::AlignLeft);
    timelineLayout->addWidget(timelineCombo,0,Qt::AlignLeft);
    timelineBox->setLayout(timelineLayout);
}

Dashboard::showButtons() {
    addIncomeButton = new QPushButton("Income");
    addExpenseButton = new QPushButton("Expense");
    viewTransactionButton = new QPushButton("View Transaction");
    QGroupBox *buttonsBox = new QGroupBox();
    QGridLayout *buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(addIncomeButton,0,0);
    buttonsLayout->addWidget(addExpenseButton,0,1);
    buttonsLayout->addWidget(viewTransactionButton,1,0,1,2);
    buttonsBox->setLayout(buttonsLayout);
}

Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent)
{
    showUserName();
    showTimeline();
    showButtons();

    // Combine TimeLine & Buttons
    QVBoxLayout *groupTimelineButtonsLayout = new QVBoxLayout();
    groupTimelineButtonsLayout->addWidget(timelineBox, 0);
    groupTimelineButtonsLayout->addWidget(buttonsBox, 0);

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

    // Combine Figures & Timeline-Buttons
    QHBoxLayout *groupFiguresTimelineButtonsLayout = new QHBoxLayout();
    groupFiguresTimelineButtonsLayout->addWidget(figureBox, 0);
    groupFiguresTimelineButtonsLayout->addLayout(groupTimelineButtonsLayout, 0);

    ///////////////////////////////////////////
    /// Graph
    ///////////////////////////////////////////

    graphLabel = new QLabel("Graph");
    graphLabel->setFont(QFont(GUI_FONTTYPE, GUI_FONTSIZE, QFont::Normal));
    //graphLabel->setStyleSheet("QLabel { background-color : rgb(0, 128, 128); color : white; }");
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

    // Timeline_Value
    // 0 -
    // 1 - Daily
    // 2 - Monthly
    // 3 - Yearly
    int timeline_val = 0;

    QVector<QString> labels;
    QVector<double> ticks;

    // Prepare X Axis
    if(timeline_val == 2) {
        // Monthly
        ticks << 1 << 2 << 3 << 4 << 5 << 6;
        labels << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "June";
        customPlot->xAxis->setAutoTicks(false);
        customPlot->xAxis->setAutoTickLabels(false);
        customPlot->xAxis->setTickVector(ticks);
        customPlot->xAxis->setTickVectorLabels(labels);
        customPlot->xAxis->setTickLabelRotation(60);
        customPlot->xAxis->setSubTickCount(0);
        customPlot->xAxis->setTickLength(0, 4);
        customPlot->xAxis->grid()->setVisible(true);
        customPlot->xAxis->setRange(0, 12);
    }
    else if(timeline_val == 3) {
        // Yearly
        ticks << 1 << 2 << 3 << 4 << 5 << 6;
        labels << "2011" << "2012" << "2013" << "2014" << "2015" << "2016";
        customPlot->xAxis->setAutoTicks(false);
        customPlot->xAxis->setAutoTickLabels(false);
        customPlot->xAxis->setTickVector(ticks);
        customPlot->xAxis->setTickVectorLabels(labels);
        customPlot->xAxis->setTickLabelRotation(60);
        customPlot->xAxis->setSubTickCount(0);
        customPlot->xAxis->setTickLength(0, 4);
        customPlot->xAxis->grid()->setVisible(true);
        customPlot->xAxis->setRange(0, 7);
    } else {
        // Daily
        ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
        labels << "Mon" << "Tue" << "Wed" << "Thur" << "Fri" << "Sat" << "Sun";
        customPlot->xAxis->setAutoTicks(false);
        customPlot->xAxis->setAutoTickLabels(false);
        customPlot->xAxis->setTickVector(ticks);
        customPlot->xAxis->setTickVectorLabels(labels);
        customPlot->xAxis->setTickLabelRotation(60);
        customPlot->xAxis->setSubTickCount(0);
        customPlot->xAxis->setTickLength(0, 4);
        customPlot->xAxis->grid()->setVisible(true);
        customPlot->xAxis->setRange(0, 8);
    }

    // Prepare Y Axis
    customPlot->yAxis->setRange(0, 105);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Amount");
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Income and Expense Data
    QVector<double> incomeData, expenseData;
    incomeData << 100 << 70 << 65 << 60 << 50 << 55 << 82;
    expenseData << 60 << 50 << 40 << 30 << 25 << 20 << 90;

    incomeGraph->setData(ticks, incomeData);
    expenseGraph->setData(ticks, expenseData);

    //legends
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    customPlot->legend->setBorderPen(legendPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    QGroupBox *graphBox = new QGroupBox();
    QVBoxLayout *graphLayout = new QVBoxLayout();
    graphLayout->addWidget(graphLabel,0,Qt::AlignTop);
    graphLayout->addWidget(customPlot,20);
    graphBox->setLayout(graphLayout);

    // Combine Figure-Button and Graph Layout
    QVBoxLayout *groupGraphFiguresTimelineButtonsLayout = new QVBoxLayout();
    groupGraphFiguresTimelineButtonsLayout->addLayout(groupFiguresTimelineButtonsLayout);
    groupGraphFiguresTimelineButtonsLayout->addWidget(graphBox);

    // Main Layout
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(userNameBox, 0, Qt::AlignTop);
    //mainLayout->addWidget(timelineBox, 0, Qt::AlignTop);
    mainLayout->addLayout(groupGraphFiguresTimelineButtonsLayout, 10);
    //mainLayout->addWidget(figureBox);
    //mainLayout->addWidget(graphBox);
    //mainLayout->addWidget(buttonsBox);
    setLayout(mainLayout);
    setWindowTitle("Dash Board");
    setFixedSize(500,500);

#if 0
    QString newpath (":/images/background.jpg");
    QPixmap pixmap = QPixmap(newpath).scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
#endif
}

Dashboard::~Dashboard()
{

}
