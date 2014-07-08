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
    cout << string(50,'\n');
    
    //Begin switch for choice
    switch(choice){
        case 1:{
            
            cout << string(50,'\n');
            break;
        }
        case 2:{
            
            cout << string(50,'\n');
            break;
        }
        case 3:{
            
            cout << string(50,'\n');
            break;
        }
        case 4:{
            
            cout << string(50,'\n');
            break;
        }
        case 5:{
            
            cout << string(50,'\n');
            break;
        }
        case 6:{
            
            cout << string(50,'\n');
            break;
        }
        case 7:{
            
            cout << string(50,'\n');
            break;
        }
        case 8:{
            
            cout << string(50,'\n');
            break;
        }
        case 9:{
            
            cout << string(50,'\n');
            break;
        }
        case 10:{
            
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

