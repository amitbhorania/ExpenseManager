/*\file	GraphData.h
*
* \brief	GraphData Header File containing class definition
*
* Revision History  :
*   Date            Author              Change(Describe the changes made)
*   05.06.2016      Ankit Luv Mittal    Created & combined with other header files
*                                       and class definition
*
*/


#include "graphdata.h"

    // create fileName variable corresponding to specific userName
    GraphData::GraphData(string userName): userName (userName){
            this->fileName = userName + ".dat";
    }

    //Sum of trasactions today or the date provided
    GraphData:: figures_of_a_day(double& expense, double& income, Date date){
            double temp_expense=0;
            double temp_income=0;
            double amount;
            int type;
            //Get file name using user name
            ifstream f(this->fileName.c_str());
            string line;
            int i=0;
            bool read= false;
            string date_string;
            date_string = date.getMonth() + "//" + date.getDay + "//" + date.getYear;
            while (!f.eof()) {
            getline(f,line);
            if (line == date_string || i>0){ //need to work on the condition if date will be checked or not
                switch (i){
                    case 1 : {istringstream (line) >> type;
                                break;}
                    case 2 : {istringstream (line) >> amount;
                                read = true;
                                break;}
                   default: 	break;
                }
                i++;
                if (read){
                        if (type ==0)
                            temp_income += amount;
                        else
                            temp_expense += amount;
                        i=0;
                        read= false;
                }
            }
        }
        expense = temp_expense;
        income = temp_income;
       }
    }

    //Load last 6 days' expense & income into respective vector
    GraphData:: LastSixDays(vector<double>& sixDays_Expense, vector<double>& sixDays_Income, Date date){
        double expense, income;
        int m= date.getMonth();
        int d = date.getDay();
        for (int i=0; i < 6; i++){
            figures_of_a_day(expense, income, date);
            sixDays_Expense.push_back(expense);
            sixDays_Income.push_back(income);
            d--;
            if (d=0){
                d=31;
                date.setDay(d);
                m--;
                if (m==0){
                    m= 12;
                    y--;
                    date.setYear(y);
                }
                date.setMonth(m);
            }
            date.setDay(d);
        }
    }

    //Load last 6 months' expens & income into respective vector
    GraphData:: LastSixMonths(vector<double>& sixMonths_Expense,
                              vector<double>& sixMonths_Income, Date date){
        double expense, income;
        double expense_month=0;
        double income_month=0;
        int d= date.getDay();
        int m= date.getMonth();
        for (int j=0; j<6; j++){
            while (d >0){
                figures_of_a_day(expense, income, date);
                expense_month += expense;
                income_month += income;
                d--;
                date.setDay(d);
            }
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
    }

    //Load last 6 years' expense & income into respective vector
    GraphData:: LastSixYears(string userName, vector<double>& sixYears_Expense,
                             vector<double>& sixYears_Income, Date date){


        vector<double> sixMonths_Expense, sixMonths_Income;
        double yearExpense=0;
        double yearIncome=0;
        int d = date.getDay();
        int m = date.getMonth();
        int y = date.getYear();
        int j =6;
        while (j>0){
            for(int i=0; i<2; i++){
                while (m >0){
                    LastSixMonths (userName, sixMonths_Expense, sixMonths_Income, date);
                    if (m-6 >= 0){

                        for((vector<double>::iterator it = sixMonths_Expense.begin(); it != sixMonths_Expense.end(); ++it))
                        yearExpense += *it;

                        for((vector<double>::iterator it = sixMonths_Income.begin(); it != sixMonths_Income.end(); ++it))
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
                        int i=0;
                        while (m>0){
                            yearExpense += sixMonths_Expense[i];
                            yearIncome += sixMonths_Income[i];
                            m--;
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
    }
