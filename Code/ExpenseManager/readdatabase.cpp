
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
        string fileName = userName + ".dat";
        ifstream f(fileName.c_str());
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
    ReadDatabase:: ReadTransaction(Transaction& data){

        ifstream f("SpecificUserName.dat");
        string line;
        int i=0;
        int category_or_type_or_pay;
        double amount;
        while (!f.eof()) {
        getline(f,line);
        if (line == date || i>0){ //need to work on the condition if date will be checked or not
            switch (i){
                case 1 : {istringstream (line) >> category_or_type_or_pay;
                         data.setType((TranType_t)category_or_type_or_pay);
                            break;}
                case 2 : {istringstream (line) >>amount;
                         data.setAmount(amount);
                            break;}
                case 3 : data.setDescription (line);
                            break;
                case 4 : {istringstream (line) >> category_or_type_or_pay;
                         data.setCategory ((TranCategory_t) category_or_type_or_pay);
                            break;}
                case 5 :{istringstream (line) >> category_or_type_or_pay;
                         data.setCategory ((PaymentType_t) cat_or_type_or_pay);
                            break;}
                default: 	break;
            }
            i++;
        }
        if (i > 5){
            break;
        }
    }
}

