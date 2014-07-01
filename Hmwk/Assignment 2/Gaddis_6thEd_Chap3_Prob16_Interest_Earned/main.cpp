/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on June 30, 2014, 7:32 PM
 * Purpose: Calculate the interest earned on an investment
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>    //Needed for pow() function

//User-defined Libraries

//Global Constants

//Function Prototypes

using namespace std;

//Begin execution
int main(int argc, char** argv) {

    //Declare and initialize variables
    float princip, rate, amt, inter;
    short comp;
    
    //Request user input
    cout << "How much was the initial investment? $";
    cin >> princip;
    cout << "What percent is the interest rate? ";
    cin >> rate;
    cout << "How many times has the interest been compounded since initial investment? ";
    cin >> comp;
    
    //Calculations
    rate = rate / 100;
    amt = princip * pow(1 + rate / comp, comp);
    inter = amt - princip;
    
    //Output data
    cout << endl;
    cout << setw(15) << setw(20) << "Interest Rate:" << setw(2) << " " << setw(10) << rate * 100 << "%" << endl;
    cout << setw(15) << setw(20) << "Times Compounded:" << setw(2) << " " << setw(10) << comp << endl;
    cout << setprecision(2) << fixed;
    cout << setw(15) << setw(20) << "Principal:" << setw(2) << "$" << setw(10) << princip << endl;
    cout << setw(15) << setw(20) << "Interest Earned:" << setw(2) << "$" << setw(10) << inter << endl;
    cout << setw(15) << setw(20) << "Amount in Savings:" << setw(2) << "$" << setw(10) << amt << endl;
    
    
    //Finish him!!
    return 0;
}

