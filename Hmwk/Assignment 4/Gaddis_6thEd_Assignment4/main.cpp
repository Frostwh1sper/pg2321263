/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 8, 2014, 1:04 PM
 * Purpose: To execute 10 programs from Gaddis 6th Edition, Chapter 5
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

//Assignment 4 Menu
    
    //Declare variables
    int choice;
    bool loop=true;
    do{
    //Menu Display
    cout << "_____________________________________________" << endl;
    cout << "* Glenning, Patrick - Assignment #4 - 46023 *" << endl;
    cout << "*  1) Sum of Numbers                        *" << endl;
    cout << "*  2) Calories Burned                       *" << endl;
    cout << "*  3) Distance Traveled                     *" << endl;
    cout << "*  4) Math Tutor                            *" << endl;
    cout << "*  5) Population                            *" << endl;
    cout << "*  6) The Greatest and Least of These       *" << endl;
    cout << "*  7) Savings Account Balance               *" << endl;
    cout << "*  8) Sales Bar Chart                       *" << endl;
    cout << "*  9) Budget Analysis                       *" << endl;
    cout << "* 10) Random Number Guessing Game           *" << endl;
    cout << "*   Enter any other key to exit program     *" << endl;
    cout << "*___________________________________________*" << endl;
    cout << "Please choose a program: ";
    cin >> choice;
    cin.ignore();
    cout << string(50,'\n');
    
    //Begin switch for choice
    switch(choice){
        case 1:{        //Problem 1, Sum of Numbers
            
            //Declare and initialize variables
            unsigned short num, sum=0, counter=1;
            
            //User input
            cout << "This program will sum all integers leading up to a number you choose." << endl;
            cout << "Please choose any positive integer: ";
            cin >> num;
            
            //Calculations
            while(counter<=num){
                sum+=counter;
                counter++;
            }
            
            //Output
            cout << "The sum of all numbers leading up to " << num << " is " << sum << "." << endl;
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        case 2:{        //Problem 4, Calories Burned
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        case 3:{        //Problem 6, Distance Traveled
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        case 4:{        //Problem 8, Math Tutor
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        case 5:{        //Problem 11, Population
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        case 6:{        //Problem 13, The Greatest and Least of These
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        case 7:{        //Problem 16, Savings Account Balance
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        case 8:{        //Problem 17, Sales Bar Chart
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        case 9:{        //Problem 19, Budget Analysis
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        case 10:{       //Problem 21, Random Number Guessing Game
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        default:{
            cout << "Exiting program..." << endl;
            loop=false;
            break;
        }
    }
    }while(loop);
    //Finish him!!
    return 0;
}

