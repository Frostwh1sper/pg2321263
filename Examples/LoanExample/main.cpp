/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 1, 2014, 1:08 PM
 * Purpose: Calculate loan payments
 */

//System Libraries
#include <iostream>     //I/O function library
#include <iomanip>      //Formatting of I/O
#include <cmath>        //Need for pow() function
using namespace std;

//User-defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {

    //Declare and initialize Variables
    float apr;          //Annual percentage rate
    float intRate;      //Interest rate per month
    float loanAmt;      //Loan amount
    short numPymt;      //Number of payments to pay off the loan
    float payment;      //Cost of each payment
    float inter;        //Amount of interest paid
    
    //User input
    cout << "What is your loan APR? ";
    cin >> apr;
    cout << "What is the total loan amount? $";
    cin >> loanAmt;
    cout << "In how many payments will the loan be payed off? ";
    cin >> numPymt;
    
    //Calculations
    intRate = apr / 1200;       //Converts APR to monthly interest rate
    payment = intRate * pow(1+intRate,numPymt) / (pow(1+intRate,numPymt)-1) * loanAmt;
    inter = payment * numPymt - loanAmt;
    
    //Output data
    cout << setprecision(2) << fixed;
    cout << "You will make " << numPymt << " monthly payments of $" << payment << ", and pay $" << inter << " in interest over the course of the loan." << endl;
    
    //Finish him!!
    return 0;
}

