/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on August 6, 2014, 3:30 AM
 * Purpose: Encrypt input text
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
const int SIZE=255;

//Function Prototypes
string encryptDecrypt(string,string);

//Begin execution
int main(int argc, char** argv) {
    
    //Seed RNG
    srand(time(0));
    
    //Declare and initialize variables
    string message;
    string key;
    ofstream code;
    ofstream jumbled;
    ofstream readable;
    code.open("key.txt");
    jumbled.open("encrypted_message.txt");
    readable.open("unencrypted_message.txt");
    
    //Input character string
    cout << "Enter the message you want encrypted:" << endl;
    getline(cin,message);
    
    //Generate encryption key
    for(int i=0; i<message.size(); i++){
        key[i]=rand()%26+97;
        code << key[i];
    }
    
    //Encrypt & Decrypt message
    string encrypted = encryptDecrypt(message,key);
    string unencrypted = encryptDecrypt(encrypted,key);
    
    //Write to file
    jumbled << encrypted;
    readable << unencrypted;
    
    //Close files
    code.close();
    jumbled.close();
    readable.close();
    
    //Finish him!!
    return 0;
}

string encryptDecrypt(string encrypt, string key){
    string output=encrypt;
    
    for(int i=0; i<encrypt.size(); i++){
        output[i]=encrypt[i] ^ key[i];
    }
    return output;
}