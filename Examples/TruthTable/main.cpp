/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on June 30, 2014, 10:51 AM
 * Purpose: Display a truth table for logical operators
 */

//System Libraries
#include <iostream>

//User-defined Libraries

//Global Constants

//Function Prototypes

using namespace std;

//Begin execution
int main(int argc, char** argv) {
    
    //Declare and initialize variables
    char a = 50, b = 51, temp;
    bool x, y;
    x = true, y = true;
    
    //Output the values
    cout << "Initialized Values for a and b:" << endl;
    cout << "a=" << static_cast<int>(a) << ", b=" << static_cast<int>(b) << endl;
    cout << "a=" << a << ", b=" << b << endl << endl;
    
    //Swap with a memory position and output
    temp = a;
    a = b;
    b = temp;
    cout << "After the Swap in memory:" << endl;
    cout << "a=" << static_cast<int>(a) << ", b=" << static_cast<int>(b) << endl;
    cout << "a=" << a << ", b=" << b << endl << endl;
    
    //Swap in place and output
    a = a^b;
    b = a^b;
    a = a^b;
    cout << "After the Swap in place:" << endl;
    cout << "a=" << static_cast<int>(a)<< ", b=" << static_cast<int>(b) << endl;
    cout << "a=" << a << ", b=" << b << endl << endl;
    
    //Truth Table Header
    cout << "Truth Table" << endl;
    cout << "X  Y  !X  !Y  X&&Y  X||Y  X^Y^X  X^Y^Y  !(X&&Y)  !X||!Y  !(X||Y)  !X&&!Y" << endl;
    
    //First row
    cout << (x?'T':'F') << "  ";
    cout << (y?'T':'F') << "   ";
    cout << (!x?'T':'F') << "   ";
    cout << (!y?'T':'F') << "    ";
    cout << (x&&y?'T':'F') << "     ";
    cout << (x||y?'T':'F') << "     ";
    cout << (x^y^x?'T':'F') << "      ";
    cout << (x^y^y?'T':'F') << "       ";
    cout << (!(x&&y)?'T':'F') << "        ";
    cout << (!x||!y?'T':'F') << "       ";
    cout << (!(x||y)?'T':'F') << "        ";
    cout << (!x&&!y?'T':'F') << endl;
    
    //Second row
    y = false;
    cout << (x?'T':'F') << "  ";
    cout << (y?'T':'F') << "   ";
    cout << (!x?'T':'F') << "   ";
    cout << (!y?'T':'F') << "    ";
    cout << (x&&y?'T':'F') << "     ";
    cout << (x||y?'T':'F') << "     ";
    cout << (x^y^x?'T':'F') << "      ";
    cout << (x^y^y?'T':'F') << "       ";
    cout << (!(x&&y)?'T':'F') << "        ";
    cout << (!x||!y?'T':'F') << "       ";
    cout << (!(x||y)?'T':'F') << "        ";
    cout << (!x&&!y?'T':'F') << endl;
    
    //Third row
    x = false, y = true;
    cout << (x?'T':'F') << "  ";
    cout << (y?'T':'F') << "   ";
    cout << (!x?'T':'F') << "   ";
    cout << (!y?'T':'F') << "    ";
    cout << (x&&y?'T':'F') << "     ";
    cout << (x||y?'T':'F') << "     ";
    cout << (x^y^x?'T':'F') << "      ";
    cout << (x^y^y?'T':'F') << "       ";
    cout << (!(x&&y)?'T':'F') << "        ";
    cout << (!x||!y?'T':'F') << "       ";
    cout << (!(x||y)?'T':'F') << "        ";
    cout << (!x&&!y?'T':'F') << endl;
    
    //Fourth row
    y = false;
    cout << (x?'T':'F') << "  ";
    cout << (y?'T':'F') << "   ";
    cout << (!x?'T':'F') << "   ";
    cout << (!y?'T':'F') << "    ";
    cout << (x&&y?'T':'F') << "     ";
    cout << (x||y?'T':'F') << "     ";
    cout << (x^y^x?'T':'F') << "      ";
    cout << (x^y^y?'T':'F') << "       ";
    cout << (!(x&&y)?'T':'F') << "        ";
    cout << (!x||!y?'T':'F') << "       ";
    cout << (!(x||y)?'T':'F') << "        ";
    cout << (!x&&!y?'T':'F') << endl;
    
    //Finish him!!
    return 0;
}

