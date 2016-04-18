/*\ file transaction.h
 *
 *\ Brief    Header file containing class definition
 *
 * Revision History :
 * Date        Author            Changes
 * 04/18/2016  Vrushali Gaikwad  Createdc file and added members and methods
 *
 *
 */
#ifndef TRANSACTION_H
#define TRANSACTION_H

// class to handle transaction given by user
class transaction
{
private:
    double income_type;
    double payment;
    string category;
    string creditordebit;
    transcategory transaction;
    paymentype payment;

public:
    // constructor
    transaction();
    // show Method
    // Method to Display Transaction Window
            ShowTransactionPage();

            // Method to Display Amount Field
            ShowAmountTextBox();

            // Method to Display Description Field
            ShowDescriptionTextBox();

            // Method to Display Category Field
            ShowCategoryTextBox();

            // Method to Display Method of Payment Field
            ShowPaymentTypeTextBox();

            // Method to Display Date Selection
            ShowDateField();

            // Method to Display Submit button for Income/Expense Transaction
            ShowSubmitButton();

};

#endif // TRANSACTION_H
