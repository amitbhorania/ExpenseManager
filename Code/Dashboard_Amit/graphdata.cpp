/*\file	GraphData.cpp
*
* \brief	GraphData Header File containing class definition
*
* Revision History  :
*   Date            Author              Change(Describe the changes made)
*   05.07.2016      Ankit Luv Mittal    Added date as private member of 
                    class
*
*/

#define START_YEAR  2010
#define MAX_YEAR  10

#include <QDebug>
#include <QDir>
#include "graphdata.h"
#include <cstring>
#include <iostream>
#include <string>

//using namespace std;

// create fileName variable corresponding to specific userName
GraphData::GraphData(string userName): userName (userName){
    //this->fileName = userName + ".dat";
    //f.open("E:\\Stevens\\C++\\Projects\\Dashboard_final\\ExpenseManager.dat", ios_base::in);
    //memset(incomeValue, 0, sizeof(int)*2*12*31);
    //memset(expenseValue, 0, sizeof(int)*2*12*31);
    //for(int i = 0; i < 2; i++) {
    //for(int j = 0; j < 12; j++) {
    //            for(int k = 0; k < 31; k++) {
    //              incomeValue[k] = 0;
    //            expenseValue[k] = 0;
    //      }
    //}
    //}
    //qDebug() << QString::number(incomeValue[0]);
    //qDebug() << QString::number(incomeValue[0]);
}

#if 0
void GraphData::calculateGraphData() {
    ifstream f;
    f.open("E:\\Stevens\\C++\\Projects\\Dashboard_final\\ExpenseManager.dat", ios_base::in);
    if(f.is_open() == false) {
        qDebug() << "File is not Opened";
        return;
    }
    //while (!f.eof()) {

    //}
}
#endif

//Sum of trasactions today or the date provided
void GraphData:: figures_of_a_day(double& expense, double& income, Date date){
    //qDebug() << "Inside figures_of_a_day function";
    double temp_expense=0;
    double temp_income=0;
    double amount;
    int type;

    //Get file name using user name
    //ifstream f(this->fileName.c_str(), ifstream::in);
    ifstream f;

    f.open("E:\\Stevens\\C++\\Projects\\Dashboard_final\\ExpenseManager.dat", ios_base::in);

    if(f.is_open() == false) {
        return;
    }

    //qDebug() << "File Successfully Opened";

    //qDebug() << "Done Reading the File";

    string line;
    int i=0;
    bool read= false;
    stringstream date_string;
    date_string << date.getMonth() << "/" << date.getDay() << "/" << date.getYear();

    this->date = date_string.str();
    //qDebug() << "Before While Loop of Figures of a Day function";
    while (!f.eof()) {
        getline(f,line);
        //qDebug() << "GetLine Done";
        //qDebug() << QString::fromStdString(line);
        //qDebug() << QString::fromStdString(this->date);
        if (line == this->date || i>0){ //need to work on the condition if date will be checked or not
            //qDebug() << "Inside first if";
            switch (i)
            {
            case 1 :
            {
                //qDebug() << "Inside Case 1";
                istringstream (line) >> type;
                break;
            }
            case 2 :
            {
                //qDebug() << "Inside Case 2";
                istringstream (line) >> amount;
                read = true;
                break;
            }
            default:
                //qDebug() << "Inside Default Case";
                break;
            }
            i++;
            if (read){
                //qDebug() << "Inside if(read)";
                if (type ==0)
                    temp_income += amount;
                else
                    temp_expense += amount;
                i=0;
                read= false;

            }
        }
    }
    //qDebug() << "While Loop of Figures of a Day function over";
    expense = temp_expense;
    income = temp_income;
}

