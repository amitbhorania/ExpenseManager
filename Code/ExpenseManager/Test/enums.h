/*\file	enums.h
*
* \brief	Header File containing different Enums definitions
*
* Revision History  :
*   Date            Author          Change(Describe the changes made)
*   04.17.2016      Amit Bhorania   Created File and added Enum definitions
*
*
*/

#ifndef ENUMS_H
#define ENUMS_H

// Type of Transaction
enum TranType_t {
    INCOME = 0,
    EXPENSE
};

// Transaction Category
enum TranCategory_t {
    TRAVELLING = 0,
    FOOD,
    SHOPPING,
    EDUCATION,
    MEDICAL,
    RENT,
    OTHER,
    MAX_TRANCATEGORY
};

// Type of Payment
enum PaymentType_t {
    CASH = 0,
    CREDIT_CARD,
    DEBIT_CARD,
    NET_BANKING,
    MAX_PAYMENTTYPE,
};

#endif // ENUMS_H
