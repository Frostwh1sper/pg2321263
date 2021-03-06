/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 22, 2014, 12:50 PM
 * Purpose: Execute 10 problems from Gaddis 6thEd, Chapter 6
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//User Libraries

//Global Constants
const float G=9.80f;

//Function Prototypes
void menu();            //Displays main menu
int slction();          //Returns menu selection
void cntinue();         //Waits for input before continuing
void problem1();        //Gaddis 6thEd Chap6 Prob1
void problem2();        //Gaddis 6thEd Chap6 Prob4
void problem3();        //Gaddis 6thEd Chap6 Prob5
void problem4();        //Gaddis 6thEd Chap6 Prob6
void problem5();        //Gaddis 6thEd Chap6 Prob9
void problem6();        //Gaddis 6thEd Chap6 Prob11
void problem7();        //Gaddis 6thEd Chap6 Prob14
void problem8();        //Gaddis 6thEd Chap6 Prob15
void problem9();        //Gaddis 6thEd Chap6 Prob19
void problem10();       //Gaddis 6thEd Chap6 Prob21
float calcRet(float,float);
int numAcc();
void findLow(int,int,int,int,int);
float fallDst(int);
float kinetic(int,float);
float presVal(float,float,int);
void jdgData(float &);
void calcScr(float,float,float,float,float);
float findLo(float,float,float,float,float);
float findHi(float,float,float,float,float);
float hosptal(int,float,float,float);
float hosptal(float,float);
int populat(int,int,int);
float stocks(int,float,float,float,float);
bool isPrime(int);

//Begin execution
int main(int argc, char** argv) {
    
    //Declare and initialize variables
    int choice;
    
    //Display Menu
    do{
        menu();

        //User selection
        choice=slction();

        //Problems
        switch(choice){
            case 1:{
                problem1();
                cout << "Press any key to return to the main menu." << endl;
                cntinue();
                break;
            }
            case 2:{
                problem2();
                cout << "Press any key to return to the main menu." << endl;
                cntinue();
                break;
            }
            case 3:{
                problem3();
                cout << "Press any key to return to the main menu." << endl;
                cntinue();
                break;
            }
            case 4:{
                problem4();
                cout << "Press any key to return to the main menu." << endl;
                cntinue();
                break;
            }
            case 5:{
                problem5();
                cout << "Press any key to return to the main menu." << endl;
                cntinue();
                break;
            }
            case 6:{
                problem6();
                cout << "Press any key to return to the main menu." << endl;
                cntinue();
                break;
            }
            case 7:{
                problem7();
                cout << "Press any key to return to the main menu." << endl;
                cntinue();
                break;
            }
            case 8:{
                problem8();
                cout << "Press any key to return to the main menu." << endl;
                cntinue();
                break;
            }
            case 9:{
                problem9();
                cout << "Press any key to return to the main menu." << endl;
                cntinue();
                break;
            }
            case 10:{
                problem10();
                cout << "Press any key to return to the main menu." << endl;
                cntinue();
                break;
            }
            default:{
                break;
            }
        }
        cout << string(50,'\n');
    }while(choice<11);
    
    cout << "Exiting program..." << endl << endl;
    
    //Finish him!!
    return 0;
}
/*
 * 
 * 
 */
void menu(){
    
    cout << "           ________________________________________________ " << endl <<
            "          *                                                *" << endl <<
            "          *                                                *" << endl <<
            "          *    Glenning, Patrick - Assignment 5 - 46023    *" << endl <<
            "          *                                                *" << endl <<
            "          *    1)  Markup                                  *" << endl <<
            "          *    2)  Safest Driving Area                     *" << endl <<
            "          *    3)  Falling Distance                        *" << endl <<
            "          *    4)  Kinetic Energy                          *" << endl <<
            "          *    5)  Present Value                           *" << endl <<
            "          *    6)  Star Search                             *" << endl <<
            "          *    7)  Overloaded Hospital                     *" << endl <<
            "          *    8)  Population                              *" << endl <<
            "          *    9)  Stock Profit                            *" << endl <<
            "          *    10) isPrime Function                        *" << endl <<
            "          *    11) Exit Program                            *" << endl <<
            "          *________________________________________________*" << endl <<
            "             Enter your selection number: ";
    
}

/*
 * 
 * 
 */
int slction(){
    
    //Declare variables
    int n;
    bool x=true;
    
    //User input
    do{
        cin >> n;
        cin.ignore();
        if(n>=1 && n<=11){
            cout << string(50,'\n');
        }
        else{
            cout << "             Please enter a valid input: ";
        }
    }while(n<1 || n>11);
    return n;
}

