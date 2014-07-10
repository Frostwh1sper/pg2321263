/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 8, 2014, 1:04 PM
 * Purpose: To execute 10 programs from Gaddis 6th Edition, Chapter 5
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin execution
int main(int argc, char** argv) {

//Assignment 4 Menu
    
    //Declare variables
    int choice;
    bool loop=true;
    do{
    //Menu Display
    cout << "            _________________________________________________ " << endl;
    cout << "           *                                                 *" << endl;
    cout << "           *    Glenning, Patrick - Assignment #4 - 46023    *" << endl;
    cout << "           *                                                 *" << endl;
    cout << "           *     1) Sum of Numbers                           *" << endl;
    cout << "           *     2) Calories Burned                          *" << endl;
    cout << "           *     3) Distance Traveled                        *" << endl;
    cout << "           *     4) Math Tutor                               *" << endl;
    cout << "           *     5) Population                               *" << endl;
    cout << "           *     6) The Greatest and Least of These          *" << endl;
    cout << "           *     7) Savings Account Balance                  *" << endl;
    cout << "           *     8) Sales Bar Chart                          *" << endl;
    cout << "           *     9) Budget Analysis                          *" << endl;
    cout << "           *    10) Random Number Guessing Game              *" << endl;
    cout << "           *    Enter any other key to exit this program     *" << endl;
    cout << "           *_________________________________________________*" << endl;
    cout << "           Please choose a program: ";
    cin >> choice;
    cin.ignore();
    cout << string(50,'\n');
    
    //Begin switch for choice
    switch(choice){
        case 1:{        //Problem 1, Sum of Numbers
            
            //Declare and initialize variables
            unsigned short num, sum=0, counter=1;
            
            //User input
            cout << "This program will sum all integers leading up to a number you choose." << endl;
            cout << "Please choose any positive integer: ";
            cin >> num;
            
            //Calculations
            while(counter<=num){
                sum+=counter;
                counter++;
            }
            
            //Output
            cout << "The sum of all numbers leading up to " << num << " is " << sum << "." << endl;
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        
        case 2:{        //Problem 4, Calories Burned
            
            //Declare and initialize variables
            float calPer=3.9, calTot;
            int min=30;
            int counter=10;
            
            //Output
            cout << "This is how many calories are burned on a treadmill over time" << endl;
            while(counter<=min){
                calTot=counter*calPer;
                cout << counter << " minutes: " << setw(4) << calTot << " calories" << endl;
                counter+=5;
            }
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        
        case 3:{        //Problem 6, Distance Traveled
            
            //Declare and initialize variables
            int mph;
            int hours;
            int distance;
            bool loop=true;
            
            //Program description
            cout << "This program calculates the distance a vehicle has traveled over time." << endl;
            
            //User input
            do{
                cout << "Enter the speed of the vehicle, in miles per hour: ";
                cin >> mph;
                cin.ignore();
                cout << "Enter the length of time the vehicle will travel: ";
                cin >> hours;
                cin.ignore();
                if(mph<=0 || hours<=0){
                    cout << endl;
                    cout << "Please enter positive numbers greater than zero." << endl << endl;
                }
                else{
                    loop=false;
                }
            }while(loop);
            
            //Calculation and outputs
            for(int i=1; i<=hours; i++){
                distance=mph*i;
                cout << "Hour " << i <<": " << distance << " Miles" << endl;
            }
            cout << endl;
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        
        case 4:{        //Problem 8, Math Tutor
            
            //Seed the RNG
            unsigned seed=time(0);
            srand(seed);
            
            //Declare and initialize variables
            char funct;
            float num1, num2;
            float solve;
            char cont;
            bool repeat=true;
            
            do{
                //Select mathematical function
                cout << "  Choose which mathematical function you would like to solve:" << endl;
                cout << "  1) Addition" << endl;
                cout << "  2) Subtraction" << endl;
                cout << "  3) Multiplication" << endl;
                cout << "  4) Division" << endl;
                cout << "  Enter any other key to exit" << endl;
                cin >> funct;
                cin.ignore();

                switch(funct){
                    case '1':{
                        num1=rand()%999+1;
                        num2=rand()%999+1;
                        solve=num1+num2;
                        cout << setw(5) << num1 << endl;
                        cout << "+" << setw(4) << num2 << endl << endl;
                        cout << "Enter any key to reveal the answer: ";
                        cin >> cont;
                        cin.ignore();
                        cout << num1 << " + " << num2 << " = " << solve << endl << endl;
                        break;
                    }
                    case '2':{
                        num1=rand()%999+1;
                        num2=rand()%999+1;
                        solve=num1-num2;
                        cout << setw(5) << num1 << endl;
                        cout << "-" << setw(4) << num2 << endl << endl;
                        cout << "Enter any key to reveal the answer: ";
                        cin >> cont;
                        cin.ignore();
                        cout << num1 << " - " << num2 << " = " << solve << endl << endl;
                        break;
                    }
                    case '3':{
                        num1=rand()%99+1;
                        num2=rand()%99+1;
                        solve=num1*num2;
                        cout << setw(5) << num1 << endl;
                        cout << "x" << setw(4) << num2 << endl << endl;
                        cout << "Enter any key to reveal the answer: ";
                        cin >> cont;
                        cin.ignore();
                        cout << num1 << " x " << num2 << " = " << solve << endl << endl;
                        break;
                    }
                    case '4':{
                        num1=rand()%9999+1;
                        num2=rand()%99+1;
                        solve=num1/num2;
                        cout << "       ____" << endl;
                        cout << setw(5) << num2 << " |" << setw(4) << num1 << endl << endl;
                        cout << "Enter any key to reveal the answer: ";
                        cin >> cont;
                        cin.ignore();
                        cout << "       ____" << endl;
                        cout << setw(5) << num2 << " |" << setw(4) << num1 << " = " << solve << endl << endl;
                        break;
                        
                    }
                    default:{
                        repeat=false;
                        break;
                    }
                }
            }while(repeat);
            
            cout << string(50,'\n');
            break;
        }
        
        case 5:{        //Problem 11, Population
            
            //Declare and initialize variables
            int pop, days;      //Number of original organisms, and days to multiply
            float rate, origin; //Population growth rate, origin population
            bool start=true;    //Input validation loop operator
            
            //User input
            cout << "This program will calculate how many organisms will be in a population after x amount of days:" << endl;
            do{
                cout << "How many organisms did you start with? ";
                cin >> origin;
                if(origin>1){
                    start=false;
                }
                else{
                    cout << "You must start with at least two organisms." << endl;
                }
            }while(start);
            start=true;
            do{
                cout << "What is their daily population increase percentage? ";
                cin >> rate;
                if(rate>0){
                    start=false;
                }
                else{
                    cout << "You must have a growth rate greater than zero." << endl;
                }
            }while(start);
            rate/=100;  //Converts the percentage rate to a decimal
            start=true;
            do{
                cout << "How many days of growth will be projected? ";
                cin >> days;
                if(days>0){
                    start=false;
                }
                else{
                    cout << "You must let the organisms populate for at least a day." << endl;
                }
            }while(start);
            
            //Calculations and outputs
            pop=origin;
            for(int i=1; i<=days; i++){
                origin*=(1+rate);
                pop=origin;
                cout << "Day " << setw(4) << i << ": " << setw(10) << pop << " organisms" << endl;
            }
            cout << endl << endl;
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        
        case 6:{        //Problem 13, The Greatest and Least of These
            
            //Declare and initialize variables
            int num[99];        //Array of numbers to be entered by user
            int counter=0;      //Tallies the number of integers entered
            
            //User input
            cout << "This program will choose the largest and smallest numbers from a series." << endl << endl;
            cout << "Enter a series of integers, each followed by the enter key." << endl
                 << "Enter '-99' to stop entering numbers (-99 will not count toward your entries):" << endl;
            for(int i=1; i<=99; i++){
                cin >> num[i];
                if(num[i]==-99){
                    i=100;
                }
                else{
                    counter++;
                }
            }
            
            //Testing numbers for Greatest and Least
            for(int i=1; i<=counter; i++){
                //Test for lesser number
                for(int n=1; n<=counter; n++){
                    if(n==i){
                        //Prevents testing number against itself
                    }
                    else if(num[n]<num[i]){
                        n=counter+1;
                    }
                    if(n==counter){
                        cout << num[i] << " is the lesser number." << endl;
                    }
                    
                }
                //Test for greater number
                for(int m=1; m<=counter; m++){
                    if(m==i){
                        //Prevents testing number against itself
                    }
                    else if(num[m]>num[i]){
                        m=counter+1;
                    }
                    if(m==counter){
                        cout << num[i] << " is the greater number." << endl;
                    }
                    
                }
                
            }
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        
        case 7:{        //Problem 16, Savings Account Balance
            
            //Declare and initialize variables
            float rate;
            float balance;
            float deposit, withdrw;
            int months;
            
            //User inputs
            cout << "This program will calculate the balance in your savings account after a certain number of months." << endl;
            cout << "It will also request deposit and withdrawal amounts for each month leading up to that date." << endl << endl;
            cout << "What is the starting balance for the account? $";
            cin >> balance;
            cout << "What is the annual interest rate for the account? ";
            cin >> rate;
            rate/=1200;  //Converts percentage annual rate to monthly decimal rate
            cout << "How many months would you like to calculate? ";
            cin >> months;
            cout << endl;
            
            //Continues user input and calculations for each month
            cout << setprecision(2) << fixed;
            for(int i=1; i<=months; i++){
                //Display balance at the start of the month
                cout << "Month " << i << ": Starting balance of $" << balance << endl;
                //Enter deposits & calculate balance
                cout << "Enter total deposited this month: $";
                cin >> deposit;
                balance+=deposit;
                //Enter withdrawals & calculate balance
                cout << "Enter total withdrawals this month: $";
                cin >> withdrw;
                balance-=withdrw;
                //Displays if the account was closed during this month
                if(balance<=0){
                    cout << "The account has been closed due to insufficient funds." << endl;
                    i=months+1;
                }
                //Calculate and display interest earned this month, then add to balance
                else{
                    cout << "Interest earned at the end of this month: $" << balance*rate << endl << endl;
                    balance*=(1+rate);
                }
                //Outputs final balance
                if(i==months){
                    cout << "At the end of " << months << " months, you have a balance of: " << balance << endl << endl;
                }
                
            }
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        
        case 8:{        //Problem 17, Sales Bar Chart
            
            //Declare and initialize variables
            int store[5];
            
            //Display program purpose
            cout << "This program displays the sales of five (5) stores in a bar graph." << endl << endl;
            
            //User input
            for(int i=1; i<=5; i++){
                cout << "Enter today's sales for store " << i << ": $";
                cin >> store[i];
            }
            cout << endl;
            
            //Display graph
            cout << "Sales summary for each store:" << endl;
            for(int i=1; i<=5; i++){
                cout << "Store " << i << "| " << string(store[i]/100,'*') << endl;
            }
            cout << "       * = $100 in sales" << endl << endl;
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        
        case 9:{        //Problem 19, Budget Analysis
            
            //Declare and initialize variables
            float budget;
            float expense[20];
            
            //User input
            cout << "What is your monthly budget? $";
            cin >> budget;
            cout << endl << "Now, enter all your expenses for the month." << endl;
            cout << "Enter 9999 when you are finished entering expenses." << endl;
            for(int i=1; i<=20; i++){
                cout << "Expense " << i << ": $";
                cin >> expense[i];
                cin.ignore();
                if(expense[i]==9999){
                    i=21;
                }
                else{
                    budget-=expense[i];
                }
            }
            
            //Display whether expenses are over or under budget, and by how much
            cout << setprecision(2) << fixed;
            if(budget<0){
                cout << "You came in over budget. You need to cut $" << budget*(-1) << " in monthly expenses." << endl;
            }
            if(budget>0){
                cout << "You came in under budget. You will have $" << budget << " surplus each month." << endl;
            }
            if(budget==0){
                cout << "You came in exactly on budget." << endl;
            }
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        
        case 10:{       //Problem 21, Random Number Guessing Game
            
            //Initialize RNG
            unsigned seed=time(0);
            srand(seed);
            
            //Declare and initialize variables
            unsigned short guess;
            unsigned short num;
            
            //Generate random number
            num=rand()%1000+1;
            
            //User guess
            cout << "I have picked a number from 1 to 1000. Make your guess: ";
            do{
                cin >> guess;
                
                if(guess-num>=500 || num-guess>=500){
                    if(guess>num){
                        cout << "Too high. ";
                    }
                    if(guess<num){
                        cout << "Too low. ";
                    }
                    cout << "You're way off!! Guess again: " << endl;
                }
                else if(guess>num){
                        cout << "Too high. Guess again: ";
                    }
                else if(guess<num){
                        cout << "Too low. Guess again: ";
                    }
            }while(guess!=num);
            
            cout << num << " is correct!" << endl << endl;
            
            cout << "Enter any key to continue: ";
            char temp;
            cin >> temp;
            cout << string(50,'\n');
            break;
        }
        
        default:{
            cout << "Exiting program..." << endl;
            loop=false;
            break;
        }
    }
    }while(loop);
    //Finish him!!
    return 0;
}

