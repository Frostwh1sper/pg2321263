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
#include <fstream>
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
bool menSel(bool);
void rules();
void setting(int &);
void mstrmind(int);
void cntinue();
void attempt(int &,int,char []);
void board(char [][COL],int);
void compare(char [],char [],int &,int &);

//Begin execution
int main(int argc, char** argv) {
    
    //Declare and initialize variables
    bool game=true;
    
    do{
        //Display menu
        menu();

        //Make menu choice
        game=menSel(game);
        
    }while(game);   //End of game loop
    
    //Finish him!!
    return 0;
}

/*
 * Function which displays the main menu
 * Input:
 *      none
 * Output:
 *      none
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
 */
bool menSel(bool game){
    
    //Declare variables
    int turns=10;             //Number of turns to crack the code (defaulted to 10)
    char code[SIZE];            //Code generated by computer
    char guess[SIZE];
    int sel=getN();             //Retrieves menu selection
    
    switch(sel){
        //Output Game Objectives
        case 1:{
            rules();
            break;
        }

        //User chooses difficulty settings
        case 2:{
            setting(turns);
            break;
        }

        //Game begins
        case 3:{
            mstrmind(turns);
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
 * Function to display the rules of the game
 * Input:
 *      none
 * Output:
 *      none
 */
void rules(){
    
    //Declare variables
    string rule[100];
    ifstream input;
    input.open("rules.dat");
    int i=0;
    int count=0;
    while(!input.eof()){
        input >> rule[i];
        i++;
    }
    while(count<i){
        cout << rule[count] << " ";
        count ++;
        if(count%13==0) cout << endl;
    }
    cntinue();
}

/*
 * Function to change the number of turns allowed for cracking the code
 * Input:
 *      turns
 * Output:
 *      none
 */
void setting(int &turns){
    
    //Choose number or turns to crack the code
    do{
        cout << "How many turns do you think you can crack the code in? (8-12, default is 10) ";
        turns=getN();
        if(turns<8 || turns >12) cout << "Invalid input." << endl;
    }while(turns<8 || turns >12);
}

/*
 * Function which executes the mastermind game
 * Input:
 *      turns
 * Output:
 *      none
 */
void mstrmind(int turns){
    
    //Declare and initialize variables
    int counter=1;
    char guess[SIZE][COL];
    char code[COL];                 //Array of colors chosen for the code, initialized to K, for comparison check
    
    
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
        attempt(counter,turns,code);
        counter++;
    }while(counter<=turns);
}

/*
 * Function which receives and checks the accuracy of code guesses
 * Input:
 *      counter, turns, code
 * Output:
 *      none
 */
void attempt(int &counter, int turns, char code[]){
    string colStrg;
    char guess[SIZE][COL];
    char check[COL];
    char temp[COL];
    char trade;
    bool loop, swap;
    
    do{
        loop=false;
        cout << " |   |   |   |   |     Attempt " << counter << ":";
            cin >> colStrg;
            cin.ignore();
        for(int i=0; i<COL; i++){
            guess[counter-1][i]=colStrg[i];
        }
        if(colStrg.size()!=COL){ //If incorrect number of colors entered
            cout << "Invalid entry." << endl;
            loop=true;
        }
        for(int i=0; i<COL; i++){
            if(guess[counter-1][i]!='R'
             &&guess[counter-1][i]!='O'
             &&guess[counter-1][i]!='Y'
             &&guess[counter-1][i]!='G'
             &&guess[counter-1][i]!='B'
             &&guess[counter-1][i]!='P'){    //If any guessed colors don't match the valid color inputs
                cout << "Invalid entry." << endl;
                loop=true;
            }
        }
    }while(loop);   //End of user guess do-while loop
    
    //Transcribe guess and code into a check array
    for(int i=0; i<COL; i++){
        check[i]=guess[counter-1][i];
    }
    for(int i=0; i<COL; i++){
        temp[i]=code[i];
    }
    
    //Declare and initialize variables
    int posCorr=0;
    int colCorr=0;
    
    //Execute check function to find correct color and position
    compare(check,temp,posCorr,colCorr);
    
    //Output results of comparison
    board(guess,counter);
    cout << string(posCorr,'+') << string(colCorr,'~') << endl;
    
    //Output in the event of running out of turns
    if(counter==turns){
        cout << "You have run out of turns. The correct combination was: ";
        for(int i=0; i<COL; i++){
            cout << code[i] << " ";
        }
        //Sort code alphabetically
        do{
            swap=false;
            for(int i=0; i<3; i++){
                if(code[i]>code[i+1]){
                    trade=code[i];
                    code[i]=code[i+1];
                    code[i+1]=trade;
                    swap=true;
                }
            }
        }while (swap);
        cout << "The code, sorted alphabetically, is: ";
        for(int i=0; i<4; i++){
            cout << code[i] << " ";
        }
        cout << endl;
        cntinue();
    }
    
    //Output in the event of a completely correct guess
    if(posCorr==COL){
        cout << "Congratulations on cracking the code in " << counter << " turns!" << endl << endl << endl;
        //Sort code alphabetically
        do{
            swap=false;
            for(int i=0; i<3; i++){
                if(code[i]>code[i+1]){
                    trade=code[i];
                    code[i]=code[i+1];
                    code[i+1]=trade;
                    swap=true;
                }
            }
        }while (swap);
        cout << "The code, sorted alphabetically, is: ";
        for(int i=0; i<4; i++){
            cout << code[i] << " ";
        }
        counter=turns;
        cntinue();
    }
}

/*
 * Function which displays the guessed code in a "board-like" manner
 * Input:
 *      guess, counter
 * Output:
 *      none
 */
void board(char guess[][COL], int counter){
    for(int n; n<COL; n++){
        cout << " | " << guess[counter-1][n];
    }
    cout << " |   ";
}

/*
 * Function which pauses code execution, waiting for key-press
 * Input:
 *      none
 * Output:
 *      none
 */
void cntinue(){
    char x;
    cout << endl << endl << "Press any key to continue." << endl;
    cin.get(x);
    cout << string(50,'\n');
}

void compare(char check[],char temp[],int &pos,int &col){
    //Find Correct color in correct place
    for(int i=0; i<COL; i++){
        if(check[i]==temp[i]){
            pos++;
            temp[i]='Z';        //Removes matched code segment from future consideration
            check[i]='X';       //Removes guessed color from future consideration
        }
    }
    //Find correct color in wrong place
    for(int i=0; i<COL; i++){
        for(int n=0; n<COL; n++){
            if(temp[i]==check[n]){
                col++;
                check[n]='X';   //Removes guessed color from future consideration
                n=COL;
            }
        }
    }
}