void cntinue(){
    char x;
    cin.get(x);
    cin.ignore();
}

/*
 * Gaddis 6thEd Chap6 Prob1 - Markup
 * Purpose: Displays an item's retail price
 */
void problem1(){
    
    //Declare and initialize variables
    float wholSal,markup,retail;
    
    //User input
    cout << "What is the wholesale price for the item? $";
    cin >> wholSal;
    cout << "What is the markup percentage? ";
    cin >> markup;
    markup/=100;
    
    //Calculate price
    retail=calcRet(wholSal, markup);
    
    //Display retail price after markup
    cout << setprecision(2) << fixed;
    cout << "The retail price is $" << retail << endl;
}

/*
 * Gaddis 6thEd Chap6 Prob4 - Safest Driving Area
 * Purpose: Displays the safest driving route
 */
void problem2(){
    
    //Declare and initialize variables
    int accEst, accNth, accWst, accSth, accCnt;
    
    //User inputs
    cout << "How many accidents were reported in the eastern part of town? ";
    accEst=numAcc();
    cout << "How many accidents were reported in the northern part of town? ";
    accNth=numAcc();
    cout << "How many accidents were reported in the western part of town? ";
    accWst=numAcc();
    cout << "How many accidents were reported in the southern part of town? ";
    accSth=numAcc();
    cout << "How many accidents were reported in the central part of town? ";
    accCnt=numAcc();
    
    //Display safest route
    findLow(accEst,accNth,accWst,accSth,accCnt);
}

/*
 * Gaddis 6thEd Chap6 Prob5 - Falling Distance
 * Purpose: Find the distance an object has fallen after a period of time
 */
void problem3(){
    
    //Declare and initialize variables
    float dist;
    int time;
    
    //User input
    cout << "How long has the object been falling (in seconds)? ";
    cin >> time;
    
    //Find the distance traveled
    dist=fallDst(time);
    
    //Display distance fallen
    cout << "The object has fallen " << setprecision(1) << fixed << dist << " meters." << endl;
}

/*
 * Gaddis 6thEd Chap6 Prob6 - Kinetic Energy
 * Purpose: Calculates the kinetic energy in an object
 */
void problem4(){
    
    //Declare and initialize variables
    int mass;
    float veloc;
    float kinEner;
    
    //User inputs
    cout << "What is the mass of the object (in kilograms)? ";
    cin >> mass;
    cout << "What is the speed of the object (in meters per second)? ";
    cin >> veloc;
    
    //Calculations
    kinEner=kinetic(mass,veloc);
    
    //Display results
    cout << "That object has a kinetic energy of " << setprecision(2) << fixed << kinEner << " Joules." << endl;
}

/*
 * Gaddis 6thEd Chap6 Prob9 - Present Value
 * Purpose: Calculate the initial investment needed to reach a future goal
 */
void problem5(){
    
    //Declare and initialize variables
    float present, future, annRate;
    unsigned short numYrs;
    
    //User inputs
    cout << "What future value would you like in your account? $";
    cin >> future;
    cout << "What is your annual interest rate? ";
    cin >> annRate;
    annRate/=100;
    cout << "In how many years would you like to have your future balance? ";
    cin >> numYrs;
    
    //Calculations
    present=presVal(future,annRate,numYrs);
    
    //Display results
    cout << "In order to have $" << future << " in your account within " << numYrs << 
            " years, you require an initial investment of $" << setprecision(2) << 
            fixed << present << endl;
}

/*
 * Gaddis 6thEd Chap6 Prob11 - Star Search
 * Purpose: Calculate the final judges score at a talent competition
 */
void problem6(){
    
    //Declare and initialize variables
    float judge1, judge2, judge3, judge4, judge5;   //Scores by judge
    
    //User input
        jdgData(judge1);
        jdgData(judge2);
        jdgData(judge3);
        jdgData(judge4);
        jdgData(judge5);
    
    //Calculate and display final score
    calcScr(judge1,judge2,judge3,judge4,judge5);
}

/*
 * Gaddis 6thEd Chap6 Prob14 - Overloaded Hospital
 * Purpose: Calculate the total charges for a hospital visit
 */
