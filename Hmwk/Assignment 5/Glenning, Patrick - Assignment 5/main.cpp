/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 22, 2014, 12:50 PM
 * Purpose: Execute 10 problems from Gaddis 6thEd, Chapter 6
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void menu();
int slction();
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

//Begin execution
int main(int argc, char** argv) {
    
    //Declare and initialize variables
    int choice;
    bool loop=true;
    
    //Display Menu
    menu();
    
    //User selection
    choice=slction();
    
    //Problems
    do{
        switch(choice){
            case 1:{
                problem1();
                break;
            }
            case 2:{
                problem2();
                break;
            }
            case 3:{
                problem3();
                break;
            }
            case 4:{
                problem4();
                break;
            }
            case 5:{
                problem5();
                break;
            }
            case 6:{
                problem6();
                break;
            }
            case 7:{
                problem7();
                break;
            }
            case 8:{
                problem8();
                break;
            }
            case 9:{
                problem9();
                break;
            }
            case 10:{
                problem10();
                break;
            }
            default:{
                cout << "Exiting program..." << endl << endl;
                loop=false;
                break;
            }
        }
    }while(loop);
    
    //Finish him!!
    return 0;
}

