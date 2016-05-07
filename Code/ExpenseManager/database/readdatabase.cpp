/*\file	ReadDatabase.h
*
* \brief	ReadDatabase Header File containing class definition
*
* Revision History  :
*   Date            Author              Change(Describe the changes made)
*   05.06.2016      Ankit Luv Mittal    Combined with other header files and class definition
*
*
*/


#include "readdatabase.h"


    // create fileName variable corresponding to specific userName
    ReadDatabase:: ReadDatabase(string userName
                                ): userName(userName)
    {
    this->fileName =userName + ".dat";
    }

    // Load Transaction details: Date, Type, Category, Amount, Description from Database
    ReadDatabase:: ReadTransaction(Transaction& data){

        ifstream f(this->fileName.c_str());
        string line;
        int i=0;
        int type_or_category_or_paymentType;
        double amount;
        while (!f.eof()) {
            getline(f,line);
            if (line == date || i>0){ //need to work on the condition if date will be checked or not
                switch (i){
                    case 1 : {istringstream (line) >> type_or_category_or_paymentType;
                             data.setType((TranType_t)type_or_category_or_paymentType);
                                break;}
                    case 2 : {istringstream (line) >>amount;
                             data.setAmount(amount);
                                break;}
                    case 3 : data.setDescription (line);
                                break;
                    case 4 : {istringstream (line) >> type_or_category_or_paymentType;
                             data.setCategory ((TranCategory_t) type_or_category_or_paymentType);
                                break;}
                    case 5 :{istringstream (line) >> type_or_category_or_paymentType;
                             data.setCategory ((PaymentType_t) type_or_category_or_paymentType);
                                break;}
                    default: 	break;
                }
                i++;
            }
            if (i > 5){
                i=0;
            }
        }
    }

#if 0
    // Check if user name is available
    ReadDatabase:: ChkUserName(string userName,
                               bool& NotAvailable){
        ifstream f("userNames.dat");
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
    }


    // Get User Info
    ReadDatabase:: ReadUserInfo(string userName,
                                string& firstName,
                                string& lastName,
                                string& password,
                                string& securityAns){

        ifstream f("userNames.dat");
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


    //Get previously stored password from database
    ReadDatabase:: ReadPassword(string userName,
                                string& password){

        string NoUse1,NoUse2, NoUse3;

        ReadDatabase:: ReadUserInfo(userName,
                                    NoUse1,
                                    NoUse2,
                                    password,
                                    NoUse3);
    }

    //Get previously stored Security Answer from backend
    ReadDatabase:: ReadSecurityAnswer(string userName,
                                      string& securityAnswer){

        string NoUse1,NoUse2, NoUse3;

        ReadDatabase:: ReadUserInfo(userName,
                                    NoUse1,
                                    NoUse2,
                                    NoUse3,
                                    securityAnswer);
    }

#endif
