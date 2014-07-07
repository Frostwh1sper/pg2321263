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
    char package;
    int hours;
    float rate1, rate2, rate3;
    bool loop=true;
    
    //User input
    cout << "How many hours of Internet did you consume this month? ";
    cin >> hours;
    do{
    cout << "Which subscription package do you subscribe to?" << endl;
    cout << "1) Package A: For $9.95 per month, 10 hours of access are provided. Additional hours" << endl;
    cout << "              are $2.00 per hour." << endl;
    cout << "2) Package B: For $14.95 per month, 20 hours of access are provided. Additional hours" << endl;
    cout << "              are $1.00 per hour." << endl;
    cout << "3) Package C: For $19.95 per month, unlimited access is provided." << endl;
    cout << "Enter the number for the corresponding package: ";
    cin >> package;
    cin.ignore();
    cout << setprecision(2) << fixed;
    switch(package){
        case '1':{
            cout << "Your bill for this month is $" << (hours-10)*2.0f+9.95f << "." << endl;
            loop=false;
            break;
        }
        case '2':{
            cout << "Your bill for this month is $" << (hours-20)*1.0f+14.95f << "." << endl;
            loop=false;
            break;
        }
        case '3':{
            cout << "Your bill for this month is $19.95." << endl;
            loop=false;
            break;
        }
        default:{
            cout << "You didn't enter a valid package number, please try again." << endl;
            break;
        }
    }
    }while(loop);
    
    //Output
    
    //Finish him!!
    return 0;
}

