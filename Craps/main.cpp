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
    int sum, sum2;              //Sum of two dice
    int d6_1, d6_2;             //The dice
    bool loop=true;
    bool game=true;
    bool reroll=true;
    float win=0;                //Total wins
    float counter=0;            //Total win or lose rolls
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
                    cout << "You rolled " << sum << "! You win!!" << endl;
                    win++;
                    counter++;
                    loop=false;
                    break;
                }
                
                case 2: case 3: case 12:{
                    cout << "You rolled " << sum << ". Sorry, you lose." << endl;
                    counter++;
                    loop=false;
                    break;
                }
                
                default:{
                    do{
                        d6_1=1+rand()%6;
                        d6_2=1+rand()%6;
                        sum2=d6_1+d6_2;
                        switch(sum2){
                            case 7:{
                                cout << "You rolled " << sum << " then 7. You lose." << endl;
                                counter++;
                                loop=false;
                                reroll=false;
                                break;
                            }
                            default:{
                                if(sum==sum2){
                                    cout << "You rolled double " << sum << "'s! You win!" << endl;
                                    win++;
                                    counter++;
                                    loop=false;
                                    reroll=false;
                                }
                                else{
                                    counter++;
                                }
                                break;
                            }
                        }
                    }while(reroll);
                }
            }
        }while(loop);
        
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

