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
#include <string>
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
    int numTurn=10;             //Number of turns to crack the code (defaulted to 10)
    int choice;                 //Main menu selection
    int colCorr=0, posCorr=0;   //Number of correct colors, and correct positions
    bool loop=true;             //Mini loop operator
    bool game=true;             //Loop operator for the game
    const int SIZE=12;           //Used for initialization of color arrays
    string colStrg;
    
    cout << string(50,'\n');
    do{
        //Game menu
        cout << "        _______________________________________________________        " << endl;
        cout << "       *                                                       *       " << endl;
        cout << "       *                                                       *       " << endl;
        cout << "       *                 Welcome to Mastermind!                *       " << endl;
        cout << "       *                                                       *       " << endl;
        cout << "       *       Menu:                                           *       " << endl;
        cout << "       *       1) Game Objective                               *       " << endl;
        cout << "       *       2) Difficulty Settings                          *       " << endl;
        cout << "       *       3) Start the game                               *       " << endl;
        cout << "       *       4) Exit Mastermind                              *       " << endl;
        cout << "       *                                                       *       " << endl;
        cout << "       *_______________________________________________________*       " << endl;
        cout << "        Make your selection: ";
        cin >> choice;
        cin.ignore();
        cout << string(50,'\n');
        
        switch(choice){

            //Output Game Objectives
            case 1:{
                cout << "The idea of the game is for one player (the code-breaker) to guess the secret code chosen" << endl;
                cout << "by the computer (the code-maker). The code is a sequence of colored pegs chosen from six" << endl;
                cout << "colors available. The code-breaker makes a series of pattern guesses - after each guess" << endl;
                cout << "the code-maker gives feedback in the form of 2 numbers, the number of pegs that are of" << endl;
                cout << "the right color and in the correct position (+), and the number of pegs that are of the" << endl;
                cout << "correct color but not in the correct position (~)." << endl << endl;
                cout << "Enter any key to return to the menu: ";
                char temp;
                cin >> temp;
                cin.ignore();
                cout << string(50,'\n');
                break;
            }

            //User chooses difficulty settings
            case 2:{
                do{
                    //Settings menu
                    cout << "        _______________________________________________________        " << endl;
                    cout << "       *                                                       *       " << endl;
                    cout << "       *                                                       *       " << endl;
                    cout << "       *                 Welcome to Mastermind!                *       " << endl;
                    cout << "       *                                                       *       " << endl;
                    cout << "       *       Settings Menu:                                  *       " << endl;
                    cout << "       *       1) Combination length                           *       " << endl;
                    cout << "       *       2) Number of turns                              *       " << endl;
                    cout << "       *       3) Return to main menu                          *       " << endl;
                    cout << "       *                                                       *       " << endl;
                    cout << "       *                                                       *       " << endl;
                    cout << "       *_______________________________________________________*       " << endl;
                    cout << "        Make your selection: ";
                    int sett;
                    cin>> sett;
                    switch(sett){
                        case 1:{
                            //Choose length of code
                            while(loop){
                                cout << "How long would you like the color combination to be? (4-6, default is 4) ";
                                cin >> numCol;
                                switch(numCol){
                                    case 4 ... 6:{
                                        loop=false;
                                        break;
                                    }
                                    default:{
                                        cout << "Invalid entry, please re-enter your selection." << endl;
                                        break;
                                    }
                                }
                            }loop=true;
                            cout << string(50,'\n');
                            break;
                        }

                        case 2:{
                            //Choose number or turns to crack the code
                            while(loop){
                                cout << "How many turns do you think you can crack the code in? (8-12, default is 10) ";
                                cin >> numTurn;
                                switch(numTurn){
                                    case 8 ... 12:{
                                        loop=false;
                                        break;
                                    }
                                    default:{
                                        cout << "Invalid entry, please re-enter your selection." << endl;
                                        break;
                                    }
                                }
                            }loop=true;
                            cout << string(50,'\n');
                            break;
                        }

                        default:{
                            cout << string(50,'\n');
                            loop=false;
                            break;
                        }
                    }
                }while(loop);
                loop=true;
                break;
            }

            //Game begins
            case 3:{
                //Randomly generate the 'code' to be cracked
                char color[SIZE]="K";           //Array of colors chosen for the code, initialized to K, for comparison check
                char userCol[SIZE]="K";         //Variable for user's color selections, initialized to K, for comparison check
                for(int i=0; i<numCol; i++){
                    int colNum=rand()%6+1;      //Switch operator for assigning color numbers
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
                cout << numCol << " colors have been chosen, and placed into a random order." << endl <<
                        "You have " << numTurn << " turns to crack the code and prove that you are a Mastermind!" << endl <<
                        "The colors available are Red (R), Orange (O), Yellow (Y), Green (G), Blue (B), Purple (P)." << endl <<
                        "(Enter your guesses with capital letters, in the form of XXXX, i.e. RORY)" << endl <<
                        "You can enter any letters you choose, however you may only enter the number" << endl <<
                        "of colors in the code." << endl << endl <<
                        "+ = correct color, correct position," << endl <<
                        "~ = correct color, incorrect position." << endl << endl;
                
                //Display combination for testing (Remove block comment to display when running program)
                
                cout << "The combinations is: ";
                for(int i=0; i<numCol; i++){
                    cout << color[i];
                }
                cout << endl << endl;
                

                //User guesses
                do{
                    do{
                        loop=false;
                        cout << "Attempt " << counter << ":";
                            cin >> colStrg;
                        for(int i=0; i<numCol; i++){
                            userCol[i]=colStrg[i];
                        }
                        if(colStrg.size()!=numCol){ //If incorrect number of colors entered
                            cout << "Invalid entry." << endl;
                            loop=true;
                        }
                        for(int i=0; i<numCol; i++){
                            if(userCol[i]!='R'
                             &&userCol[i]!='O'
                             &&userCol[i]!='Y'
                             &&userCol[i]!='G'
                             &&userCol[i]!='B'
                             &&userCol[i]!='P'){    //If any guessed colors don't match the valid color inputs
                                cout << "Invalid entry." << endl;
                                loop=true;
                            }
                        }
                            
                    }while(loop);   //End of user guess do-while loop
                    loop=true;
                    
                //Compare values
                    for(int i=0; i<numCol; i++){
                        if(userCol[i]==color[i]){
                            posCorr++;
                            for(int n=0; n<numCol; n++){
                                if(userCol[i]==color[n]&&n!=i){
                                    colCorr--;  //Makes sure the correctly guessed color & position isn't also a correct color in the wrong position elsewhere
                                }
                            }
                        }
                        else if(color[i]==userCol[0]){
                            colCorr++;
                            for(int n=i+1; n<numCol; n++){
                                if(color[i]==color[n]){
                                    colCorr--;
                                }
                            }
                        }
                        if(color[i]==userCol[1]){
                            colCorr++;
                            for(int n=i+1; n<numCol; n++){
                                if(color[i]==color[n]){
                                    colCorr--;
                                }
                            }
                        }
                        if(color[i]==userCol[2]){
                            colCorr++;
                            for(int n=i+1; n<numCol; n++){
                                if(color[i]==color[n]){
                                    colCorr--;
                                }
                            }
                        }
                        if(color[i]==userCol[3]){
                            colCorr++;
                            for(int n=i+1; n<numCol; n++){
                                if(color[i]==color[n]){
                                    colCorr--;
                                }
                            }
                        }
                        if(color[i]==userCol[4]){
                            colCorr++;
                            for(int n=i+1; n<numCol; n++){
                                if(color[i]==color[n]){
                                    colCorr--;
                                }
                            }
                        }
                        if(color[i]==userCol[5]){
                            colCorr++;
                        }
                        
                    }
                    
                    
                    
                //Output results of comparison
                    cout << string(posCorr,'+') << string(colCorr,'~') << endl;
                    
                //Output in the event of running out of turns
                    if(counter==numTurn){
                        cout << "You have run out of turns. The correct combination was: ";
                        for(int i=0; i<numCol; i++){
                            cout << color[i] << " ";
                        }
                        cout << endl;
                    }
                    
                //Output in the event of a completely correct guess
                    if(userCol[1]==color[1]
                     &&userCol[2]==color[2]
                     &&userCol[3]==color[3]
                     &&userCol[4]==color[4]
                     &&userCol[5]==color[5]
                     &&userCol[6]==color[6]){
                        cout << "Congratulations on cracking the code in " << counter << " turns!" << endl << endl << endl;
                        counter=numTurn;
                    }
                    
                    colCorr=0;
                    posCorr=0;
                    counter++;
                }while(counter<=numTurn);   //End of do-while loop for guessing
                counter=1;                  //Resets guess counter for next game
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
                cout << "Invalid input. Please re-enter your selection: " << endl;
                break;
            }

        }
    }while(game);
    
    //Finish him!!
    return 0;
}

