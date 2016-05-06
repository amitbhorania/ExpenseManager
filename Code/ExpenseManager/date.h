/*\file	date.h
*
* \brief	Date Header File containing class definition
*
* Revision History  :
*   Date            Author              Change(Describe the changes made)
*   05.03.2016      Vrushali gaikwad    Created File and added members and methods
*
*
*/

#ifndef DATE_H
#define DATE_H

#include <string>

// Date Class to handle date in Transaction Entries
class Date
{
private:
    int month;
    int day;
    int year;
public:
    // Constructor
    Date(int month = 1, int day = 1, int year = 2016);

    // Get/Set Methods
    int getMonth();
    int getDay();
    int getYear();

    void setMonth(int month);
    void setDay(int day);
    void setYear(int year);

    // Get a Date as String
    //string getDateString();
};

#endif // DATE_H
