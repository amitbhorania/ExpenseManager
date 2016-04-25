/*\file	date.cpp
*
* \brief	Date Source File containing required methods
*
* Revision History  :
*   Date            Author          Change(Describe the changes made)
*   04.17.2016      Amit Bhorania   Created File and Framework
*
*
*/

#include "date.h"

// Constructor
Date::Date(int month, int day, int year):month(month), day(day), year(year)
{
    // Nothing to Add here
}

// Get Methods
int Date::getMonth()
{
    return this->month;
}

int Date::getDay()
{
    return this->day;
}

int Date::getYear()
{
    return this->year;
}

// Set Methods
void Date::setMonth(int month)
{
    this->month = month;
}

void Date::setDay(int day)
{
    this->day = day;
}

void Date::setYear(int year)
{
    this->year = year;
}

#if 0
// Get a Date String to print
string Date::getDateString()
{

}
#endif
