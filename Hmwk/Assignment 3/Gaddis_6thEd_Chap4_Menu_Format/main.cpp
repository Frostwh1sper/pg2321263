/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 5, 2014, 11:44 AM
 * Purpose: Assignment #3, with menu
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string.h>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin execution
int main(int argc, char** argv) {

    //Menu
    bool loop=true;
    do{
        //Menu Options
        cout << "Homework Assignment #3 Menu:" << endl;
        cout << "Type 1 to solve problem 1, Minimum/Maximum." << endl;
        cout << "Type 2 to solve problem 2, Roman Numeral Converter." << endl;
        cout << "Type 3 to solve problem 5, Body Mass Index." << endl;
        cout << "Type 4 to solve problem 7, Time Calculator." << endl;
        cout << "Type 5 to solve problem 8, Sorted Names." << endl;
        cout << "Type 6 to solve problem 9, Math Tutor." << endl;
        cout << "Type 7 to solve problem 18, The Speed of Sound." << endl;
        cout << "Type 8 to solve problem 20, Freezing and Boiling Points." << endl;
        cout << "Type 9 to solve problem 22, Long Distance Calls." << endl;
        cout << "Type 10 to solve problem 23, Internet Service Provider." << endl;
        cout << "Type anything else to quit the program." << endl;
        
        //User choice
        int choice;
        cin >> choice;
        
        switch(choice){
            case 1:{    //Problem 1, Minimum/Maximum
                int a,b;
                char temp;
                cout << "You will be entering two numbers, and the program will order them." << endl;
                cout << "Enter the first number: ";
                cin >> a;
                cout << "Enter the second number: ";
                cin >> b;
                
                if (a<b){
                    cout << a << " is smaller than " << b << "." << endl << endl;
                }
                if (b<a){
                    cout << b << " is smaller than " << a << "." << endl << endl;
                }
                else {
                    cout << "You entered the same number twice." << endl << endl;
                }
                cout << "Press any key and enter to return to the menu: ";
                cin >> temp;
                cout << string(50, '\n');
                break;
            }
        
            case 2:{    //Problem 2, Roman Numeral Converter
                
                break;
            }
        
            case 3:{    //Problem 5, Body Mass Index
                
                break;
            }
        
            case 4:{    //Problem 7, Time Calculator
                
                break;
            }
        
            case 5:{    //Problem 8, Sorted Names
                
                break;
            }
        
            case 6:{    //Problem 9, Math Tutor
                
                break;
            }
        
            case 7:{    //Problem 18, The Speed of Sound
                
                break;
            }
        
            case 8:{    //Problem 20, Freezing and Boiling Points
                
                break;
            }
        
            case 9:{    //Problem 22, Long Distance Calls
                
                break;
            }
        
            case 10:{   //Problem 23, Internet Service Provider
                
                break;
            }
            default:{   //Program exit
            cout << "Exiting program." << endl;
            loop=false;
            break;
            }
        }
        
    }while(loop);   //End of menu do/while
    
    //Finish him!!
    return 0;
}

