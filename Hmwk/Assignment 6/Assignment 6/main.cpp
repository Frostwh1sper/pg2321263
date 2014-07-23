/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 22, 2014, 12:50 PM
 * Purpose: Execute 10 problems from Gaddis 6thEd, Chapter 7
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
void callPrb(int);      //Calls programs using switch
void cntinue();         //Waits for input before continuing
void problem1();        //Gaddis 6thEd Chap7 Prob1 - Largest/Smallest Array Values
void problem2();        //Gaddis 6thEd Chap7 Prob
void problem3();        //Gaddis 6thEd Chap7 Prob
void problem4();        //Gaddis 6thEd Chap7 Prob
void problem5();        //Gaddis 6thEd Chap7 Prob
void problem6();        //Gaddis 6thEd Chap7 Prob
void problem7();        //Gaddis 6thEd Chap7 Prob
void problem8();        //Gaddis 6thEd Chap7 Prob
void problem9();        //Gaddis 6thEd Chap7 Prob
void problem10();       //Gaddis 6thEd Chap7 Prob
int getNum();

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
        callPrb(choice);
        
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
            "          *    Glenning, Patrick - Assignment 6 - 46023    *" << endl <<
            "          *                                                *" << endl <<
            "          *    1)                                          *" << endl <<
            "          *    2)                                          *" << endl <<
            "          *    3)                                          *" << endl <<
            "          *    4)                                          *" << endl <<
            "          *    5)                                          *" << endl <<
            "          *    6)                                          *" << endl <<
            "          *    7)                                          *" << endl <<
            "          *    8)                                          *" << endl <<
            "          *    9)                                          *" << endl <<
            "          *    10)                                         *" << endl <<
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
 * Input
 *      choice
 * Output
 *      none
 */
void callPrb(int x){
    switch(x){
        case 1:{
            problem1();
            cout << "Press any key to return to the main menu." << endl;
            cntinue();
            break;
        }
        case 2:{
            problem2();
            cout << "Press any key to return to the main menu." << endl;
            cntinue();
            break;
        }
        case 3:{
            problem3();
            cout << "Press any key to return to the main menu." << endl;
            cntinue();
            break;
        }
        case 4:{
            problem4();
            cout << "Press any key to return to the main menu." << endl;
            cntinue();
            break;
        }
        case 5:{
            problem5();
            cout << "Press any key to return to the main menu." << endl;
            cntinue();
            break;
        }
        case 6:{
            problem6();
            cout << "Press any key to return to the main menu." << endl;
            cntinue();
            break;
        }
        case 7:{
            problem7();
            cout << "Press any key to return to the main menu." << endl;
            cntinue();
            break;
        }
        case 8:{
            problem8();
            cout << "Press any key to return to the main menu." << endl;
            cntinue();
            break;
        }
        case 9:{
            problem9();
            cout << "Press any key to return to the main menu." << endl;
            cntinue();
            break;
        }
        case 10:{
            problem10();
            cout << "Press any key to return to the main menu." << endl;
            cntinue();
            break;
        }
        default:{
            cout << "Exiting program..." << endl << endl;
            break;
        }
    }
}

/*
 * Gaddis 6thEd Chap7 Prob
 * Purpose: Displays the largest and smallest values in an array
 */
void problem1(){
    
    //Declare and initialize variables
    int num[10];
    int high, low;
    
    //User inputs
    for(int i=0; i<10; i++){
        num[i]=getNum();
    }
    
    //Find largest and smallest
    high=low=num[0];
    for(int i=1; i<10; i++){
        if(high<num[i]) high=num[i];
        if(low>num[i]) low=num[i];
    }
    
    //Display largest and smallest
    cout << "Highest: " << high << endl <<
            " Lowest: " << low << endl;
}

/*
 * Gaddis 6thEd Chap7 Prob
 * Purpose: 
 */
void problem2(){
    
}

/*
 * Gaddis 6thEd Chap7 Prob
 * Purpose: 
 */
void problem3(){
    
}

/*
 * Gaddis 6thEd Chap7 Prob
 * Purpose: 
 */
void problem4(){
    
}

/*
 * Gaddis 6thEd Chap7 Prob
 * Purpose: 
 */
void problem5(){
    
}

/*
 * Gaddis 6thEd Chap7 Prob
 * Purpose: 
 */
void problem6(){
    
}

/*
 * Gaddis 6thEd Chap7 Prob
 * Purpose: 
 */
void problem7(){
    
}

/*
 * Gaddis 6thEd Chap7 Prob
 * Purpose: 
 */
void problem8(){
    
}

/*
 * Gaddis 6thEd Chap7 Prob
 * Purpose: 
 */
void problem9(){
    
}

/*
 * Gaddis 6thEd Chap7 Prob
 * Purpose: 
 */
void problem10(){
    
}

/*
 * 
 * 
 */
int getNum(){
    int x;
    cout << "Enter a number: "
    cin >> x;
    return x;
}