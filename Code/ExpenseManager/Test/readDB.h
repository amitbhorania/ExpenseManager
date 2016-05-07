
// Author: Ankit Luv Mittal

#ifndef READDATABASE_H
#define READDATABASE_H

#include "transaction.h"

// Class to Read content from Database
class ReadDatabase {

public:
    //Constructor
    ReadDatabase();

    // Check if user name is available
    ChkUserName(string userName,
                bool available);

    // Get User Info
    ReadUserInfo(string userName,
                 string& firstName,
                 string& lastName,
                 string& password,
                 string& securityAns);

    //Get password from database
    ReadPassword(string userName,
                 string& password);

    //Get Security Answer
    ReadSecurityAnswer(string username,
                       string& securityAnswer);

    // Get the Transaction details from Database
    void ReadTransaction(Transaction& data);

};

#endif // READDATABASE_H
