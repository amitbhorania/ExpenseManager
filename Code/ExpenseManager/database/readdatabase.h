/*\file	ReadDatabase.h
*
* \brief	ReadDatabase Header File containing class definition
*
* Revision History  :
*   Date            Author              Change(Describe the changes made)
*   05.06.2016      Ankit Luv Mittal    Combined with other header files and class definition
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
    String fileName;
    string userName;
public:
    //Create file Name corresponding to user or a default file
    ReadDatabase(string userName = "ExpenseManager");

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

    // Load the Transaction details from Database
    ReadTransaction(Transaction_t& t);

};

#endif // READDATABASE_H
