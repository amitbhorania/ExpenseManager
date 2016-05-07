/*\file	ReadDatabase.h
*
* \brief	ReadDatabase Header File containing class definition
*
* Revision History  :
*   Date            Author              Change(Describe the changes made)
*   05.07.2016      Ankit Luv Mittal    Added date as private member of class and
*					extrated date from the transaction object
*
*
*/

#ifndef READDATABASE_H
#define READDATABASE_H

//Header Files
#include <writedatabase.h>
#include <transaction.h>
#include <date.h>
#include <enums.h>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

// Read all content from Database
class ReadDatabase {
private:
    string fileName,
           userName,
           date;
public:
    //Create file Name corresponding to user or a default file
    ReadDatabase(string userName = "ExpenseManager");

    // Load the Transaction details from Database
    ReadTransaction(Transaction& data);

#if 0

    // Check if user name is available
    ChkUserName(string userName,
                bool available);

    //Load User Info from Database
    ReadUserInfo(string userName,
                 string& firstName,
                 string& lastName,
                 string& password,
                 string& securityAns);

    //Load password from database
    ReadPassword(string userName,
                 string& password);

    //Load Security Answer
    ReadSecurityAnswer(string username,
                       string& securityAnswer);
#endif

};

#endif // READDATABASE_H
