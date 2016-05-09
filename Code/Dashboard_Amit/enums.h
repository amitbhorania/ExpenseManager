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
    RENT,
    MEDICAL,
    OTHER1,
    MAX_EXPENSECATEGORY = OTHER1,
    FRIEND,
    SALARY,
    PENSION,
    OTHER2,
    MAX_INCOMECATEGORY = OTHER2,
};

// Type of Payment
enum PaymentType_t {
    CASH = 0,
    CHEQUE,
    ONLINE_BANKING,
    CREDIT_CARD,
    DEBIT_CARD,
    OTHER,
    MAX_PAYMENTTYPE,
};

#endif // ENUMS_H
