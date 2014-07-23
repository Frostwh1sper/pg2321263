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
void problem2();        //Gaddis 6thEd Chap7 Prob4 - Monkey Business
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
            "          *    1) Largest/Smallest Array Values            *" << endl <<
            "          *    2) Monkey Business                          *" << endl <<
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
        if(n<1 || n>11) cout << "             Please enter a valid input: ";
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

void cntinue(){
    char x;
    cout << endl;
    cin.get(x);
}

/*
 * Gaddis 6thEd Chap7 Prob1 - Largest/Smallest Array Values
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
 * Gaddis 6thEd Chap7 Prob4 - Monkey Business
 * Purpose: Record food intake of monkeys
 */
void problem2(){
    
    //Declare and initialize variables
    const int ROW=3, COL=7;
    int food[ROW][COL], sumTot, ave, lowX, lowY, highX, highY;
    
    //User inputs
    for(int i=0; i<3; i++){
        cout << "Enter how much food (in whole pounds) monkey " << i+1 << " consumed... " << endl;
        for(int n=0; n<7; n++){
            cout << "Day " << n+1 << ": ";
            do{
                cin >> food[i][n];
                cin.ignore();
                if(food[i][n]<0) cout << "Invalid weight entered, please re-enter: ";
            }while(food[i][n]<0);
        }
    }
    
    //Calculations
    sumTot=food[0][0];
    for(int i=0; i<3; i++){
        for(int n=0; n<7; n++){
            sumTot+=food[i][n];
        }
    }
    ave=sumTot/21;
    
    //Determine lowest and highest consumption
    lowX=0;
    lowY=0;
    highX=0;
    highY=0;
    for(int i=0; i<3; i++){
        for(int n=0; n<7; n++){
            if(food[lowY][lowX]>food[i][n]){
                lowX=n;
                lowY=i;
            }
            if(food[highY][highX]<food[i][n]){
                highX=n;
                highY=i;
            }
        }
    }
    
    //Display data
    cout << "Average daily consumption: " << ave << " pounds" << endl <<
            " Total weekly consumption: " << sumTot << " pounds." << endl <<
            " Most was consumed by monkey " << highY+1 << " on day " << highX+1 << ": " << food[highY][highX] << " pounds." << endl <<
            "Least was consumed by monkey " << lowY+1 << " on day " << lowX+1 << ": " << food[lowY][lowX] << " pounds." << endl;
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
    cout << "Enter a number: ";
    cin >> x;
    return x;
}