/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on June 27, 2014, 5:37 PM
 * Purpose: Calculate the amount of sales tax collected at a register
 */

//System Libraries
#include <iostream>
#include <iomanip>

//User-defined Libraries

//Global Constants

//Function Prototypes

using namespace std;

//Begin execution
int main(int argc, char** argv) {

    //Declare and initialize variables
    short year;
    float sales, saleTax, total;  //Sales made, Sales tax, Total money
    char month[10];
    
    //Request user input
    cout << "What month were the sales made? ";
    cin.getline(month, 10);
    cout << "What year were the sales made? ";
    cin >> year;
    cout << "How much was collected from sales during that time? $";
    cin >> total;
    
    //Calculations
    sales = total / 1.06;
    saleTax = total - sales;
    
    //Output data
    cout << setprecision(2) << fixed;
    cout << "During the month of " << month << " in " << year << ", of the collected $" << total << "," << endl;
    cout << "$" << saleTax << " was from sales tax, and $" << sales << " was from sales.";
    
    //Finish him!!
    return 0;
}

