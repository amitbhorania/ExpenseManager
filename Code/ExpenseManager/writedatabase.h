// Ankit Luv Mittal

#ifndef WRITEDATABASE_H
#define WRITEDATABASE_H


// Class to Write content into Database
class WriteDatabase {
private:
    int type;	// Income=0 or Expense=1
    double amount;
    string description;
    TranCategory_t category;	// Can take a String
    PaymentType_t paymentType;	// Cash/Credit/NetBanking
    Date date;	// Transaction Date

public:
    //Constructor
    WriteDatabase();

    //Store User Info
    WriteUserInfo(string firstName,
    string lastName,
    string userName,
    string password,
    string securityAns,
    Date date);

    // Store the Transaction Details to DataBase
    WriteTransaction(int type,
    double amount,
    string description,
    TranCategory_t category,
    PaymentType_t paymentType,
    Date date,
    bool acknowledgement);


    // Store the Transaction Details to DataBase
    WriteNewPassword(string new_pass);


    //Reset the data
    ResetUserData(string userName );
};

#endif // WRITEDATABASE_H
