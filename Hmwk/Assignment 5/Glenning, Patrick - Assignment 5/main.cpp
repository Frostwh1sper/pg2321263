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
    int inN;
    
    //Display Menu
    do{
        menu();

        //User selection
        inN=slction();
        cout << "You chose " << inN << endl;

        //Problems
        switch(inN){
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
    }while(inN<12);
    
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
            "          *    1)  Gaddis 6thEd Chap6 Prob                 *" << endl <<
            "          *    2)  Gaddis 6thEd Chap6 Prob                 *" << endl <<
            "          *    3)  Gaddis 6thEd Chap6 Prob                 *" << endl <<
            "          *    4)  Gaddis 6thEd Chap6 Prob                 *" << endl <<
            "          *    5)  Gaddis 6thEd Chap6 Prob                 *" << endl <<
            "          *    6)  Gaddis 6thEd Chap6 Prob                 *" << endl <<
            "          *    7)  Gaddis 6thEd Chap6 Prob                 *" << endl <<
            "          *    8)  Gaddis 6thEd Chap6 Prob                 *" << endl <<
            "          *    9)  Gaddis 6thEd Chap6 Prob                 *" << endl <<
            "          *    10) Gaddis 6thEd Chap6 Prob                 *" << endl <<
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
    int inN;
    bool x=true;
    
    //User input
    do{
        cin >> inN;
        if(inN<1 || inN>11){
            cout << "             Please enter a valid input: ";
        }
        if(inN>0 && inN<12){
            x=false;
            cout << string(50,'\n');
        }
    }while(x);
    return inN;
}

/*
 * Gaddis 6thEd Chap6 Prob
 * 
 */
void problem1(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob
 * 
 */
void problem2(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob
 * 
 */
void problem3(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob
 * 
 */
void problem4(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob
 * 
 */
void problem5(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob
 * 
 */
void problem6(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob
 * 
 */
void problem7(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob
 * 
 */
void problem8(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob
 * 
 */
void problem9(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob
 * 
 */
void problem10(){
    
}