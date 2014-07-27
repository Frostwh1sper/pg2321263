/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 26, 2014, 10:15 AM
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
const int SIZE=12;
const int COL=4;

//Function Prototypes
void menu();
int getN();
bool menSel();
void rules();
void setting(int &);
void mstrmind(int);
void cntinue();
void attempt(int &,int,char []);
void board(char [][COL],int);

//Begin execution
int main(int argc, char** argv) {
    
    //Declare and initialize variables
    bool game;
    
    do{
        //Display menu
        menu();

        //Make menu choice
        game=menSel();
        
    }while(game);
    
    //Finish him!!
    return 0;
}

/*
 * Function which displays the main menu
 * 
 */
void menu(){
    cout << "        _______________________________________________________        " << endl <<
            "       *                                                       *       " << endl << 
            "       *                                                       *       " << endl <<
            "       *                 Welcome to Mastermind!                *       " << endl << 
            "       *                                                       *       " << endl << 
            "       *       Menu:                                           *       " << endl << 
            "       *       1) Game Objective                               *       " << endl << 
            "       *       2) Difficulty Settings                          *       " << endl << 
            "       *       3) Start the game                               *       " << endl << 
            "       *       4) Exit Mastermind                              *       " << endl << 
            "       *                                                       *       " << endl << 
            "       *_______________________________________________________*       " << endl << 
            "        Make your selection: ";
}

/*
 * Function which retrieves an entered integer
 * Input:
 *      none
 * Output:
 *      n
 */
int getN(){
    int n;
    cin >> n;
    cin.ignore();
    cout << string(50,'\n');
    return n;
}

/*
 * Function which calls other functions chosen from a menu
 * Input:
 *      none
 * Output:
 *      game
 * 
 */
bool menSel(){
    int numTurn=10;             //Number of turns to crack the code (defaulted to 10)
    char code[SIZE];            //Code generated by computer
    char guess[SIZE];
    bool game=true;             //Loops game until 
    int sel=getN();             //Retrieves menu selection
    switch(sel){
        //Output Game Objectives
        case 1:{
            rules();
            break;
        }

        //User chooses difficulty settings
        case 2:{
            setting(numTurn);
            break;
        }

        //Game begins
        case 3:{
            string(50,'\n');
            mstrmind(numTurn);
            break;
        }

        //Exit Program
        case 4:{
            cout << endl << endl;
            cout << "Exiting Mastermind..." << endl;
            game=false;
            break;
        }
        
        //Invalid menu selection
        default:{
            cout << "Invalid input. Please re-enter your selection: " << endl;
            break;
        }
    }
    return game;
}

/*
 * 
 * 
 */
void rules(){
    cout << "The idea of the game is for one player (the code-breaker) to guess the secret code chosen" << endl << 
            "by the computer (the code-maker). The code is a sequence of colored pegs chosen from six" << endl <<
            "colors available. The code-breaker makes a series of pattern guesses - after each guess" << endl <<
            "the code-maker gives feedback in the form of 2 numbers, the number of pegs that are of" << endl <<
            "the right color and in the correct position (+), and the number of pegs that are of the" << endl <<
            "correct color but not in the correct position (~)." << endl << endl;
    cntinue();
}

/*
 * 
 * 
 */
void setting(int&turns){
    
    //Choose number or turns to crack the code
    do{
        cout << "How many turns do you think you can crack the code in? (8-12, default is 10) ";
        turns=getN();
        if(turns<8 || turns >12) cout << "Invalid input." << endl;
    }while(turns<8 || turns >12);
}

/*
 * 
 * 
 */
