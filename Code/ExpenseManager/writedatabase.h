// Author: Ankit Luv Mittal

#ifndef WRITEDATABASE_H
#define WRITEDATABASE_H


// Class to Write content into Database
class WriteDatabase {
private:
;
public:
    //Constructor
    WriteDatabase();

    //Store User Info
    WriteUserInfo(string firstName,
    string lastName,
    string userName,
    string password,
    string securityAns,
    Date date,
    bool acknowledgement);

    // Store the Transaction Details to DataBase
    WriteTransaction(Transaction_t tran);


    // Store the Transaction Details to DataBase
    WriteNewPassword(string userName,
                     string new_pass,
                     Date date);


    //Reset the data
    ResetUserData(string userName );

    //Write a vector for plotting graphs
    WriteGraphData();
};

#endif // WRITEDATABASE_H
