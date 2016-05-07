/*\file	transaction.cpp
*
* \brief	Transaction Source File containing required methods
*
* Revision History  :
*   Date            Author          Change(Describe the changes made)
*   04.17.2016      Amit Bhorania   Created File and Framework
*
*
*/

#include "transaction.h"
#include "writeDB.h"
#include "readDB.h"

// Constructor
Transaction::Transaction(
        TranType_t type,
        double amount,
        string des,
        TranCategory_t category,
        PaymentType_t paymentType,
        int month,
        int day,
        int year
        ):type(type),amount(amount),description(des), category(category), paymentType(paymentType), Date(month, day, year)
{

}

// Method to Get the Transaction details given by User
void Transaction::getTransactionDetails()
{
    // Create Database Object and Call the method to read Transaction
    ReadDatabase   RDB;
    RDB.ReadTransaction(*this);
}

// Send the Transaction Details to DataBase to make an entry
void Transaction::sendTransactionToDatabase()
{
    // Create Database Object and Call the method to write Transaction
    WriteDatabase   WDB;
    WDB.WriteTransaction(*this);
}

// Get/Set Methods

TranType_t Transaction::getType()
{
    return this->type;
}

double Transaction::getAmount()
{
    return this->amount;
}

string Transaction::getDescription()
{
    return this->description;
}

TranCategory_t Transaction::getCategory()
{
    return this->category;
}

PaymentType_t Transaction::getPaymentType()
{
    return this->paymentType;
}

void Transaction::setType(TranType_t t)
{
    this->type = t;
}

void Transaction::setAmount(double amount)
{
    this->amount = amount;
}

void Transaction::setDescription(string s)
{
    this->description = s;
}

void Transaction::setCategory(TranCategory_t category)
{
    this->category = category;
}

void Transaction::setPaymentType(PaymentType_t paymentType)
{
    this->paymentType = paymentType;
}

void Transaction::setDate(int month, int day, int year)
{
    this->setMonth(month);
    this->setDay(day);
    this->setYear(year);
}
