// Author: Ankit Luv Mittal

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
                Date date){

    ofstream filehandle;
    filehandle.open("userNames.dat", ios::app);
    filehandle << userName << "\n";
    filehandle << date << "\n";
    filehandle << firstName << "\n";
    filehandle << lastName << "\n";
    filehandle << password << "\n";
    filehandle << securityAns << "\n\n" ;
    filehandle.close();
}

// Store the Transaction Details to DataBase
WriteDatabase:: WriteTransaction(Transaction& data){
        ofstream filehandle;
        cout << "Opening the test.dat file";
        filehandle.open("userNameSpecific.dat", ios::app);
        filehandle << data.getMonth() << "\\" << data.getDay() << "\\" <<data.getYear() << "\n";
        filehandle << data.getType() << "\n";
        filehandle << data.getAmount() << "\n";
        filehandle << data.getDescription() << "\n";
        filehandle << data.getCategory() << "\n";
        filehandle << data.getPaymentType() << "\n\n" ;
        filehandle.close();
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
                           securityAns);
    password = new_pass;
    //ToDo: Need to find a way to either replace new data in the old place or atleast delete old data and add new one at the end
    //Write Info with new pass
    userName.WriteUserInfo (firstName,
                            lastName,
                            userName,
                            password,
                            securityAns,
                            date);
}


//Reset the data
WriteDatabase::ResetUserData(string userName ){

    ofstream f;
    f.open("SpecificUserName.dat", ios::ate);
    f << "\n";
    f.close;
}

WriteDatabase::WriteGraphData(vector<double>& a, Date date ){
    int i= 6;
    int day;
    while (i>0){
    //ReadTransaction (date);
       a.push_back()
    day= date.readDay();
    date.setDay()= day-1;
    }
}
