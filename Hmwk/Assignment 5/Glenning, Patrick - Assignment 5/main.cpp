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
 * Purpose: 
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
 * Purpose: 
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
 * Purpose: 
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
 * Purpose: 
 */
void problem7(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob15 - Population
 * Purpose: 
 */
void problem8(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob19 - Stock Profit
 * Purpose: 
 */
void problem9(){
    
}

/*
 * Gaddis 6thEd Chap6 Prob21 - isPrime Function
 * Purpose: 
 */
void problem10(){
    
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