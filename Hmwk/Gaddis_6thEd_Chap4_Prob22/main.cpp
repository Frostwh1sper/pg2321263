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
    int min, time;
    bool loop=true;
    
    //User input
    cout << "This program will calculate the cost of your recent long distance call." << endl;
    cout << "Please enter the duration of your phone call, in minutes: ";
    cin >> min;
    do{
        cout << "Enter 1 for calls made between midnight and 6:59AM" << endl;
        cout << "Enter 2 for calls made between 7AM and 7PM" << endl;
        cout << "Enter 3 for calls made between 7PM and 11:59PM" << endl;
        cin >> time;
    
    //Output
        cout << setprecision(2) << fixed;
        switch(time){
            case 1:{
                cout << "Your charges, for the call lasting " << min << " minutes, is $" << min*rate1 << endl;
                loop=false;
                break;
            }
            case 2:{
                cout << "Your charges, for the call lasting " << min << " minutes, is $" << min*rate2 << endl;
                loop=false;
                break;
            }
            case 3:{
                cout << "Your charges, for the call lasting " << min << " minutes, is $" << min*rate3 << endl;
                loop=false;
                break;
            }
            default:{
                cout << "You did not select an appropriate time for the start of the phone call, please try again." << endl;
            }
    }
    }while(loop);
    
    //Finish him!!
    return 0;
}

