/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 7, 2014, 10:56 AM
 * Purpose: Determine which fluids will freeze or boil at input temperature
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin execution
int main(int argc, char** argv) {

    //Declare and initialize variables
    int ethylF=-173, ethylB=172;        //Freezing and boiling point of Ethyl Alcohol
    int mercF=-38, mercB=676;           //Freezing and boiling point of Mercury
    int oxyF=-362, oxyB=-306;           //Freezing and boiling point of Oxygen
    int watF=32, watB=212;              //Freezing and boiling point of Water
    int tempF;
    
    //User input
    cout << "This program will determine whether ethyl alcohol, mercury, oxygen, or water will freeze or boil at any given temperature." << endl;
    cout << "What temperature would you like to check? (Fahrenheit) ";
    cin >> tempF;
    
    //Output
    cout << "At " << tempF << " degrees Fahrenheit:" << endl;
    if (tempF<=-173||tempF>=172){
        if(tempF<=-173){
            cout << "Ethyl alcohol freezes" << endl;
        }
        if (tempF>=172){
            cout << "Ethyl alcohol boils" << endl;
        }
    }
    if (tempF<=-38||tempF>=676){
        if(tempF<=-38){
            cout << "Mercury freezes" << endl;
        }
        if (tempF>=676){
            cout << "Mercury boils" << endl;
        }
    }
    if (tempF<=-362||tempF>=-306){
        if(tempF<=-362){
            cout << "Oxygen freezes" << endl;
        }
        if (tempF>=-306){
            cout << "Oxygen boils" << endl;
        }
    }
    if (tempF<=32||tempF>=212){
        if(tempF<=32){
            cout << "Water freezes" << endl;
        }
        if (tempF>=212){
            cout << "Water boils" << endl;
        }
    }
    
    //Finish him!!
    return 0;
}