void mstrmind(int turns){
    
    //Declare and initialize variables
    int counter=0;
    char guess[SIZE][COL];
    char code[COL];                      //Array of colors chosen for the code, initialized to K, for comparison check
    
    //Randomly generate the 'code' to be cracked
    srand(time(0));
    for(int i=0; i<COL; i++){
        int colNum=rand()%6+1;      //Switch operator for assigning color numbers
        switch(colNum){
            case 1:{
                code[i]='R';
                break;
            }
            case 2:{
                code[i]='O';
                break;
            }
            case 3:{
                code[i]='Y';
                break;
            }
            case 4:{
                code[i]='G';
                break;
            }
            case 5:{
                code[i]='B';
                break;
            }
            case 6:{
                code[i]='P';
                break;
            }
        }
    }
    
    //Output game information
    cout << "A color code of four (4) colors has been generated." << endl <<
            "You have " << turns << " turns to crack the code!" << endl <<
            "The colors you can choose from are:" << endl <<
            "Red (R), Orange (O), Yellow (Y), Green (G), Blue (B), Purple (P)" << endl <<
            "Entered guesses must be in the format of XXXX (i.e. RORY)" << endl <<
            "+ = Correct position" << endl <<
            "~ = Correct color in wrong position" << endl << endl;
    
    /*
    //Display code for debugging purposes
    for(int i=0; i<COL; i++){
        cout << code[i] << " ";
    }
    cout << endl;
    */
    
    do{
        //User input
        attempt(counter,turns,code);
        
        counter++;
        
        //Display board and past guesses
        
        
    }while(counter<turns);
}

/*
 * 
 * 
 */
void attempt(int &counter, int turns, char code[]){
    string colStrg;
    char guess[SIZE][COL];
    char check[COL];
    char temp[COL];
    bool loop;
    do{
        loop=false;
        cout << " |   |   |   |   |     Attempt " << counter+1 << ":";
            cin >> colStrg;
            cin.ignore();
        for(int i=0; i<COL; i++){
            guess[counter][i]=colStrg[i];
        }
        if(colStrg.size()!=COL){ //If incorrect number of colors entered
            cout << "Invalid entry." << endl;
            loop=true;
        }
        for(int i=0; i<COL; i++){
            if(guess[counter][i]!='R'
             &&guess[counter][i]!='O'
             &&guess[counter][i]!='Y'
             &&guess[counter][i]!='G'
             &&guess[counter][i]!='B'
             &&guess[counter][i]!='P'){    //If any guessed colors don't match the valid color inputs
                cout << "Invalid entry." << endl;
                loop=true;
            }
        }
    }while(loop);   //End of user guess do-while loop
    
    //Transcribe guess and code into a check array
    for(int i=0; i<COL; i++){
        check[i]=guess[counter][i];
    }
    for(int i=0; i<COL; i++){
        temp[i]=code[i];
    }
    
    //Declare and initialize variables
    int posCorr=0;
    int colCorr=0;
    
    //Find Correct color in correct place
    for(int i=0; i<COL; i++){
        if(check[i]==temp[i]){
            posCorr++;
            temp[i]='Z';
            check[i]='X';         //Removes guessed color from future consideration
        }
    }
    //Find correct color in wrong place
    for(int i=0; i<COL; i++){
        for(int n=0; n<COL; n++){
            if(temp[i]==check[n]){
                colCorr++;
                check[n]='X';   //Removes guessed color from future consideration
                n=COL;
            }
        }
    }
    
    //Output results of comparison
    board(guess,counter);
    cout << string(posCorr,'+') << string(colCorr,'~') << endl;
    
    //Output in the event of running out of turns
    if(counter==turns){
        cout << "You have run out of turns. The correct combination was: ";
        for(int i=0; i<COL; i++){
            cout << code[i] << " ";
        }
        cout << endl;
        cntinue();
    }
    
    //Output in the event of a completely correct guess
    if(posCorr==COL){
        cout << "Congratulations on cracking the code in " << counter+1 << " turns!" << endl << endl << endl;
        counter=turns;
        cntinue();
    }
}

/*
 * 
 * 
 */
void board(char guess[][COL], int counter){
    for(int n; n<COL; n++){
        cout << " | " << guess[counter][n];
    }
    cout << " |   ";
}

/*
 * 
 * 
 */
void cntinue(){
    char x;
    cout << "Press any key to continue." << endl;
    cin.get(x);
    cout << string(50,'\n');
}