void problem7(){
    
    //Declare and initialize variables
    int patient;
    int numDays;
    float rate, inMeds, inServ, outMed, outSrv, balance;
    
    
    //User input
    do{
        cout << "Enter 1 for in-patient care." << endl <<
                "Enter 2 for out-patient care." << endl <<
                "Enter 3 to terminate the program." << endl;
        cin >> patient;
        cin.ignore();
    }while(patient>2 || patient<1);
    switch(patient){
        case 1:{
            do{
                cout << "Enter information as requested:" << endl <<
                        "Number of days spent in the hospital: ";
                cin >> numDays;
                if(numDays<0) cout << "Invalid number of days, please re-enter: ";
            }while(numDays<0);
            do{
                cout << "Daily rate for room: $";
                cin >> rate;
                if(rate<0) cout << "Invalid daily rate, please re-enter: $";
            }while(rate<0);
            do{
                cout << "Hospital medication charges: $";
                cin >> inMeds;
                if(inMeds<0) cout << "Invalid medication charges, please re-enter: $";
            }while(inMeds<0);
            do{
                cout << "Charges for services (lab tests, etc): $";
                cin >> inServ;
                if(inServ<0) cout << "Invalid service charges, please re-enter: $";
            }while(inServ<0);
            
            //Calculations
            balance=hosptal(numDays,rate,inMeds,inServ);
            
            //Display total charges
                cout << "Your balance is: $" << setprecision(2) << fixed << balance << endl;
            break;
        }
        case 2:{
            do{
                cout << "Hospital medication charges: $";
                cin >> outMed;
                if(outMed<0) cout << "Invalid medication charges, please re-enter: $";
            }while(outMed<0);
            do{
                cout << "Charges for services (lab tests, etc): $";
                cin >> outSrv;
                if(outSrv<0) cout << "Invalid service charges, please re-enter: $";
            }while(outSrv<0);
            
            //Calculations
            balance=hosptal(outMed,outSrv);
            
            //Display total charges
                cout << "Your balance is: $" << setprecision(2) << fixed << balance << endl;
            break;
        }
        default:{
            cout << "Terminating program..." << endl << endl;
            break;
        }
    }
}

/*
 * Gaddis 6thEd Chap6 Prob15 - Population
 * Purpose: 
 */
void problem8(){
    
    //Declare and initialize variables
    int popBeg, popFin, yrs, brthRat, dethRat;
    
    //User inputs
    cout << "What is the starting population? ";
    do{
        cin >> popBeg;
        if(popBeg<2) cout << "The starting population must be greater than 1. Re-enter:";
    }while(popBeg<2);
    cout << "What is the annual birth rate? ";
    do{
        cin >> brthRat;
        if(brthRat<0) cout << "The birth rate mustn't be negative. Re-enter: ";
    }while(brthRat<0);
    cout << "What is the annual death rate? ";
    do{
        cin >> dethRat;
        if(dethRat<0) cout << "The death rate mustn't be negative. Re-enter: ";
    }while(dethRat<0);
    cout << "How many years would you like to display? ";
    do{
        cin >> yrs;
        if(yrs<1) cout << "The number of years must be greater than 0. Re-enter: ";
    }while(yrs<1);
    
    //Calculations and display
    for(int i=0; i<yrs; i++){
        popFin=populat(popBeg,brthRat,dethRat);
        popBeg=popFin;
        cout << "Population, year " << setw(2) << i+1 << ": " << setw(9) << popFin << endl;
    }
}

/*
 * Gaddis 6thEd Chap6 Prob19 - Stock Profit
 * Purpose: 
 */
void problem9(){
    
    //Declare and initialize variables
    int numShar;
    float buy, buyComm, sale, salComm, profit;
    
    //User inputs
    cout << "How many shares were traded? ";
    cin >> numShar;
    cout << "What was the purchase price per share? $";
    cin >> buy;
    cout << "What was the commission on the purchase? $";
    cin >> buyComm;
    cout << "What was the sell price per share? $";
    cin >> sale;
    cout << "What was the commission on the sale? $";
    cin >> salComm;
    
    //Calculations
    profit=stocks(numShar,buy,buyComm,sale,salComm);
    
    //Display profit or loss
    if(profit>=0){
        cout << "Your trades resulted in a net $" << profit << endl;
    }
    else{
        profit*=(-1);
        cout << "Your trades resulted in a net -$" << profit << endl;
    }
    
}

/*
 * Gaddis 6thEd Chap6 Prob21 - isPrime Function
 * Purpose: 
 */
void problem10(){
    
    //Declare and initialize variables
    int num;
    bool prime=true;
    
    //User input
    cout << "Enter any positive integer to determine whether or not it is a prime number: ";
    do{
        cin >> num;
        if(num<2) cout << num << " is not a positive integer value, try again: ";
    }while(num<2);
    
    //Determine whether it is prime
    if(isPrime(num)){
        cout << num << " is a prime number." << endl;
    }
    else{
        cout << num << " is not a prime number." << endl;
    }
}

