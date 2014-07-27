/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 *
 * Created on July 26, 2014, 10:53 PM
 */

//System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants
const int SUITS=4;

//Function Prototypes
void menu();
void setup(int &);
int getN();
int deckSiz(int [][SUITS],int);
void suitTyp(int);
int arrSum(int [], int);

//Begin execution
int main(int argc, char** argv) {
    
    //Seed RNG
    srand(time(0));
    
    //Declare and initialize variables
    int decks=1;
    int choice;
    int suit, card;
    bool game=true;
    int player[11];
    int house[11];
    int hit;
    
    //Generate deck values
    int deck[13*decks][SUITS];
    for(int n=0; n<SUITS; n++){
        int val=1;
        for(int i=0; i<(13*decks); i++){
            if(val==14) val=1;
            int temp=val;
            if(val>10 && val<14){
                val=10;
            }
            if(val==1) val=11;
            deck[i][n]=val;
            val=temp;
            val++;
        }
    }
    do{
        //Display menu
        menu();
        
        //User input
        choice=getN();
        
        //Menu selection
        switch(choice){
            case 1:{
                
                //Declare variables
                int pCount=2;   //Keeps count of number of cards in player's hand
                int hCount=2;   //Keeps count of number of cards in house's hand
                
                //If deck goes below 10 cards, reshuffle
                int deck[13*decks][SUITS];
                for(int n=0; n<SUITS; n++){
                    int val=1;
                    for(int i=0; i<(13*decks); i++){
                        if(val==14) val=1;
                        int temp=val;
                        if(val>10 && val<14){
                            val=10;
                        }
                        if(val==1) val=11;
                        deck[i][n]=val;
                        val=temp;
                        val++;
                    }
                }
                
                //Deal first two cards to player
                for(int i=0; i<2; i++){
                    do{
                        suit=rand()%4;
                        card=rand()%(13*decks);
                        player[i]=deck[card][suit];
                    }while(deck[card][suit]==0);
                    deck[card][suit]=0;
                    cout << "You draw: ";
                    if(card==0){
                        cout << "Ace of ";
                        suitTyp(suit);
                        cout << endl;
                    }
                    if(card>0 && card<10){
                        cout << card+1 << " of ";
                        suitTyp(suit);
                        cout << endl;
                    }
                    if(card==10){
                        cout << "Jack of ";
                        suitTyp(suit);
                        cout << endl;
                    }
                    if(card==11){
                        cout << "Queen of ";
                        suitTyp(suit);
                        cout << endl;
                    }
                    if(card==12){
                        cout << "King of ";
                        suitTyp(suit);
                        cout << endl;
                    }
                }
                
                //Deal first two cards to dealer
                for(int i=0; i<2; i++){
                    do{
                        suit=rand()%4;
                        card=rand()%(13*decks);
                        house[i]=deck[card][suit];
                    }while(deck[card][suit]==0);
                    deck[card][suit]=0;
                }
                cout << "House shows: ";
                if(card==0){
                    cout << "Ace of ";
                    suitTyp(suit);
                    cout << endl;
                }
                if(card>0 && card<10){
                    cout << card+1 << " of ";
                    suitTyp(suit);
                    cout << endl;
                }
                if(card==10){
                    cout << "Jack of ";
                    suitTyp(suit);
                    cout << endl;
                }
                if(card==11){
                    cout << "Queen of ";
                    suitTyp(suit);
                    cout << endl;
                }
                if(card==12){
                    cout << "King of ";
                    suitTyp(suit);
                    cout << endl;
                }
                
                do{
                //User decides whether to hit or stand
                cout << "1) Hit" << endl <<
                        "2) Stand" << endl;
                cin >> hit;
                cin.ignore();
                switch(hit){
                    case 1:{
                        do{
                            suit=rand()%4;
                            card=rand()%13;
                            player[pCount]=deck[card][suit];
                        }while(deck[card][suit]==0);
                        deck[card][suit]=0;
                        cout << "You draw: ";
                        if(card==0){
                            cout << "Ace of ";
                            suitTyp(suit);
                            cout << endl;
                        }
                        if(card>0 && card<10){
                            cout << card+1 << " of ";
                            suitTyp(suit);
                            cout << endl;
                        }
                        if(card==10){
                            cout << "Jack of ";
                            suitTyp(suit);
                            cout << endl;
                        }
                        if(card==11){
                            cout << "Queen of ";
                            suitTyp(suit);
                            cout << endl;
                        }
                        if(card==12){
                            cout << "King of ";
                            suitTyp(suit);
                            cout << endl;
                        }
                        pCount++;
                        break;
                    }
                    case 2:{
                        cout << "You stand with " << arrSum(player,pCount) << endl;
                        break;
                    }
                    default:{
                        
                        break;
                    }
                }
                }while(hit==1);
                
                break;
            }
            case 2:{
                setup(decks);
                //Generate deck values
                int deck[13*decks][SUITS];
                for(int n=0; n<SUITS; n++){
                    int val=1;
                    for(int i=0; i<(13*decks); i++){
                        if(val==14) val=1;
                        int temp=val;
                        if(val>10 && val<14){
                            val=10;
                        }
                        if(val==1) val=11;
                        deck[i][n]=val;
                        val=temp;
                        val++;
                    }
                }
                break;
            }
            case 3:{
                game=false;
                cout << string(50,'\n') << "Exiting blackjack..." << string(2,'\n');
                break;
            }
            case 4:{
                for(int i=0; i<SUITS; i++){
                    for(int n=0; n<(13*decks); n++){
                        cout << deck[n][i] << " ";
                    }
                    cout << endl;
                }
            }
            default:{
                cout << "Invalid input, please re-enter." << endl;
                break;
            }
        }
        
    }while(game);

    return 0;
}

/*
 * Function that displays the main menu
 */
void menu(){
    cout << " ______________________________________________________ " << endl <<
            "*                                                      *" << endl <<
            "*        WELCOME TO BLACKJACK!!                        *" << endl <<
            "*                                                      *" << endl <<
            "*        1) Play Hand                                  *" << endl <<
            "*        2) Change number of decks                     *" << endl <<
            "*        3) Exit Blackjack                             *" << endl <<
            "*                                                      *" << endl <<
            "*______________________________________________________*" << endl <<
            " Enter your selection: ";
}

/*
 * Function that returns an integer
 */
int getN(){
    int n;
    cin >> n;
    cin.ignore();
    cout << string(50,'\n');
    return n;
}

/*
 * Function that changes the number of decks being played with
 */
void setup(int &x){
    cout << "Enter the number of decks you would like to play with (1-2): ";
    do{
        cin >> x;
        cin.ignore();
        if(x<1 || x>2) cout << "Invalid input, please re-enter: ";
    }while(x<1 || x>2);
}

/*
 * Function that determines number of cards remaining in the deck
 */
int deckSiz(int array[][SUITS], int decks){
    int count=52*decks;
    for(int i=0; i<SUITS; i++){
        for(int n=0; n<(13*decks); n++){
            if(array[i][n]==0) count--;
        }
    }
    return count;
}

void suitTyp(int suit){
    switch(suit){
        case 0:{
            cout << "clubs"; 
            break;
        }
        case 1:{
            cout << "diamonds"; 
            break;
        }
        case 2:{
            cout << "spades"; 
            break;
        }
        case 3:{
            cout << "hearts"; 
            break;
        }
    }
}

/*
 * Function that sums the values of cards in an array
 */
int arrSum(int arr[], int count){
    int sum=arr[0];
    for(int i=1; i<count; i++){
        sum+=arr[i];
    }
    return sum;
}