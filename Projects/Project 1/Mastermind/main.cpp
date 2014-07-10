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
    int choice;
    bool loop=true;     //Loop operator
    bool game=true;
    
    do{
        //Game menu
        cout << "        _______________________________________________________ " << endl;
        cout << "       *                                                       *" << endl;
        cout << "       *                                                       *" << endl;
        cout << "       *                 Welcome to Mastermind!                *" << endl;
        cout << "       *                                                       *" << endl;
        cout << "       *       Menu:                                           *" << endl;
        cout << "       *       1) Game Objective                               *" << endl;
        cout << "       *       2) Difficulty Settings                          *" << endl;
        cout << "       *       3) Start the game                               *" << endl;
        cout << "       *       4) Exit Mastermind                              *" << endl;
        cout << "       *                                                       *" << endl;
        cout << "       *________________________________________________________*" << endl;
        cout << "        Make your selection: ";
        cin >> choice;
        cin.ignore();

        switch(choice){

            //Output Game Objectives
            case 1:{
                cout << "The idea of the game is for one player (the code-breaker) to guess the secret code chosen" << endl;
                cout << "by the computer (the code-maker). The code is a sequence of 4 colored pegs chosen from" << endl;
                cout << "six colors available. The code-breaker makes a series of pattern guesses - after each guess" << endl;
                cout << "the code-maker gives feedback in the form of 2 numbers, the number of pegs that are of" << endl;
                cout << "the right color and in the correct position, and the number of pegs that are of the correct" << endl;
                cout << "color but not in the correct position." << endl;
                
                
                break;
            }

            //User chooses difficulty settings
            case 2:{
                
                //Choose length of code
                while(loop){
                    cout << "How long of a code would you like to crack? (4-6) ";
                    cin >> numCol;
                    switch(numCol){
                        case 4 ... 6:{
                            cout << "You have selected a code " << numCol << " colors long." << endl;
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

                //Choose number or turns to crack the code
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
                
                break;
            }
            loop=true;

            //Game begins
            case 3:{
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

                //Output game information
                cout << "A combination of " << numCol << " colors has been chosen." << endl 
                     << "You have " << numTurn << " turns to crack the code and prove that you are a Mastermind!" << endl
                     << "The colors you can choose from are R, O, Y, G, B, P." << endl;

                //User guesses
                do{

                    counter++;
                }while(counter<numTurn);
                
                
                break;
            }

            //Exit Program
            case 4:{
                cout << endl << endl;
                cout << "Exiting Mastermind..." << endl;
                game=false;
                break;
            }

            default:{
                cout << "Invalid input. Please re-enter your selection: ";
                break;
            }

        }
    }while(game);
    //Finish him!!
    return 0;
}

