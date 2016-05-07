
// Author: Ankit Luv Mittal

#include "readDB.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

//Constructor
ReadDatabase:: ReadDatabase(){

}

// Get the Transaction details from Database
void ReadDatabase:: ReadTransaction(Transaction& data){

    ifstream f;
    int day;
    int month;
    int year;
    string line;
    cout << "\nOpening the Amit_Output.txt file";
    f.open("E:\\Stevens\\C++\\Projects\\GitHub\\ExpenseManager\\Code\\ExpenseManager\\Test\\Amit_Output.txt", ios::app);
    int i=0;
    while (!f.eof()) {
        //f >> month >> day >> year;
        //cout << "\n Date :";
        getline(f,line);
        cout << "\nRead Data = " << line;
#if 0
        if (line == date || i>0){
            switch (i){
            case 1 : istringstream (line) >> type;
                break;
            case 2 : istringstream (line) >>amount;
                break;
            case 3 : description = line;
                break;
            case 4 : category = line;
                break;
            case 5 : paymentType = line;
                break;
            default: 	break;
            }
            i++;
        }
        if (i > 5){
            break;
        }
#endif
    }

}

// Backend needs to implement readtransaction repeatedly
// Read Data for graphs
// ReadDatabase:: ReadGraphData(Date firstDate, Date lastDate){
//   ReadDatabase:: ReadTransaction (type, amount, description, category, paymentType, date);
//}

