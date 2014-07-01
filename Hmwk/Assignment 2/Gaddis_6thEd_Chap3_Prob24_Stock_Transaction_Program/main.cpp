/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 1, 2014, 12:50 PM
 * Purpose: Calculate the figures from a stock transaction
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User-defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {

    //Declare and initialize variables
    int numShar = 1000;         //Number of shares in the transaction
    float buyShar = 32.87;      //Price per share when purchased
    float selShar = 33.92;      //Price per share when sold
    float rate = 0.02;          //Stock broker's commission rate
    float buyComm;              //Broker's commission when shares were purchased
    float selComm;              //Broker's commission when shares were sold
    float cost;                 //Share value when purchased
    float value;                //Share value when sold
    float profit;               //Profit from overall transaction    
    
    //Calculations
    cost = numShar * buyShar;
    value = numShar * selShar;
    buyComm = rate * cost;
    selComm = rate * value;
    profit = value - cost - buyComm - selComm;
    
    //Output information
    cout << "Purchase transaction" << endl;
    cout << setw(25) << "Price per share:" << setw(2) << buyShar << endl;
    cout << setw(25) << "Shares purchased:" << setw(2) << numShar << endl;
    cout << setw(25) << "Subtotal:" << setw(2) << cost << endl;
    cout << setw(25) << "Commission on sale:" << setw(2) << buyComm << endl;
    cout << setw(25) << "Total:" << setw(2) << cost + buyComm << endl;
    cout << endl;
    cout << "Sell transaction" << endl;
    cout << setw(25) << "Price per share:" << setw(2) << buyShar << endl;
    cout << setw(25) << "Shares purchased:" << setw(2) << numShar << endl;
    cout << setw(25) << "Subtotal:" << setw(2) << cost << endl;
    cout << setw(25) << "Commission on sale:" << setw(2) << buyComm << endl;
    cout << setw(25) << "Total:" << setw(2) << cost + buyComm << endl;
    cout << endl;
    
    //Finish him!!
    return 0;
}

