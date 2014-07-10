/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 9, 2014, 4:56 PM
 * Purpose: Execute the game Mastermind
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin execution
int main(int argc, char** argv) {
    
    //Seed RNG
    unsigned seed=time(0);
    srand(seed);
    
    //Declare and initialize variables
    char userCol[4];    //Variable for user's color selections
    int counter=0;      //Keeps track of guess attempts
    int numCol;         //Number of colors to be guessed within the allotted turns
    int numTurn;        //Number of turns to crack the code
    bool loop=true;     //Loop operator
    
    //User chooses difficulty settings
    while(loop){
        cout << "How long of a code would you like to crack? (4-6) ";
        cin >> numCol;
        switch(numCol){
            case 4 ... 6:{
                cout << "You have selected " << numCol << " colors." << endl;
                loop=false;
                break;
            }
            default:{
                cout << "Invalid entry, please re-enter your selection." << endl;
                break;
            }
        }
    }
    
    loop=true;
    
    while(loop){
        cout << "How many turns would you like to have to attempt to crack the color combination? (10-12) ";
        cin >> numTurn;
        switch(numTurn){
            case 10 ... 12:{
                cout << "You have chosen " << numTurn << " turns." << endl;
                loop=false;
                break;
            }
            default:{
                cout << "Invalid entry, please re-enter your selection." << endl;
                break;
            }
        }
    }
    
    loop=true;
    
    //Randomly generate the 'code' to be cracked
    char color[numCol];         //Array of colors chosen for the code
    for(int i=0; i<numCol; i++){
        int colNum=rand()%6+1;  //Switch operator for assigning color numbers
        switch(colNum){
            case 1:{
                color[i]='R';
                break;
            }
            case 2:{
                color[i]='O';
                break;
            }
            case 3:{
                color[i]='Y';
                break;
            }
            case 4:{
                color[i]='G';
                break;
            }
            case 5:{
                color[i]='B';
                break;
            }
            case 6:{
                color[i]='P';
                break;
            }
        }
    }
    
    //Code output test (comment block when running finalized game debug)
    for(int i=0; i<numCol; i++){
        cout << color[i] << " ";
    }
    cout << endl;
    
    //User guesses
    do{
        
    }while(counter<numTurn);

    //Finish him!!
    return 0;
}

