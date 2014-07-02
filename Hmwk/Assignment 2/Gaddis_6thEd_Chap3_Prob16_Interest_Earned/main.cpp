/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 2, 2014, 12:00 AM
 * Purpose: Calculate interest earned in savings
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User-defined Libraries

//Global constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {

    //Declare and initialize variables
    float rate;     //Interest rate
    float princip;  //Principal
    short numComp;  //Number of times compounded
    float inter;    //Interest earned
    float amt;      //Amount in savings
    
    //User inputs
    cout << "What is the principal on the account? $";
    cin >> princip;
    cout << "What is the APR on the account? ";
    cin >> rate;
    cout << "How many times has the interest compounded? ";
    cin >> numComp;
    
    //Calculations
    rate = rate/1200;
    amt = princip * pow(1 + rate/numComp, numComp);
    inter = amt - princip;
    rate = rate * 1200;
    
    //Display data
    cout << setw(20) << "Interest Rate:" << setw(2) << " " << setw(10) << rate << "%" << endl;
    cout << setw(20) << "Times compounded:" << setw(2) << " " << setw(10) << numComp << endl;
    cout << setprecision(2) << fixed;
    cout << setw(20) << "Principal:" << setw(2) << "$" << setw(10) << princip << endl;
    cout << setw(20) << "Interest:" << setw(2) << "$" << setw(10) << inter << endl;
    cout << setw(20) << "Amount in Savings:" << setw(2) << "$" << setw(10) << amt << endl;
    
    //Finish him!!
    return 0;
}

