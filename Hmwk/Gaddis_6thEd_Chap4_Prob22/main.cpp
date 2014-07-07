/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 7, 2014, 11:21 AM
 * Purpose: Calculate the charges for a long distance call
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin execution
int main(int argc, char** argv) {

    //Declare and initialize variables
    float rate1=0.12, rate2=0.55, rate3=0.35;   //Rates from 0000-0659, 0700-1900, 1901-2359
    int min;
    float time;
    bool loop=true;
    
    //User input
    cout << "This program will calculate the cost of your recent long distance call." << endl;
    cout << "Please enter the duration of your phone call, in minutes: ";
    cin >> min;
    do{
        cout << "What time was the call made? (Format HH.MM)" << endl;
        cin >> time;
    
    //Output
        cout << setprecision(2) << fixed;
        if(time>=00.00 && time<=06.59){
            cout << "Your charges, for the call lasting " << min << " minutes, is $" << min*rate1 << endl;
            loop=false;
            break;
            }
        else if(time>=07.00 && time<=19.00){
            cout << "Your charges, for the call lasting " << min << " minutes, is $" << min*rate2 << endl;
            loop=false;
            break;
            }
        else if(time>=19.01 && time<=23.59){
            cout << "Your charges, for the call lasting " << min << " minutes, is $" << min*rate3 << endl;
            loop=false;
            break;
            }
        else{
            cout << "You did not select an appropriate time for the start of the phone call, please try again." << endl;
            }
    }while(loop);
    
    //Finish him!!
    return 0;
}