/*
 * Inputs:
 *      wholSal, markup
 * Outputs:
 *      ret
 */
float calcRet(float w, float m){
    float ret;
    ret=w*(1+m);
    return ret;
}

/*
 * Inputs:
 *      none
 * Outputs:
 *      accdnts
 */
int numAcc(){
    int accdnts;
    do{
        cin >> accdnts;
        if(accdnts<0) cout << "Invalid input, please re-enter: ";
    }while(accdnts<0);
    return accdnts;
}

/*
 * Inputs:
 *      accEst, accNth, accWst, accSth, accCnt
 * Outputs:
 *      none
 */
void findLow(int e, int n, int w, int s, int c){
    if(e<n && e<w && e<s && e<c){
        cout << "The safest route is through the eastern part of town." << endl;
    }
    if(n<e && n<w && n<s && n<c){
        cout << "The safest route is through the northern part of town." << endl;
    }
    if(w<e && w<n && w<s && w<c){
        cout << "The safest route is through the western part of town." << endl;
    }
    if(s<e && s<n && s<w && s<c){
        cout << "The safest route is through the southern part of town." << endl;
    }
    if(c<e && c<n && c<w && c<s){
        cout << "The safest route is through the central part of town." << endl;
    }
}

/*
 * Inputs:
 *      time
 * Outputs:
 *      dist
 */
float fallDst(int t){
    float d;
    d=0.5f*G*t*t;
    return d;
}

/*
 * Inputs:
 *      mass, veloc
 * Outputs:
 *      kinEner
 */
float kinetic(int m, float v){
    float ke;
    ke=0.5f*m*v*v;
    return ke;
}

/*
 * Inputs:
 *      
 * Outputs:
 *      
 */
float presVal(float f, float r, int n){
    float p;
    p=f/pow(1+r,n);
    return p;
}

/*
 * Inputs:
 *      i, judge[i]
 * Outputs:
 *      none
 */
void jdgData(float &score){
    cout << "Enter judge's score: ";
    do{
        cin >> score;
        if(score<0 || score>10) cout << "Invalid judges score, please enter a score between 0 and 10: ";
    }while(score<0 || score>10);
}

/*
 * Inputs:
 *      judge[i]
 * Outputs:
 *      none
 */
void calcScr(float a, float b, float c, float d, float e){
    float low, high, ave;
    //Find the lowest score
        low=findLo(a,b,c,d,e);
    
    //Find the highest score
        high=findHi(a,b,c,d,e);
    
    //Calculate the average
    ave=(a+b+c+d+e-high-low)/3;
    
    //Display the final score
    cout << "The final score is: " << setprecision(1) << fixed << ave << endl;
    
}

/*
 * Inputs:
 *      a,b,c,d,e
 * Outputs:
 *      low
 */
float findLo(float a, float b, float c, float d, float e){
    float low=a;
    if(low>b){
        low=b;
    }
    if(low>c){
        low=c;
    }
    if(low>d){
        low=d;
    }
    if(low>e){
        low=e;
    }
    return low;
}

/*
 * Inputs:
 *      a,b,c,d,e
 * Outputs:
 *      high
 */
float findHi(float a, float b, float c, float d, float e){
    int high=a;
    if(high<b){
        high=b;
    }
    if(high<c){
        high=c;
    }
    if(high<d){
        high=d;
    }
    if(high<e){
        high=e;
    }
    return high;
}
/*
 * Inputs:
 *      numDays, rate, inMeds, inServ
 * Outputs:
 *      balance
 */
float hosptal(int d, float r, float m, float s){
    float c;
    c=d*r+m+s;
    return c;
}

/*
 * Inputs:
 *      outMed, outSrv
 * Outputs:
 *      balance
 */
float hosptal(float m, float s){
    float c;
    c=m+s;
    return c;
}

/*
 * Inputs:
 *      popBeg, brthRat, dethRat, yrs
 * Outputs:
 *      popFin
 */
int populat(int p, int bp, int dp){
    int n;
    n=p+bp+dp;
    return n;
}

/*
 * Inputs:
 *      numShar, buy, buyComm, sale, salComm
 * Outputs:
 *      profit
 */
float stocks(int ns, float pp, float pc, float sp, float sc){
    float p;
    p=((ns*sp)-sc)-((ns*pp)-pc);
    return p;
}

/*
 * Inputs:
 *      num
 * Outputs:
 *      none
 */
bool isPrime(int n){
    bool x=true;
    for(int i=n-1; i>1; i--){
        if(n%i==0){
            x=false;
            i=1;
        }
    }
    return x;
}