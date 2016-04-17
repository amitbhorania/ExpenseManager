/*\file	transaction.h
*
* \brief	Transaction Header File containing class definition
*
* Revision History  :
*   Date            Author          Change(Describe the changes made)
*   04.17.2016      Amit Bhorania   Created File and added class definition
*
*
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

// Header Files
#include "enums.h"
#include "date.h"

// Class for Transaction Entry
class Transaction
{
private:
    TranType_t type;
    double amount;
    string description;
    TranCategory_t category;
    PaymentType_t paymentType;
    Date date;
public:
    // Constructor
    Transaction();

    // Method to Get the Transaction details given by User
    getTransactionDetails();

    // Send the Transaction Details to DataBase to make an entry
    sendTransactionToDatabase();

    // Get/Set Methods
    getType();
    getAmount();
    getDescription();
    getCategory();
    getPaymentType();
    getDate();

    setType();
    setAmount();
    setDescription();
    setCategory();
    setPaymentType();
    setDate();
};

#endif // TRANSACTION_H
