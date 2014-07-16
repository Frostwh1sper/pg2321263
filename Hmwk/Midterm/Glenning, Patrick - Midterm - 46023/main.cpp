/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 14, 2014, 12:34 PM
 * Purpose: Midterm for C++ 46023
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
const float e=2.71828;        //Constant utilized by problem 6

//Function Prototypes
void menu();
int getN();
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();

//Begin execution
int main(int argc, char** argv) {

    //Declare variables
    int inN;    //Menu selection
    
    //Display menu
    do{
        menu();
        inN=getN();
        switch(inN){
            case 1: prob1(); break;
            case 2: prob2(); break;
            case 3: prob3(); break;
            case 4: prob4(); break;
            case 5: prob5(); break;
            case 6: prob6(); break;
            default: break;
        }
        
    }while(inN<7);
    cout << endl;
    
    //Finish him!!
    return 0;
}

/* 
 * Menu function
 * Displays menu for the midterm program
 * Inputs
 *      none
 * Outputs
 *      none
*/
void menu(){
    cout << "Enter 1 for problem 1" << endl;
    cout << "Enter 2 for problem 2" << endl;
    cout << "Enter 3 for problem 3" << endl;
    cout << "Enter 4 for problem 4" << endl;
    cout << "Enter 5 for problem 5" << endl;
    cout << "Enter 6 for problem 6" << endl;
    cout << "Enter 7 to exit" << endl;
}

/* 
 * getN function
 * Receives input for menu selection
 * Inputs
 *      none
 * Outputs
 *      inN
*/
int getN(){
    int inN;
    cin >> inN;
    return inN;
}

/* 
 * Problem 1 function
 * Fancy way to output a series of integers
*/
void prob1(){
    //Declare variables
    int num;    //Any positive integer
    
    //Inputs
    cout << "Enter any positive integer: ";
    cin >> num;
    
    //Outputs
    while(num>0){
        for(int i=num-1; i>0; i--){
            cout << " ";
        }
        cout << num << endl;
        num--;
    }
}

/* 
 * Problem 2 function
 * Shows individual number value with asterisk
*/
void prob2(){
    //Declare variables
    char a,b,c,d;       //4-digit combination
    
    //Inputs
    cout << "Enter any 4-digit number: ";
    cin >> a >> b >> c >> d;
    
    //Output
    if(a>='0' && a<='9'){
        cout << a << " " << string(a-48,'*') << endl;
    }
    else{
        cout << a << " ?" << endl;
    }
    if(b>='0' && b<='9'){
        cout << b << " " << string(b-48,'*') << endl;
    }
    else{
        cout << b << " ?" << endl;
    }
    if(c>='0' && c<='9'){
        cout << c << " " << string(c-48,'*') << endl;
    }
    else{
        cout << c << " ?" << endl;
    }
    if(d>='0' && d<='9'){
        cout << d << " " << string(d-48,'*') << endl;
    }
    else{
        cout << d << " ?" << endl;
    }
}

/* 
 * Problem 3 function
 * Simulates bank statement
*/
void prob3(){
    //Declare variables
    float bal;                  //Balance on the account
    unsigned short withd, depos;//Withdraw amount, Deposit amount
    char dummy;                 //Dummy variable for PIN input
    
    //Inputs
    cout << "Enter your PIN: ";
    cin >> dummy >> dummy >> dummy >> dummy;
    cout << "Initial balance on card: $";
    cin >> bal;
    cout << "Total debits during the month: $";
    cin >> withd;
    cout << "Total deposits during the month: $";
    cin >> depos;
    
    //Calculations
    bal+=depos;
    bal-=withd;
    
    //Outputs
    if(bal>=0){
        cout << "Your end of month balance is: $" << bal << endl;
    }
    else{
        bal-=27.75f;
        cout << "Your end of month balance is: -$" << bal*(-1) << endl;
        cout << "An overdraft fee of $27.75 has been assessed to the account." << endl <<
                "In order to make further charges, the balance must be zeroed" << endl <<
                "out and a new credit balance applied." << endl;
    }
}

