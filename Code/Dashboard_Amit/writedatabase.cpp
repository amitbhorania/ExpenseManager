/*\file	WriteDatabase.h
*
* \brief	WriteDatabase Header File containing class definition
*
* Revision History  :
*   Date            Author              Change(Describe the changes made)
*   04.25.2016      Ankit Luv Mittal    Added Methods of WriteDatabase class
*   05.08.2016      Ankit Luv Mittal    Updated Methods according to Integration
*/

#include "writedatabase.h"
extern string dir;

//Create file Name variable corresponding to specific user Name
WriteDatabase::WriteDatabase(string userName): userName(userName){
    fileName = userName + ".csv";
}

// Store the Transaction Details to DataBase
void WriteDatabase:: WriteTransaction(Transaction &data){
    ofstream filehandle;
    filehandle.open(dir.c_str(), ios_base::app);
    filehandle << data.getMonth() << "," << data.getDay() << "," <<data.getYear() << ",";
    filehandle << data.getType() << ",";
    filehandle << data.getAmount() << ",";
    filehandle << data.getCategory() << ",";
    filehandle << data.getDescription() << ",";
    filehandle << data.getPaymentType() << "\n" ;
    filehandle.close();
}

//Reset the data
void WriteDatabase::ResetUserData(){

    ofstream f;
    f.open(dir.c_str(), ios::ate);
    f << "\n";
    f.close();
}

// Methods for Future Implementation
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
