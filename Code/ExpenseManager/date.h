/*\file	date.h
*
* \brief	Date Header File containing class definition
*
* Revision History  :
*   Date            Author          Change(Describe the changes made)
*   04.17.2016      Amit Bhorania   Created File and added members and methods
*
*
*/

#ifndef DATE_H
#define DATE_H

// Date Class to handle date in Transaction Entries
class Date
{
private:
    int month;
    int day;
    int year;
public:
    // Constructor
    Date();

    // Get/Set Methods
    getMonth();
    getDay();
    getYear();
    setMonth();
    setDay();
    setYear();

    // Get a Date String to print
    getDateString();
};

#endif // DATE_H