/* 
 * Problem 4 function
 * Calculates Internet bill
*/
void prob4(){
    //Declare variables
    char package;       //Package letter
    int hours;          //Number of hours used
    float bill;         //Monthly bill
    int i;              //loop counter
    
    //Inputs
    cout << "Which subscription package are you enrolled in:" << endl;
    cout << "Package A: $19.95 per month, 5 hours access.  Additional hours" << endl;
    cout << "           are $0.75 up to 20 hours, then $1 for all additional" << endl;
    cout << "           hours." << endl;
    cout << "Package B: $24.95 per month, 15 hours access.  Additional hours" << endl;
    cout << "           are $0.75 up to 25 hours, then $0.50 for all additional" << endl;
    cout << "           hours." << endl;
    cout << "Package C: $29.75 per month, unlimited access." << endl;
    cin >> package;
    cout << "How many hours did you utilize during the last billing period? ";
    cin >> hours;
    
    //Outputs
    if(package=='a'||package=='A'){
        bill=19.95f;
        i=5;
        while(hours>5&&i<=15){
            bill+=0.75f;
            i++;
        }
        while(hours>15&&i<=hours){
            bill+=1.0f;
            i++;
        }
        cout << fixed << showpoint << setprecision(2);
        cout << "Your bill for the month is $" << bill << endl;
        if(bill>24.95f&&bill<=29.75f){
            cout << "You would save more money if you upgraded to package B." << endl;
        }
        if(bill>29.75f){
            cout << "You would save more money if you upgraded to package C." << endl;
        }
    }
    if(package=='b'||package=='B'){
        bill=24.95f;
        i=15;
        while(hours>15&&i<=25){
            bill+=0.75f;
            i++;
        }
        while(hours>25&&i<=hours){
            bill+=0.5f;
            i++;
        }
        cout << fixed << showpoint << setprecision(2);
        cout << "Your bill for the month is $" << bill << endl;
        if(hours<11){
            cout << "You would save more money if you downgraded to package A." << endl;
        }
        if(bill>29.75f){
            cout << "You would save more money if you upgraded to package C." << endl;
        }
    }
    if(package=='c'||package=='C'){
        bill=29.75f;
        cout << fixed << showpoint << setprecision(2);
        cout << "Your bill for the month is $" << bill << endl;
        if(hours<21&&hours>=11){
            cout << "You would save more money if you downgraded to package B." << endl;
        }
        if(hours<11){
            cout << "You would save more money if you downgraded to package A." << endl;
        }
    }
}

/* 
 * Problem 5 function
 * Calculates paycheck
*/
void prob5(){
    //Declare variables
    int hours;          //Hours worked
    float paycheck=0.0f;//Paycheck amount
    float rate;         //Hourly wage
    int i=1;            //Loop counter
    
    //Inputs
    cout << "How many hours did you work this week? ";
    cin >> hours;
    cout << "What is your hourly pay? $";
    cin >> rate;
    
    //Calculations
    while(i<=40&&i<=hours){
        paycheck+=rate;
        i++;
    }
    while(i>40&&i<50&&i<=hours){
        paycheck+=(rate*2.0f);
        i++;
    }
    while(i>=50&&i<=hours){
        paycheck+=(rate*3.0f);
        i++;
    }
    
    //Output
    cout << "Your paycheck will be $" << paycheck << endl;
}

/* 
 * Problem 6 function
 * approximates e^x
*/
void prob6(){
    //Declare variables
    int x;
    int terms;
    float approx=1.0f, error=0.0f;
    float ratio=0.0f;
    
    //Inputs
    cout << "Enter a positive integer value for x? ";
    cin >> x;
    cout << "How many terms would you like to approximate with? ";
    cin >> terms;
    
    //Calculations
    for(int i=1; i<=terms; i++){
        ratio=static_cast<float>(pow(x,i));
        for(int n=1;n<=i;n++){
            ratio/=n;
        }
        approx+=ratio;
    }
    error=(approx-static_cast<float>(pow(e,x)))/static_cast<float>(pow(e,x));
    
    //Output
    cout << "The approximation of e^" << x << " is " << setprecision(9) << approx;
    cout << ", which has an error of " << setprecision(2) << error*100;
    cout << "%, when calculated out with " << terms << " terms" << endl;
}