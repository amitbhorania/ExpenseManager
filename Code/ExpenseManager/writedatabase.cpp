// Ankit Luv Mittal

#include "writedatabase.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>


WriteDatabase::WriteDatabase(){
}


//Store User Info
WriteDatabase::WriteUserInfo(string firstName,
                string lastName,
                string userName,
                string password,
                string securityAns,
                Date date,
                bool acknowledgement){

    ofstream filehandle;
    filehandle.open("test.dat", ios::app);
    filehandle << userName << "\n";
    filehandle << date << "\n";
    filehandle << firstName << "\n";
    filehandle << lastName << "\n";
    filehandle << password << "\n";
    filehandle << securityAns << "\n\n" ;
    filehandle.close();
    acknowledgement = 1;
}

// Store the Transaction Details to DataBase
WriteDatabase:: WriteTransaction(int type,
                    double amount,
                    string description,
                    TranCategory_t category,
                    PaymentType_t paymentType,
                    Date date,
                    bool acknowledgement){

    ofstream filehandle;
    filehandle.open("test.dat", ios::app);
    filehandle << date << "\n";
    filehandle << type << "\n";
    filehandle << amount << "\n";
    filehandle << description << "\n";
    filehandle << category << "\n";
    filehandle << paymentType << "\n\n" ;
    filehandle.close();
    acknowledgement = 1;
}


// Store the Transaction Details to DataBase
WriteDatabase:: WriteNewPassword(string userName,
                                 string new_pass,
                                 Date date){

    string userName;
    string firstName;
    string lastName;
    string password;
    string securityAns;
    //Read info
    userName.ReadUserInfo (userName,
                           firstName,
                           lastName,
                           password,
                           securityAns)
    password = new_pass;
    //ToDo: Need to find a way to either replace new data in the old place or atleast delete old data and add new one at the end
    //Write Info with new pass
    userName.WriteUserInfo (firstName,
                            lastName,
                            userName,
                            password,
                            securityAns,
                            date)
}


//Reset the data
WriteDatabase::ResetUserData(string userName ){

    ofstream f;
    f.open("SpecificUserName.dat", ios::ate);
    f << "\n";
    f.close;
}
