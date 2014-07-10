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
    int counter=1;              //Keeps track of guess attempts
    int numCol=4;               //Number of colors to be guessed within the allotted turns (defaulted to 4)
    int numTurn=3;             //Number of turns to crack the code (defaulted to 10)
    int choice;
    int colCorr=0, posCorr=0;   //Number of correct colors, and correct positions
    bool loop=true;             //Mini loop operator
    bool game=true;             //Loop operator for the game
    
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
        cout << string(50,'\n');
        
        switch(choice){

            //Output Game Objectives
            case 1:{
                cout << "The idea of the game is for one player (the code-breaker) to guess the secret code chosen" << endl;
                cout << "by the computer (the code-maker). The code is a sequence colored pegs chosen from six" << endl;
                cout << "colors available. The code-breaker makes a series of pattern guesses - after each guess" << endl;
                cout << "the code-maker gives feedback in the form of 2 numbers, the number of pegs that are of" << endl;
                cout << "the right color and in the correct position, and the number of pegs that are of the correct" << endl;
                cout << "color but not in the correct position." << endl << endl;
                cout << "Enter any key to return to the menu: ";
                char temp;
                cin >> temp;
                cin.ignore();
                cout << string(50,'\n');
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
                }loop=true;

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
                }loop=true;
                break;
            }
            loop=true;

            //Game begins
            case 3:{
                //Randomly generate the 'code' to be cracked
                char color[numCol];         //Array of colors chosen for the code
                char userCol[numCol];       //Variable for user's color selections
                for(int i=1; i<=numCol; i++){
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

                cout << endl;

                //Output game information
                cout << "A combination of " << numCol << " colors has been chosen." << endl 
                     << "You have " << numTurn << " turns to crack the code and prove that you are a Mastermind!" << endl
                     << "The colors you can choose from are Red, Orange, Yellow, Green, Blue, Purple." << endl
                     << "(Enter your guesses with capital letters, in the form of XXXX, i.e. RORY)" << endl;
                
                //Output answer for comparison testing
                for(int i=1; i<=numCol; i++){
                    cout << color[i] << " ";
                }
                cout << endl << endl;

                //User guesses
                do{
                    cout << "Attempt " << counter << ":";
                    for(int i=1; i<=numCol; i++){
                        cin >> userCol[i];
                    }
                    
                //Compare values
                    for(int i=1; i<=numCol; i++){
                        if(userCol[i]==color[i]){
                            colCorr++;
                            posCorr++;
                        }
                    }
                    
                //Tests if the user's first choice matches any other colors on the board, as long as that color isn't already perfectly matched
                    if(userCol[1]!=color[1]){
                        if((userCol[1]==color[2] && userCol[2]!=color[2]) ||
                           (userCol[1]==color[3] && userCol[3]!=color[3]) ||
                           (userCol[1]==color[4] && userCol[4]!=color[4])){
                            colCorr++;
                        }
                        //Prevent correct color redundancies
                        if(userCol[1]==userCol[2] && (userCol[1]==color[3] || userCol[1]==color[4])){
                            colCorr--;
                        }
                        if(userCol[1]==userCol[3] && (userCol[1]==color[2] || userCol[1]==color[4])){
                            colCorr--;
                        }
                        if(userCol[1]==userCol[4] && (userCol[1]==color[2] || userCol[1]==color[3])){
                            colCorr--;
                        }
                    }
                //Tests if the user's second choice matches any other colors on the board, as long as that color isn't already perfectly matched
                    if(userCol[2]!=color[2]){
                        if((userCol[2]==color[1] && userCol[1]!=color[1]) ||
                           (userCol[2]==color[3] && userCol[3]!=color[3]) ||
                           (userCol[2]==color[4] && userCol[4]!=color[4])){
                            colCorr++;
                        }
                        //Prevent correct color redundancies
                        if(userCol[2]==userCol[3] && (userCol[2]==color[1] || userCol[2]==color[4])){
                            colCorr--;
                        }
                        if(userCol[2]==userCol[4] && (userCol[2]==color[1] || userCol[2]==color[3])){
                            colCorr--;
                        }
                    }
                //Tests if the user's third choice matches any other colors on the board, as long as that color isn't already perfectly matched
                    if(userCol[3]!=color[3]){
                        if((userCol[3]==color[1] && userCol[1]!=color[1]) ||
                           (userCol[3]==color[2] && userCol[2]!=color[2]) ||
                           (userCol[3]==color[4] && userCol[4]!=color[4])){
                            colCorr++;
                        }
                        //Prevent correct color redundancies
                        if(userCol[3]==userCol[4] && (userCol[3]==color[1] || userCol[3]==color[2])){
                            colCorr--;
                        }
                    }
                //Tests if the user's fourth choice matches any other colors on the board, as long as that color isn't already perfectly matched
                    if(userCol[4]!=color[4]){
                        if((userCol[4]==color[1] && userCol[1]!=color[1]) ||
                           (userCol[4]==color[2] && userCol[2]!=color[2]) ||
                           (userCol[4]==color[3] && userCol[3]!=color[3])){
                            colCorr++;
                        }
                    }
                    
                
                    
                //Output results of comparison
                    cout << colCorr << " of your colors are correct, with " << posCorr << " in the correct position." << endl;
                    
                //Output in the event of running out of turns
                    if(counter==numTurn){
                        cout << "You have run out of turns. The correct combination was: ";
                        for(int i=1; i<=numCol; i++){
                            cout << color[i] << " ";
                        }
                        cout << endl << endl;
                    }
                    
                //Output in the event of a correct guess
                    if(userCol[1]==color[1]&&userCol[2]==color[2]&&userCol[3]==color[3]&&userCol[4]==color[4]){
                        cout << "Congratulations on cracking the code in " << counter << " turns!" << endl << endl << endl;
                        counter=numTurn;
                    }
                    
                    colCorr=0;
                    posCorr=0;
                    counter++;
                }while(counter<=numTurn);
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