//Load last 6 days' expense & income into respective vector
void GraphData:: LastSixDaysNew(vector<double>& sixDays_Expense,
                                 vector<double>& sixDays_Income, Date date){
    ifstream f;
    vector<string> result;
    int index;
    int y_index;
    int m_index;
    int y = date.getYear();
    int m = date.getMonth();
    int d = date.getDay();
    string line;

    const char del = ',';

    f.open("E:\\Stevens\\C++\\Projects\\Dashboard_final\\ExpenseManager.dat", ios_base::in);
    if(f.is_open() == false) {
        qDebug() << "File is not Opened";
        return;
    }

    for(int k =0; k < 6; k++) {
        sixDays_Expense[k] = 0;
        sixDays_Income[k] = 0;
    }

    while (!f.eof()) {
        getline(f,line);
        if(line == "\0"){
            continue;
        }

        result.clear();
        GraphData::split(result, line, del);

        // Year Index
        y_index = y - stoi(result[2]);

        // Same Year
        if(y_index == 0) {
            m_index = m - stoi(result[0]);
            // Same Month
            if(m_index == 0) {
                index = d - stoi(result[1]);
            }
            // 1 Month Difference
            else if(m_index == 1) {
                index = (d+31) - stoi(result[1]);
            }
            else {
                // Do Nothing
                continue;
            }
        }
        // 1 Year Difference
        else if (y_index == 1) {
            m_index = 12+m - stoi(result[0]);
            // Current Month = 1 & Second Month = 12
            if(m_index == 1) {
                index = (d+31) - stoi(result[1]);
            }
            else {
                // Do Nothing
                continue;
            }
        }
        else {
            // Do Nothing
            continue;
        }

        if(index < 6 && index >= 0) {
            if(stoi(result[3]) == 0) {
                sixDays_Income[index] += stod(result[4]);
            }
            else {
                sixDays_Expense[index] += stod(result[4]);
            }
        }
    }
    f.close();
}

//Load last 6 days' expense & income into respective vector
void GraphData:: LastSixDays(vector<double>& sixDays_Expense,
                             vector<double>& sixDays_Income, Date date){
    double expense, income;
    int m= date.getMonth();
    int d = date.getDay();
    int y = date.getYear();
    for (int i=0; i < 6; i++){
        figures_of_a_day(expense, income, date);
        sixDays_Expense.push_back(expense);
        sixDays_Income.push_back(income);
        d--;
        if(d == 0) {
            d = 31;
            date.setDay(d);
            m--;
            if (m == 0){
                m = 12;
                y--;
                date.setYear(y);
            }
            date.setMonth(m);
        }
        date.setDay(d);
    }
}

void GraphData:: LastSixMonthsNew(vector<double>& sixMonths_Expense,
                                 vector<double>& sixMonths_Income, Date date){
    ifstream f;
    vector<string> result;
    int index;
    int y_index;
    int y = date.getYear();
    int m = date.getMonth();
    string line;

    const char del = ',';

    f.open("E:\\Stevens\\C++\\Projects\\Dashboard_final\\ExpenseManager.dat", ios_base::in);
    if(f.is_open() == false) {
        qDebug() << "File is not Opened";
        return;
    }

    for(int k =0; k < 6; k++) {
        sixMonths_Expense[k] = 0;
        sixMonths_Income[k] = 0;
    }

    while (!f.eof()) {
        getline(f,line);
        if(line == "\0"){
            continue;
        }

        result.clear();
        GraphData::split(result, line, del);

        // Year Index
        y_index = y - stoi(result[2]);

        // Check Whether Year is current or Previous or other
        if(y_index == 0) {
            // Simply deduct the Month values
            index = m - stoi(result[0]);
        }
        else if (y_index == 1) {
            // Year is previous so add 12 to current month to make both in same level
            index = (m+12) - stoi(result[0]);
        }
        else {
            // Other Years
            // Do Nothing
            continue;
        }

        if(index < 6 && index >= 0) {
            if(stoi(result[3]) == 0) {
                sixMonths_Income[index] += stod(result[4]);
            }
            else {
                sixMonths_Expense[index] += stod(result[4]);
            }
        }
    }
    f.close();
}

