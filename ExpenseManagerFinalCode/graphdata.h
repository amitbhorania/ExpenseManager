/*\file	GraphData.h
*
* \brief	GraphData Header File containing class definition
*
* Revision History  :
*   Date            Author              Change(Describe the changes made)
*   05.07.2016      Ankit Luv Mittal    Added private members & methods of class
*   05.08.2016      Ankit & Amit        Updated methods according to Integration of GUI, Backend & Database
*   05.09.2016      Amit Bhorania       Code Clean up
*/

#ifndef GRAPHDATA_H
#define GRAPHDATA_H

//Header Files
#include <transaction.h>
#include <date.h>
#include <enums.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

//Load Data required to plot graphs from Database and pass it to backend in a vector
class GraphData{
private:
    string userName;
    string fileName;
    string date;
public:
    //Create file Name corresponding to user by taking user Name
    GraphData(string userName = "ExpenseManager");
    ~GraphData();

    void split(vector<string> &result, string &str, char delimiter);

    //Load last 6 days' expense & income into respective vector
    void LastSixDays(vector<double>& sixDays_Expense,
                     vector<double>& sixDays_Income, Date date);

    //Load last 6 months' expens & income into respective vector
    void LastSixMonths(vector<double>& sixMonths_Expense,
                          vector<double>& sixMonths_Income, Date date);

    //Load last 6 years' expense & income into respective vector
    void LastSixYears(vector<double>& sixYears_Expense,
                         vector<double>& sixYears_Income, Date date);
};

#endif // GRAPHDATA_H
