/*\file	WriteDatabase.h
*
* \brief	WriteDatabase Header File containing class definition
*
* Revision History  :
*   Date            Author              Change(Describe the changes made)
*   05.06.2016      Ankit Luv Mittal    Combined with other header files and class definition
*
*
*/


#include "writedatabase.h"

    //Create file Name variable corresponding to specific user Name
    WriteDatabase::WriteDatabase(string userName): userName(userName){
        fileName = userName + ".dat";
    }


    // Store the Transaction Details to DataBase
    WriteDatabase:: WriteTransaction(Transaction &data){
            ofstream filehandle;
            filehandle.open(this->fileName.c_str(), ios::app);
            filehandle << data.getMonth() << "\/" << data.getDay() << "\/" <<data.getYear() << "\n";
            filehandle << data.getType() << "\n";
            filehandle << data.getAmount() << "\n";
            filehandle << data.getDescription() << "\n";
            filehandle << data.getCategory() << "\n";
            filehandle << data.getPaymentType() << "\n\n" ;
            filehandle.close();
    }


    //Reset the data
    WriteDatabase::ResetUserData(){

        ofstream f;
        f.open(this->fileName.c_str(), ios::ate);
        f << "\n";
        f.close();
    }

    #if 0

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


    // User changing password and thus add new one to database
    WriteDatabase:: WriteNewPassword(string userName,
                                     string new_pass,
                                     Date date){

        fstream fileHandle(this->fileName.c_str());
        int i = 0;
        string strTemp;
        bool found = false;
        while(fileHandle >> strTemp)
        {
            if(strTemp == userName){
                found = true;
            }
            if (found) {
                if(i ==3){
                fileHandle << new_pass;
                found = false;
                i = -1;
                }
            i++;
            }
        }
    }

    //Reset the data
    WriteDatabase::ResetUserData(string userName ){
        fileName = userName + ".dat";
        ofstream f;
        f.open(fileName.c_str(), ios::ate);
        f << "\n";
        f.close;
    }

    #endif
