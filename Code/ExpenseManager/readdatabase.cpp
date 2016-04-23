
// Author: Ankit Luv Mittal

#include "readdatabase.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>


    //Constructor
    ReadDatabase:: ReadDatabase(){

    }

    // Check if user name is available
    ReadDatabase:: ChkUserName(string userName,
                               bool& NotAvailable){

        ifstream f("UserNames.dat");
        string line;
        while (!f.eof()) {
        getline(f,line);
        if (line.length() == 0 || line[0] == '-')
            ;   // "IGNORE LINE\n";
        else if (line == userName){
                NotAvailable = 1;
                break;
            }
        else
                NotAvailable = 0;
        }
      system("pause");
        return 0;
    }


    // Get User Info
    ReadDatabase:: ReadUserInfo(string userName,
                                string& firstName,
                                string& lastName,
                                string& password,
                                string& securityAns){

        ifstream f("SpecificUserName.dat");
        string line;
        int i=0;
        while (!f.eof()) {
        getline(f,line);
        if (line == userName || i>0){
            switch (i){
                case 1 : firstName = line;
                            break;
                case 2 : lastName = line;
                            break;
                case 3 : password = line;
                            break;
                case 4 : securityAns = line;
                            break;
                default: 	break;
            }
            i++;
        }
        if (i>4)
            break;
        }
          system("pause");
          return 0;
    }


    //Get password from database
    ReadDatabase:: ReadPassword(string userName,
                                string& password){

        string NoUse1,NoUse2, NoUse3;

        ReadDatabase:: ReadUserInfo(userName,
                                    NoUse1,
                                    NoUse2,
                                    password,
                                    NoUse3);
    }

    //Get Security Answer
    ReadDatabase:: ReadSecurityAnswer(string userName,
                                      string& securityAnswer){

        string NoUse1,NoUse2, NoUse3;

        ReadDatabase:: ReadUserInfo(userName,
                                    NoUse1,
                                    NoUse2,
                                    NoUse3,
                                    securityAnswer);
    }

    // Get the Transaction details from Database
    ReadDatabase:: ReadTransaction(int& type,
                                   double& amount,
                                   string& description,
                                   TranCategory_t& category,
                                   PaymentType_t& paymentType,
                                   Date date){

        ifstream f("SpecificUserName.dat");
        string line;
        int i=0;
        while (!f.eof()) {
        getline(f,line);
        if (line == date || i>0){
            switch (i){
                case 1 : istringstream (line) >> type;
                            break;
                case 2 : istringstream (line) >>amount;
                            break;
                case 3 : description = line;
                            break;
                case 4 : category = line;
                            break;
                case 5 : paymentType = line;
                            break;
                default: 	break;
            }
            i++;
        }
        if (i > 5){
            break;
        }
    }
      system("pause");
    }

    // Backend needs to implement readtransaction repeatedly
    // Read Data for graphs
   // ReadDatabase:: ReadGraphData(Date firstDate, Date lastDate){
     //   ReadDatabase:: ReadTransaction (type, amount, description, category, paymentType, date);
    //}

