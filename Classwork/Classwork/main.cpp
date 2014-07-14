/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 14, 2014, 10:41 AM
 * Purpose: Practicing with function prototypes
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float save1(float,float,int);
float save2(float,float,int);
float save3(float,float,int);
float save4(float,float,int);

//Begin Program Execution
int main(int argc, char** argv) {

    //Declare Variables
    float prin=100;             //Principal
    float intrst=5;             //Interest, in percent
    float periods=72/intrst+1;       //Rule of 72, ensures doubled principal
    
    //Process - Calculate the savings
    float sav1=save1(prin,intrst/100,periods);
    float sav2=save2(prin,intrst/100,periods);
    float sav3=save3(prin,intrst/100,periods);
    float sav4=save4(prin,intrst/100,periods);
    
    //Output the results
    cout << fixed << showpoint << setprecision(2);
    cout << "Savings with power function = $" << sav1 << endl;
    cout << "Savings with loop construct = $" << sav2 << endl;
    cout << "Savings with log & exponent = $" << sav3 << endl;
    cout << "Savings with recursion      = $" << sav4 << endl;
    
    //Finish him!!
    return 0;
}

/*Savings function utilizing the power function
 * Inputs
 *      p=principal in $'s
 *      i=interest in decimal
 *      n=compounding periods in years
 * Output
 *      float value representing balance in dollars
*/
float save1(float p,float i,int n){
    return p*pow(1+i,n);
}

/*Savings function utilizing for loop
 * Inputs
 *      p=principal in $'s
 *      i=interest in decimal
 *      n=compounding periods in years
 * Output
 *      float value representing balance in dollars
*/
float save2(float p,float i,int n){
    for(int year=1; year<=n; year++){
        p*=(1+i);
    }
    return p;
}

/*Savings function utilizing log & exponential functions
 * Inputs
 *      p=principal in $'s
 *      i=interest in decimal
 *      n=compounding periods in years
 * Output
 *      float value representing balance in dollars
*/
float save3(float p,float i,int n){
    return p*exp(n*log(1+i));
}

/*Savings function calling itself (i.e. recursion)
 * Inputs
 *      p=principal in $'s
 *      i=interest in decimal
 *      n=compounding periods in years
 * Output
 *      float value representing balance in dollars
*/
float save4(float p,float i,int n){
    if(n==0) return p;
    return save4(p,i,n-1)*(1+i);
}