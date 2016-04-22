
// Author: Ankit Luv Mittal

#include "readdatabase.h"
#include <iostream>
#include <string>
#include <fstream>

    ReadDatabase:: ReadDatabase(){

    }

    // Check if user name is available
    ReadDatabase:: ChkUserName(string userName, bool available){
        ifstream f("UserNames.dat");
        string line;
        while (!f.eof()) {
        getline(f,line);
        if (line.length() == 0 || line[0] == '-')
            ;   //cout << "IGNORE LINE\n";
        else
            cout << line << "\n";
        }
      system("pause");
        return 0;
    }

    // Get User Info
    ReadDatabase:: ReadUserInfo(string userName, string& firstName, string& lastName, string& password, string& securityAns){

        ifstream f("SpecificUserName.dat");
        string line;
        int i=0;
        while (!f.eof()) {
        getline(f,line);
        if (line == username || i>0){
            switch (i){
                case 1 : FirstName = line;
                            break;
                case 2 : LastName = line;
                            break;
                case 3 : Password = line;
                            break;
                case 4 : SecurityAns = line;
                            break;
                default: 	break;
            }
            i++;
        }
    }
      system("pause");
      return 0;
    }

    //Get password from database
    ReadDatabase:: ReadPassword(string userName, string& password){
        string NoUse1,NoUse2, NoUse3;
        ReadDatabase:: ReadUserInfo(userName, NoUse1, NoUse2, password, NoUse3);

    }

    //Get Security Answer
    ReadDatabase:: ReadSecurityAnswer(string username, string& securityAnswer, string& password){
        string NoUse1,NoUse2, NoUse3;
        ReadDatabase:: ReadUserInfo(userName, NoUse1, NoUse2, password, securityAnswer);

    }

    // Get the Transaction details from Database
    ReadDatabase:: ReadTransaction(int& type,double& amount,string& description,TranCategory_t& category,
                    PaymentType_t& paymentType, Date date){
        ifstream f("SpecificUserName.dat");
        string line;
        int i=0;
        while (!f.eof()) {
        getline(f,line);
        if (line == date || i>0){
            switch (i){
                case 1 : type = line;
                            break;
                case 2 : amount = line;
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
            cout << type << "\n" << amount << "\n" << description << "\n" << category << "\n" << paymentType << "\n" << date << "\n";
            i=0;
        }
    }
      system("pause");
    }

    // Backend needs to implement readtransaction repeatedly
    // Read Data for graphs
   // ReadDatabase:: ReadGraphData(Date firstDate, Date lastDate){
     //   ReadDatabase:: ReadTransaction (type, amount, description, category, paymentType, date);
    //}

