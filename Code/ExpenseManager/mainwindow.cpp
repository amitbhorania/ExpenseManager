#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::makePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makePlot()
{

    QCPBars *income = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *expense = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);

    ui->customPlot->addPlottable(income);
    ui->customPlot->addPlottable(expense);

    QPen pen;
    pen.setWidthF(1.2);

    income->setName("Income");
    pen.setColor(QColor(255, 131, 0));
    income->setPen(pen);
    income->setBrush(QColor(255, 131, 0, 50));

    expense->setName("Expense");
    pen.setColor(QColor(1, 92, 191));
    expense->setPen(pen);
    expense->setBrush(QColor(1, 92, 191, 50));

    int monthly = 0;
    int yearly = 0 ;

    QVector<QString> labels;
    QVector<double> ticks;

    if(monthly)
    {

    ticks << 1 << 2 << 3 << 4 << 5 << 6;
    labels << "jan" << "Feb" << "Mar" << "Apr" << "May" << "June";
    ui->customPlot->xAxis->setAutoTicks(false);
    ui->customPlot->xAxis->setAutoTickLabels(false);
    ui->customPlot->xAxis->setTickVector(ticks);
    ui->customPlot->xAxis->setTickVectorLabels(labels);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTickCount(0);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->setRange(0, 12);
    }
    else
    if(yearly){

    ticks << 1 << 2 << 3 << 4 << 5 << 6;
    labels << "2016" << "2015" << "2014" << "2013" << "2012" << "2011";
    ui->customPlot->xAxis->setAutoTicks(false);
    ui->customPlot->xAxis->setAutoTickLabels(false);
    ui->customPlot->xAxis->setTickVector(ticks);
    ui->customPlot->xAxis->setTickVectorLabels(labels);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTickCount(0);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->setRange(0, 7);
    }
    else
         {
        ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
        labels << "Mon" << "Tue" << "Wed" << "Thur" << "Fri" << "Sat" << "Sun";
        ui->customPlot->xAxis->setAutoTicks(false);
        ui->customPlot->xAxis->setAutoTickLabels(false);
        ui->customPlot->xAxis->setTickVector(ticks);
        ui->customPlot->xAxis->setTickVectorLabels(labels);
        ui->customPlot->xAxis->setTickLabelRotation(60);
        ui->customPlot->xAxis->setSubTickCount(0);
        ui->customPlot->xAxis->setTickLength(0, 4);
        ui->customPlot->xAxis->grid()->setVisible(true);
        ui->customPlot->xAxis->setRange(0, 8);
    }

    //prepare Y axis
    ui->customPlot->yAxis->setRange(0, 105);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("Amount");
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    ui->customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    ui->customPlot->yAxis->grid()->setSubGridPen(gridPen);


    QVector<double> incomeData, expenseData;
    incomeData << 100 << 70 << 65 << 60 << 50 << 55;
    expenseData << 60 << 50 << 40 << 30 << 25 << 20;

    income->setData(ticks, incomeData);
    expense->setData(ticks, expenseData);







    //minti
     //prepare x axis and y
/*
     QVector<double> datax = QVector<double>() << 1 << 2 << 3 << 4  ;
     QVector<double> datay1 = QVector<double>() << 100 << 70 << 80 << 60;
     QVector<double> datay2 = QVector<double>() << 60 << 50 << 40 << 30;

     // set colours to Bar
     QCPBarsGroup *group1 = new QCPBarsGroup(ui->customPlot);
     QCPBars *bars = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
     ui->customPlot->addPlottable(bars);
     bars->setData(datax, datay1);
     bars->setBrush(QColor(0, 0, 255, 50));
     bars->setPen(QColor(0, 0, 255));
     bars->setWidth(0.15);
     bars->setBarsGroup(group1);
     bars = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);

     QVector<QString> labels;
     QVector<double> ticks;
     ticks << 1 << 2 << 3 << 4;
     labels << "jan" << "Feb" << "Mar" << "Apr";
     ui->customPlot->xAxis->setAutoTicks(false);
     ui->customPlot->xAxis->setAutoTickLabels(false);
     ui->customPlot->xAxis->setTickVector(ticks);
     ui->customPlot->xAxis->setTickVectorLabels(labels);
     ui->customPlot->xAxis->setTickLabelRotation(60);
     ui->customPlot->xAxis->setSubTickCount(0);
     ui->customPlot->xAxis->setTickLength(0, 4);
     ui->customPlot->xAxis->grid()->setVisible(true);


     ui->customPlot->addPlottable(bars);
     bars->setData(datax, datay2);
     bars->setBrush(QColor(180, 00, 120, 50));
     bars->setPen(QColor(180, 00, 120));
     bars->setWidth(0.15);
     bars->setBarsGroup(group1);

     bars = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
     ui->customPlot->addPlottable(bars);
     ui->customPlot->xAxis->setRange(0.1, 4.9);
     ui->customPlot->yAxis->setRange(0, 105);
     ui->customPlot->xAxis->setAutoTickStep(false);
     ui->customPlot->xAxis->setTickStep(1);

*/
     //legends
     ui->customPlot->legend->setVisible(true);
     ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
     ui->customPlot->legend->setBrush(QColor(255, 255, 255, 200));
     QPen legendPen;
     legendPen.setColor(QColor(130, 130, 130, 200));
     ui->customPlot->legend->setBorderPen(legendPen);
     QFont legendFont = font();
     legendFont.setPointSize(10);
     ui->customPlot->legend->setFont(legendFont);
     ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);



}
