/*\file	transaction.h
*
* \brief	Transaction Header File containing class definition
*
* Revision History  :
*   Date            Author          Change(Describe the changes made)
*   04.17.2016      Amit Bhorania   Created File and added class definition
*   04.23.2016      Amit Bhorania
*
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

// Header Files
#include "enums.h"
#include "date.h"

using namespace std;

// Transaction Entry
class Transaction: public Date
{
private:
    TranType_t type;
    double amount;
    string description;
    TranCategory_t category;
    PaymentType_t paymentType;
public:
    // Constructor
    Transaction(
            TranType_t type = EXPENSE,
            double amount = 0,
            string des = "Expense Entry",
            TranCategory_t category = OTHER1,
            PaymentType_t paymentType = CASH,
            int month = 1,
            int day = 1,
            int year = 2016
            );

    // Method to Get the Transaction details given by User
    void getTransactionDetails();

    // Send the Transaction Details to DataBase to make an entry
    void sendTransactionToDatabase();

    // Get/Set Methods
    TranType_t getType();
    double getAmount();
    string getDescription();
    TranCategory_t getCategory();
    PaymentType_t getPaymentType();

    void setType(TranType_t t);
    void setAmount(double amount);
    void setDescription(string s);
    void setCategory(TranCategory_t category);
    void setPaymentType(PaymentType_t paymentType);
    void setDate(int month, int day, int year);
};

#endif // TRANSACTION_H
