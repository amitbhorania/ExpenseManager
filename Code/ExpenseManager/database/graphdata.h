/*\file	GraphData.h
*
* \brief	GraphData Header File containing class definition
*
* Revision History  :
*   Date            Author              Change(Describe the changes made)
*   05.07.2016      Ankit Luv Mittal    Added date as private member of 
					class
*
*/

#ifndef GRAPHDATA_H
#define GRAPHDATA_H

//Header Files
#include <writedatabase.h>
#include <readdatabase.h>
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
    string userName,
           fileName,
           date;
public:
    //Create file Name corresponding to user by taking user Name
    GraphData(string userName = "ExpenseManager");

    //Sum of trasactions today or the date provided
    figures_of_a_day(double& expense, double& income, Date date);

    //Load last 6 days' expense & income into respective vector
    LastSixDays(vector<double>& sixDays_Expense,
                vector<double>& sixDays_Income, Date date);

    //Load last 6 months' expens & income into respective vector
    LastSixMonths(vector<double>& sixMonths_Expense,
                  vector<double>& sixMonths_Income, Date date);

    //Load last 6 years' expense & income into respective vector
    LastSixYears(vector<double>& sixYears_Expense,
                 vector<double>& sixYears_Income, Date date);
};

#endif // GRAPHDATA_H
