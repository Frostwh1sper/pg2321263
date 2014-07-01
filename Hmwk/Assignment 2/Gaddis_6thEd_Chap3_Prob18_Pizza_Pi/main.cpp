/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 1, 2014, 12:32 PM
 * Purpose: Calculate dimensions of a pizza pie
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User-defined Libraries

//Global Constants
const double PI = 3.1415926535; //Yes, I'm the one who knows pi out to 10 decimal places, so please don't hate on the double

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {

    //Declare and initialize variables
    int d;                      //Diameter of pizza
    float area = 14.125;        //Area per slice
    int slices;                 //Number of slices
    
    //User input
    cout << "What is the diameter of the pizza? (inches) ";
    cin >> d;
    
    //Calculations
    slices = PI * pow(d/2,2.0) / area;  //Total area of pizza divided by area per slice
    
    //Output the number of slices for this pizza
    cout << "A " << d << "\" pizza will have " << slices << " slices." << endl;
    
    //Finish him!!
    return 0;
}

