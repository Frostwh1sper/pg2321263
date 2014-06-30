/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on June 30, 2014, 11:30 AM
 * Purpose: Present a sum of two random numbers for a student to attempt to solve before the answer is revealed
 */

//System Libraries
#include <iostream>     //input/output functions
#include <cstdlib>      //Used for the rand() function
#include <ctime>        //Used to retrieve time
#include <iomanip>      //Formatting library

//User-defined Libraries

//Global Constants

//Function Prototypes

using namespace std;

//Begin execution
int main(int argc, char** argv) {

    //Declare and initialize variables
    short a, b;
    char c;
    
    //Get the system time
    unsigned seed = time(0);
    
    //Seed the random function
    srand (seed);
    
    //Assign random values for a and b
    a = 1 + rand() % 500;
    b = 1 + rand() % 500;
    
    //Present problem equation
    cout << "Find the sum:" << endl;
    cout << setw(4) << a << endl;
    cout << "+" << setw(3) << b << endl <<endl;
    
    //Display the answer
    cout << "Hit enter when you are ready to see the answer";
    cin.get(c);
    cout << "The answer is " << (a + b) << "." << endl;
    
    //Finish him!!
    return 0;
}

