/*\file	WriteDatabase.h
*
* \brief	WriteDatabase Header File containing class definition
*
* Revision History  :
*   Date            Author              Change(Describe the changes made)
*   05.07.2016      Ankit Luv Mittal    Added private members and Methods to Class
*/

#ifndef WRITEDATABASE_H
#define WRITEDATABASE_H

//Header Files
#include <readdatabase.h>
#include <transaction.h>
#include <date.h>
#include <enums.h>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

// Write content into Database
class WriteDatabase {
private:
    string userName;
    string fileName;

public:
    // Constructor
    WriteDatabase(string userName = "ExpenseManager");

    // Store the Transaction Details to DataBase
    void WriteTransaction(Transaction& tran);

    // Reset the data
    void ResetUserData();

    // Methods for Future Implementation
#if 0
    // Store the Transaction Details to DataBase
    WriteNewPassword(string userName,
                     string new_pass,
                     Date date);
    //Store User Info
    WriteUserInfo(string firstName,
                  string lastName,
                  string userName,
                  string password,
                  string securityAns,
                  Date date,
                  bool acknowledgement);

#endif

};

#endif // WRITEDATABASE_H
