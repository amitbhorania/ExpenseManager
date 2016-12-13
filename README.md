Expense Manager
===============
Provided Code is to implement Expense Manager Desktop Application to keep track
of Incomes and Expenses, View Graphs and Figures on Daily, Monthly & Yearly basis.

Details of File Structure, Design, Implementation and Contribution is provided below

Platform
========
- QT Creator IDE
- Language - C++

FILE STRUCTURE
==============
- ExpenseManager.pro - QT Project File
- main.cpp - file with main() function to Start Application    

GUI
- addexpense.cpp/h	- Class to Show Expense Window 
- addincome.cpp/h		- Class to Show Income Window
- dashboard.cpp/h		- Dashboard Class to Show Dashboard & Graph
- qcustomplot.cpp/h	- Graph plotting Library Source and Header File

BackEnd
- date.cpp/h 			- Date Class to handle Date through out the Application
- transaction.cpp/h 	- Transaction Class to write/read transations in Database and GUI

Database
- readdatabase.cpp/h	- Class to Read the Transactions from Database
- writedatabase.cpp/h	- Class to Write the Transactions in Database
- graphdata.cpp/h		- Class to Read Last Six Days, Months and Year Data from .csv file

Contribution
============
Amit Bhorania
- BackEnd Module
- Dashboard Module

Vrushali Gaikwad
- Graph Module
- Add Expense Design
- Add Income Design

Ankit Luv Mittal
- Database Module
- Graph Data Read Module

Group Activity
- Integration, Testing & Bug Fixing


Design & Implementation
=======================
- The Whole Application is designed with Modular approach.
- We divided the modules among the team members as mentioned above.
- Each module is developed separately and unit tested
- Once done, all the modules were integrated in the Dashboard one by one with unit testing
