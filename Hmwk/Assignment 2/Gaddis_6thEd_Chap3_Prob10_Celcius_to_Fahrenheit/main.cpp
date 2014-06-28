/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on June 27, 2014, 5:23 PM
 * Purpose: Convert degrees Celcius to Fahrenheit
 */

//System Libraries
#include <iostream>
#include <iomanip>

//User-defined Libraries

//Global Constants

//Function Prototypes

using namespace std;

//Begin execution
int main(int argc, char** argv) {

    //Declare and establish variables
    float celc, fahr, ratio = 1.8;
    
    //Request input
    cout << "What is the temperature, in Celcius? ";
    cin >> celc;
    
    //Calculations
    fahr = ratio * celc + 32;
    
    //Output data
    cout << setprecision(1) << fixed;
    cout << "That is " << fahr << " degrees Fahrenheit." << endl;
    
    //Finish him!!
    return 0;
}

