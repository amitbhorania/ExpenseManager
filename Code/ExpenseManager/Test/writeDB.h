// Ankit Luv Mittal

#ifndef WRITEDATABASE_H
#define WRITEDATABASE_H

#include "transaction.h"

// Class to Write content into Database
class WriteDatabase {

public:
    //Constructor
    WriteDatabase();

    //Store User Info
    WriteUserInfo(string firstName,
                  string lastName,
                  string userName,
                  string password,
                  string securityAns,
                  Date date
                  );

    // Store the Transaction Details to DataBase
    void WriteTransaction(Transaction& data);


    // Store the Transaction Details to DataBase
    WriteNewPassword(string userName,
                     string new_pass,
                     Date date);


    //Reset the data
    ResetUserData(string userName );
};

#endif // WRITEDATABASE_H