//Load last 6 months' expens & income into respective vector
void GraphData:: LastSixMonths(vector<double>& sixMonths_Expense,
                               vector<double>& sixMonths_Income, Date date){
    //qDebug() << "Inside LastSixMonths Function";
    double expense, income;
    double expense_month=0;
    double income_month=0;
    int d= date.getDay();
    int m= date.getMonth();
    int y = date.getYear();
    //qDebug() << "Before For Loop";
    for (int j=0; j<6; j++){
        expense_month = 0;
        income_month = 0;
        while (d >0){
            //qDebug() << "Before calling figures_of_a_day function";
            figures_of_a_day(expense, income, date);
            expense_month += expense;
            income_month += income;
            d--;
            date.setDay(d);
        }
        //qDebug() << "Inside For - While Loop Over";

        sixMonths_Expense.push_back(expense_month);
        sixMonths_Income.push_back(income_month);
        m--;
        if (m==0){
            m= 12;
            y--;
            date.setYear(y);
        }
        date.setMonth(m);
        d= 31;
        date.setDay(d);
    }
    //qDebug() << "Function Over";
}

void GraphData:: LastSixYearsNew(vector<double>& sixYears_Expense,
                                 vector<double>& sixYears_Income, Date date){
    ifstream f;
    vector<string> result;
    int index;
    int y = date.getYear();
    string line;
    const char del = ',';

    f.open("E:\\Stevens\\C++\\Projects\\Dashboard_final\\ExpenseManager.dat", ios_base::in);
    if(f.is_open() == false) {
        qDebug() << "File is not Opened";
        return;
    }

    while (!f.eof()) {
        getline(f,line);
        if(line == "\0"){
            continue;
        }

        result.clear();
        GraphData::split(result, line, del);

        index = y - stoi(result[2]);

        if(index < 6 && index >= 0) {
            if(stoi(result[3]) == 0)
                sixYears_Income[index] += stod(result[4]);
            else
                sixYears_Expense[index] += stod(result[4]);
        }
    }
    f.close();
}

//Load last 6 years' expense & income into respective vector
void GraphData:: LastSixYears(vector<double>& sixYears_Expense,
                              vector<double>& sixYears_Income, Date date){

    qDebug() << "Inside LastSixYears Function";
    vector<double> sixMonths_Expense, sixMonths_Income;
    double yearExpense=0;
    double yearIncome=0;
    int d = date.getDay();
    int m = date.getMonth();
    int y = date.getYear();
    int j =6;
    qDebug() << "Before While Loop";
    while (j>0){
        qDebug() << "Inside while";
        for(int i=0; i<2; i++){
            qDebug() << "Inside for loop";
            while (m >0){
                qDebug() << "Inside 2nd while";
                LastSixMonths (sixMonths_Expense, sixMonths_Income, date);
                if (m-6 >= 0){
                    qDebug() << "Inside if";
                    for(vector<double>::iterator it = sixMonths_Expense.begin(); it != sixMonths_Expense.end(); ++it)
                        yearExpense += *it;

                    for(vector<double>::iterator it = sixMonths_Income.begin(); it != sixMonths_Income.end(); ++it)
                        yearIncome += *it;

                    m -= 6;
                    if(m == 0){
                        m= 12;
                        y--;
                        date.setYear(y);
                    }
                    date.setMonth(m);

                    d =31;
                    date.setDay(d);
                }
                else{
                    qDebug() << "Inside Else";
                    int i=0;
                    while (m>0){
                        yearExpense += sixMonths_Expense[i];
                        yearIncome += sixMonths_Income[i];
                        m--;
                        i++;
                    }
                    m = 12;
                    date.setMonth(m);
                    d =31;
                    date.setDay(d);
                    y--;
                    date.setYear(y);
                }
            }
        }
        j--;
        sixYears_Expense.push_back(yearExpense);
        sixYears_Income.push_back(yearIncome);
    }
    qDebug() << "While Over";
}

void GraphData::split(vector<string> &result, string &str, char delimiter) {
    stringstream ss(str); // Turn the string into a stream.
    string temp;

    while(getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
}

#if 0
GraphData::~GraphData() {
    //f.close();
}
#endif
