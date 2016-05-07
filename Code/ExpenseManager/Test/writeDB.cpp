// Ankit Luv Mittal

#include "writeDB.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

// Store the Transaction Details to DataBase
void WriteDatabase:: WriteTransaction(Transaction& data)
{
    ofstream filehandle;
    cout << "\nOpening the Amit_Output.txt file";
    filehandle.open("E:\\Stevens\\C++\\Projects\\GitHub\\ExpenseManager\\Code\\ExpenseManager\\Test\\Amit_Output.txt", ios::app);
    filehandle << data.getMonth() << "\\" << data.getDay() << "\\" <<data.getYear() << "\n";
    filehandle << data.getType() << "\n";
    filehandle << data.getAmount() << "\n";
    filehandle << data.getDescription() << "\n";
    filehandle << data.getCategory() << "\n";
    filehandle << data.getPaymentType() << "\n\n" ;
    filehandle.close();
    cout << "\nOperation completed";
}

//Constructor
WriteDatabase::WriteDatabase()
{

}
