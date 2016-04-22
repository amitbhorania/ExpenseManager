
// Author: Ankit Luv Mittal

#ifndef READDATABASE_H
#define READDATABASE_H



// Class to Read content from Database
class ReadDatabase {
private:
    int type;	// Income=0 or Expense=1
    double amount;
    string description;
    TranCategory_t category;	// Can take a String
    PaymentType_t paymentType;	// Cash/Credit/NetBanking
    Date date;	// Transaction Date

public:
    //Constructor
    ReadDatabase();

    // Check if user name is available
    ChkUserName(string userName, bool available);

    // Get User Info
    ReadUserInfo(string userName, string& firstName, string& lastName,
                 string& password, string& securityAns);

    //Get password from database
    ReadPassword(string userName, string& password);

    //Get Security Answer
    ReadSecurityAnswer(string username, string& securityAnswer, string& password);

    // Get the Transaction details from Database
    ReadTransaction(int& type,
    double& amount,
    string& description,
    TranCategory_t& category,
    PaymentType_t& paymentType,
    Date date);


    // Read Data for graphs
    ReadGraphData(Date firstDate, Date lastDate);
};

#endif // READDATABASE_H
