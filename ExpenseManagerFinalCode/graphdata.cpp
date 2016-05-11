/*\file	GraphData.cpp
*
* \brief	GraphData Header File containing class definition
*
* Revision History  :
*   Date            Author              Change(Describe the changes made)
*   05.07.2016      Ankit Luv Mittal    Added Methods of Graphdata Class
*   05.08.2016      Ankit & Amit        Updated methods according to Integration of GUI, Backend & Database
*   05.09.2016      Amit Bhorania       Code Clean up
*/

#include <QDebug>
#include <QDir>
#include "graphdata.h"
#include <cstring>
#include <iostream>
#include <string>

extern string dir;

// create fileName variable corresponding to specific userName
GraphData::GraphData(string userName): userName (userName){

}

//Load last 6 days' expense & income into respective vector
void GraphData:: LastSixDays(vector<double>& sixDays_Expense,
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

    f.open(dir.c_str(), ios_base::in);
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

//Load last 6 Months expense & income into respective vector
void GraphData:: LastSixMonths(vector<double>& sixMonths_Expense,
                                 vector<double>& sixMonths_Income, Date date){
    ifstream f;
    vector<string> result;
    int index;
    int y_index;
    int y = date.getYear();
    int m = date.getMonth();
    string line;

    const char del = ',';

    f.open(dir.c_str(), ios_base::in);
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

//Load last 6 Years expense & income into respective vector
void GraphData:: LastSixYears(vector<double>& sixYears_Expense,
                                 vector<double>& sixYears_Income, Date date){
    ifstream f;
    vector<string> result;
    int index;
    int y = date.getYear();
    string line;
    const char del = ',';

    f.open(dir.c_str(), ios_base::in);
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

// Split the Read line by ',' into vector of string
void GraphData::split(vector<string> &result, string &str, char delimiter) {
    stringstream ss(str); // Turn the string into a stream.
    string temp;

    while(getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
}

GraphData::~GraphData() {}
