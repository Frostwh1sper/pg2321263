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
void menu();            //Displays main menu
int slction();          //Returns menu selection
void problem1();        //Gaddis 6thEd Chap6 Prob
void problem2();        //Gaddis 6thEd Chap6 Prob
void problem3();        //Gaddis 6thEd Chap6 Prob
void problem4();        //Gaddis 6thEd Chap6 Prob
void problem5();        //Gaddis 6thEd Chap6 Prob
void problem6();        //Gaddis 6thEd Chap6 Prob
void problem7();        //Gaddis 6thEd Chap6 Prob
void problem8();        //Gaddis 6thEd Chap6 Prob
void problem9();        //Gaddis 6thEd Chap6 Prob
void problem10();       //Gaddis 6thEd Chap6 Prob

//Begin execution
int main(int argc, char** argv) {
    
    //Declare and initialize variables
    int choice;
    
    //Display Menu
    do{
        menu();

        //User selection
        choice=slction();

        //Problems
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
                break;
            }
        }
    }while(choice<11);
    
    //Finish him!!
    return 0;
}
/*
 * 
 * 
 */
void menu(){
    
    cout << "           ________________________________________________ " << endl <<
            "          *                                                *" << endl <<
            "          *                                                *" << endl <<
            "          *    Glenning, Patrick - Assignment 5 - 46023    *" << endl <<
            "          *                                                *" << endl <<
            "          *    1)  Markup                                  *" << endl <<
            "          *    2)  Safest Driving Area                     *" << endl <<
            "          *    3)  Falling Distance                        *" << endl <<
            "          *    4)  Kinetic Energy                          *" << endl <<
            "          *    5)  Present Value                           *" << endl <<
            "          *    6)  Star Search                             *" << endl <<
            "          *    7)  Overloaded Hospital                     *" << endl <<
            "          *    8)  Population                              *" << endl <<
            "          *    9)  Stock Profit                            *" << endl <<
            "          *    10) isPrime Function                        *" << endl <<
            "          *    11) Exit Program                            *" << endl <<
            "          *________________________________________________*" << endl <<
            "             Enter your selection number: ";
    
}

/*
 * 
 * 
 */
int slction(){
    
    //Declare variables
    int n;
    bool x=true;
    
    //User input
    do{
        cin >> n;
        if(n<1 || n>11){
            cout << "             Please enter a valid input: ";
        }
        if(n>0 && n<12){
            x=false;
            cout << string(50,'\n');
        }
    }while(x);
    return n;
}

/*
 * Gaddis 6thEd Chap6 Prob1 - Markup
 * Purpose: Displays an item's retail price
 */
void problem1(){
    
    //Declare and initialize variables
    
}

/*
 * Gaddis 6thEd Chap6 Prob4 - Safest Driving Area
 * Purpose: 
 */
void problem2(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob5 - Falling Distance
 * Purpose: 
 */
void problem3(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob6 - Kinetic Energy
 * Purpose: 
 */
void problem4(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob9 - Present Value
 * Purpose: 
 */
void problem5(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob11 - Star Search
 * Purpose: 
 */
void problem6(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob14 - Overloaded Hospital
 * Purpose: 
 */
void problem7(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob15 - Population
 * Purpose: 
 */
void problem8(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob19 - Stock Profit
 * Purpose: 
 */
void problem9(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob21 - isPrime Function
 * Purpose: 
 */
void problem10(){
    
}