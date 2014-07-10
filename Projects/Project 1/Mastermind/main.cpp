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
    char color[4];  //Array of four colors chosen for the code
    
    //Randomly generate the 'code' to be cracked
    for(int i=0; i<4; i++){
        int colNum=rand()%6+1; //Switch operator for assigning color numbers
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
    for(int i=0; i<4; i++){
        cout << color[i] << " ";
    }
    cout << endl;
    
    //User input
    

    //Finish him!!
    return 0;
}

