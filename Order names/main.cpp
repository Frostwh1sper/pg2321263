/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on June 30, 2014, 1:21 PM
 * Purpose: Alphabetically order 3 input names
 */

//System Libraries
#include <iostream>
#include <cstring>

//User-defined Libraries
using namespace std;

//Global Constants

//Function Prototypes
int main(int argc, char** argv) {

    //Declare and initialize variables
    const int SIZE = 20;
    char name1[SIZE], name2[SIZE], name3[SIZE];
    
    //Request name input
    cout << "Enter three different first names:" << endl;
    cout << "What is the first name?" << endl;
    cin.getline(name1,SIZE);
    cout << "What is the second name?" << endl;
    cin.getline(name2,SIZE);
    cout << "What is the third name?" << endl;
    cin.getline(name3,SIZE);
    
    //Compare strings
    cout << "These are the names, listed alphabetically:" << endl;
    if (strcmp(name1,name2)<0)
    {
        if (strcmp(name2,name3)<0)
        {
            cout << name1 << endl << name2 << endl << name3;
        }
        if (strcmp(name3,name1)<0)
        {
            cout << name3 << endl << name1 << endl << name2;
        }
        if (strcmp(name1,name3)<0)
        {
            if (strcmp(name3,name2)<0)
            {
                cout << name1 << endl << name3 << endl << name2;
            }
        }
    }
    if (strcmp(name2,name1)<0)
    {
        if (strcmp(name1,name3)<0)
        {
            cout << name2 << endl << name1 << endl << name3;
        }
        if (strcmp(name3,name2)<0)
        {
            cout << name3 << endl << name2 << endl << name1;
        }
        if (strcmp(name2,name3)<0)
        {
            if (strcmp(name3,name1)<0)
            {
                cout << name2 << endl << name3 << endl << name1;
            }
        }
    }
    
    
    //Finish him!!
    return 0;
}

