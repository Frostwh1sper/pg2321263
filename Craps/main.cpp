/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 9, 2014, 9:43 AM
 * Purpose: To program along with examples given during lecture
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
    
    //Set up the random number generator
    unsigned seed=time(0);
    srand(seed);
    
    //Declare and initialize variables
    int sum;                    //Sum of two dice
    int d6_1, d6_2;             //The dice
    bool loop=true;
    bool game=true;
    float win=0;                //Total wins
    short counter=0;            //Total win or lose rolls
    float winLoss;              //Ratio of wins to losses
    
    //Outputs
    do{
        do{
            //Calculations
            d6_1=1+rand()%6;
            d6_2=1+rand()%6;
            sum=d6_1+d6_2;
        
            switch(sum){
                case 7: case 11:{
                    cout << "You rolled a " << sum << "! You win!!" << endl;
                    win++;
                    counter++;
                    loop=false;
                    break;
                }
                
                case 2: case 3: case 12:{
                    cout << "You rolled a " << sum << "! Sorry, you lose." << endl;
                    counter++;
                    loop=false;
                    break;
                }
                
                default:{
                    /*
                    cout << "You rolled " << sum << ", roll again." << endl;
                     */
                    break;
                }
            }
        }while(loop);
        
        //Output win/loss ratio
        winLoss=win/counter*100.0f;
        cout << "You've won " << setprecision(1) << fixed << winLoss << "% of the time." << endl;
        counter=0;
        win=0;
        
        //Determine whether to repeat program
        cout << "Roll again? (y/n) ";
        char choice;
        cin >> choice;
        cin.ignore();
        switch(choice){
            case 'n': case 'N':{
                cout << endl;
                game=false;
            }
            default:{
                cout << endl;
                loop=true;
            }
        }
        
    }while(game);
    
    //Finish him!!
    return 0;
}

