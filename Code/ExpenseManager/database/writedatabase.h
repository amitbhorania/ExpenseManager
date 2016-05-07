/*\file	WriteDatabase.h
*
* \brief	WriteDatabase Header File containing class definition
*
* Revision History  :
*   Date            Author              Change(Describe the changes made)
*   05.06.2016      Ankit Luv Mittal    Combined with other header files and class definition
*
*
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
string userName,
       fileName;
public:
    //Constructor
    WriteDatabase(string userName = "ExpenseManager");

    // Store the Transaction Details to DataBase
    WriteTransaction(Transaction& tran);

    //Reset the data
    ResetUserData();


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
