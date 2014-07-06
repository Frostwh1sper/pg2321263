/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 5, 2014, 11:44 AM
 * Purpose: Assignment #3, with menu
 */

//System Libraries
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string.h>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Begin execution
int main(int argc, char** argv) {

    //Menu
    bool loop=true;
    do{
        //Menu Options
        cout << "Homework Assignment #3 Menu:" << endl;
        cout << "Type 1 for the Minimum/Maximum problem." << endl;
        cout << "Type 2 for the Roman Numeral Converter." << endl;
        cout << "Type 3 to calculate your Body Mass Index (BMI)." << endl;
        cout << "Type 4 for the Time Calculator." << endl;
        cout << "Type 5 to Sort Names." << endl;
        cout << "Type 6 for the Math Tutor." << endl;
        cout << "Type 7 for The Speed of Sound problem." << endl;
        cout << "Type 8 for the Freezing and Boiling Points problem." << endl;
        cout << "Type 9 to calculate the cost of Long Distance Calls." << endl;
        cout << "Type 10 to calculate the bill from an Internet Service Provider." << endl;
        cout << "Type anything else to quit the program." << endl;
        
        //User choice
        int choice;
        cin >> choice;
        cin.ignore();
        cout << string(50, '\n');
        
        switch(choice){
            case 1:{    //Gaddis 6thEd Chap4, Problem 1, Minimum/Maximum
                
                //Declare and initialize variables
                int a,b;
                
                //Request user input
                cout << "You will be entering two numbers, and the program will order them." << endl;
                cout << "Enter the first number: ";
                cin >> a;
                cout << "Enter the second number: ";
                cin >> b;
                
                //Output result
                if (a<b){
                    cout << a << " is smaller than " << b << "." << endl << endl;
                }
                if (b<a){
                    cout << b << " is smaller than " << a << "." << endl << endl;
                }
                else {
                    cout << "You entered the same number twice." << endl << endl;
                }
                
                //Return user to the menu
                cout << "Press any key and enter to return to the menu: ";
                char temp;
                cin >> temp;
                cout << string(50, '\n');
                break;
            }
        
            case 2:{    //Gaddis 6thEd Chap4, Problem 2, Roman Numeral Converter
                
                //Declare and initialize variables
                int num;
                
                //Request User input
                cout << "Enter any number from 1 to 10, and it will be converted to Roman numerals: ";
                cin >> num;
                
                //Output result
                switch(num){
                    case 1:{
                        cout << "1 is I in Roman numerals." << endl;
                        break;
                    }
                    case 2:{
                        cout << "2 is II in Roman numerals." << endl;
                        break;
                    }
                    case 3:{
                        cout << "3 is III in Roman numerals." << endl;
                        break;
                    }
                    case 4:{
                        cout << "4 is IV in Roman numerals." << endl;
                        break;
                    }
                    case 5:{
                        cout << "5 is V in Roman numerals." << endl;
                        break;
                    }
                    case 6:{
                        cout << "6 is VI in Roman numerals." << endl;
                        break;
                    }
                    case 7:{
                        cout << "7 is VII in Roman numerals." << endl;
                        break;
                    }
                    case 8:{
                        cout << "8 is VIII in Roman numerals." << endl;
                        break;
                    }
                    case 9:{
                        cout << "9 is IX in Roman numerals." << endl;
                        break;
                    }
                    case 10:{
                        cout << "10 is X in Roman numerals." << endl;
                        break;
                    }
                    default:{
                        cout << "You didn't enter a number between 1 and 10." << endl;
                        break;
                    }
                }
                
                //Return user to the menu
                cout << "Press any key and enter to return to the menu: ";
                char temp;
                cin >> temp;
                cout << string(50, '\n');
                break;
            }
        
            case 3:{    //Gaddis 6thEd Chap4, Problem 5, Body Mass Index
                
                //Declare and initialize variables
                int weight, height, wMax, wMin; //Weight, Height, Max Weight, Min Weight
                float bmi;                      //Body Mass Index
                
                //Request user input
                cout << "This will calculate your BMI" << endl;
                cout << "What is your height, in inches? ";
                cin >> height;
                cout << "What is your weight, in pounds? ";
                cin >> weight;
                
                //Calculations
                bmi=weight*703/pow(height,2);
                wMax=25.0f*pow(height,2)/703;
                wMin=18.5f*pow(height,2)/703;
                
                //Output result
                cout << setprecision(1) << fixed;
                cout << "Your BMI is " << bmi << "." << endl;
                if (bmi>18.5f && bmi<25.0f){
                    cout << "This indicates that you are at optimal weight." << endl;
                }
                if (bmi>=25.0f){
                    cout << "This indicates that you are overweight." << endl;
                    cout << "To achieve optimal weight, you need be at most " << wMax << " lbs." << endl;
                }
                if (bmi<=18.5f){
                    cout << "This indicates that you are underweight." << endl;
                    cout << "To achieve optimal weight, you need to be at least " << wMin << " lbs." << endl;
                }
                
                //Return user to the menu
                cout << "Press any key and enter to return to the menu: ";
                char temp;
                cin >> temp;
                cout << string(50, '\n');
                break;
            }
        
            case 4:{    //Gaddis 6thEd Chap4, Problem 7, Time Calculator
                
                //Declare and initialize variables
                int hour, min, sec, secRem;
                
                //Request user input
                cout << "This program converts seconds into hours, minutes, and seconds." << endl;
                cout << "Enter any number of seconds: ";
                cin >> sec;
                
                //Calculations
                hour = sec/3600;
                min = (sec-(hour*3600))/60;
                secRem = (sec-hour*3600-min*60);
                
                //Output results
                cout << sec << " seconds is " << hour << " hours, " << min << " minutes, " << secRem 
                        << " seconds." << endl;
                
                //Return user to the menu
                cout << "Press any key and enter to return to the menu: ";
                char temp;
                cin >> temp;
                cout << string(50, '\n');
                break;
            }
        
            case 5:{    //Gaddis 6thEd Chap4, Problem 8, Sorted Names
                
                //Declare and initialize variables
                int SIZE=20;
                char name1[SIZE], name2[SIZE], name3[SIZE]; //Three names
    
                //Request name input
                cout << "This program sorts three entered names alphabetically" << endl;
                cout << "Enter three different names, in any order:" << endl;
                cout << "Name 1: " << endl;
                cin.getline(name1,SIZE);
                cout << "Name 2: " << endl;
                cin.getline(name2,SIZE);
                cout << "Name 3: " << endl;
                cin.getline(name3,SIZE);
    
                //Compare strings
                cout << endl;
                cout << "These are the names, listed alphabetically:" << endl;
                if (strcmp(name1,name2)<0){
                    if (strcmp(name2,name3)<0){
                        cout << name1 << endl << name2 << endl << name3 << endl;
                    }
                    if (strcmp(name3,name1)<0){
                        cout << name3 << endl << name1 << endl << name2 << endl;
                    }
                    if ((strcmp(name1,name3)<0) && (strcmp(name3,name2)<0)){
                        cout << name1 << endl << name3 << endl << name2 << endl;
                    }
                }
                if (strcmp(name2,name1)<0){
                    if (strcmp(name1,name3)<0){
                        cout << name2 << endl << name1 << endl << name3 << endl;
                    }
                    if (strcmp(name3,name2)<0){
                        cout << name3 << endl << name2 << endl << name1 << endl;
                    }
                    if ((strcmp(name2,name3))<0 && (strcmp(name3,name1)<0)){
                        cout << name2 << endl << name3 << endl << name1 << endl;
                    }
                }
                
                //Return user to the menu
                cout << "Press any key and enter to return to the menu: ";
                char temp;
                cin >> temp;
                cout << string(50, '\n');
                break;
            }
        
            case 6:{    //Gaddis 6thEd Chap4, Problem 9, Math Tutor
                
                //Get system time & seed RNG
                unsigned seed=time(0);
                srand(seed);
                
                //Declare and initialize variables
                int top=rand()%1000;
                int bot=rand()%1000;
                int guess, sum;
                
                //Display the math equation
                cout << setw(2) << " " << setw(4) << top << endl;
                cout << setw(2) << "+" << setw(4) << bot << endl;
                cout << "Enter your guess:" << endl;
                cin >> guess;
                
                //Calculations
                sum=top+bot;
                
                //Output result
                if(guess==sum)
                    cout << "Great job! The sum is " << sum << "!" << endl;
                else
                    cout << "Good try, but the answer is " << sum << "." << endl;
                
                
                //Return user to the menu
                cout << "Press any key and enter to return to the menu: ";
                char temp;
                cin >> temp;
                cout << string(50, '\n');
                break;
            }
        
            case 7:{    //Gaddis 6thEd Chap4, Problem 18, The Speed of Sound
                
                //Declare and initialize variables
                unsigned short airSpd=1100, watSpd=4900, stlSpd=16400;  //Speed of sound in Air, Water & Steel
                short medium;                                           //User's choice of mediums
                float dist;
                float time;
                bool loop=true;
                
                //Request user input
                cout << "This program will calculate how long it takes sound to travel in a certain medium." << endl;
                do{
                cout << "Choose 1 for Air" << endl;
                cout << "Choose 2 for Water" << endl;
                cout << "Choose 3 for Steel" << endl;
                cin >> medium;
                cout << "What distance, in feet, will the sound wave travel through the medium? ";
                cin >> dist;
                
                switch(medium){
                    case 1:{
                        time=dist/airSpd;
                        cout << "In air, sound would travel " << dist << " feet in ";
                        cout << setprecision(4) << time << " seconds." << endl;
                        loop=false;
                        break;
                    }
                    case 2:{
                        time=dist/watSpd;
                        cout << "In water, sound would travel " << dist << " feet in ";
                        cout << setprecision(4) << time << " seconds." << endl;
                        loop=false;
                        break;
                    }
                    case 3:{
                        time=dist/stlSpd;
                        cout << "In steel, sound would travel " << dist << " feet in ";
                        cout << setprecision(4) << time << " seconds." << endl;
                        loop=false;
                        break;
                    }
                    default:{
                        cout << "You made an incorrect selection from the mediums, please try again." << endl << endl;
                        break;
                    }
                }
                
                }while(loop);
                
                //Return user to the menu
                cout << "Press any key and enter to return to the menu: ";
                char temp;
                cin >> temp;
                cout << string(50, '\n');
                break;
            }
        
            case 8:{    //Gaddis 6thEd Chap4, Problem 20, Freezing and Boiling Points
                
                //Return user to the menu
                cout << "Press any key and enter to return to the menu: ";
                char temp;
                cin >> temp;
                cout << string(50, '\n');
                break;
            }
        
            case 9:{    //Gaddis 6thEd Chap4, Problem 22, Long Distance Calls
                
                //Return user to the menu
                cout << "Press any key and enter to return to the menu: ";
                char temp;
                cin >> temp;
                cout << string(50, '\n');
                break;
            }
        
            case 10:{   //Gaddis 6thEd Chap4, Problem 23, Internet Service Provider
                
                //Return user to the menu
                cout << "Press any key and enter to return to the menu: ";
                char temp;
                cin >> temp;
                cout << string(50, '\n');
                break;
            }
            default:{   //Program exit
            cout << "Ending program." << endl;
            loop=false;
            break;
            }
        }
        
    }while(loop);   //End of menu do/while
    
    //Finish him!!
    return 0;
}

