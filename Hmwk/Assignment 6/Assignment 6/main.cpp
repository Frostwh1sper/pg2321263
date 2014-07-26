/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 * Created on July 22, 2014, 12:50 PM
 * Purpose: Execute 10 problems from Gaddis 6thEd, Chapter 7
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void menu();            //Displays main menu
int slction();          //Returns menu selection
void callPrb(int);      //Calls programs using switch
void cntinue();         //Waits for input before continuing
void problem1();        //Gaddis 6thEd Chap7 Prob1 - Largest/Smallest Array Values
void problem2();        //Gaddis 6thEd Chap7 Prob4 - Monkey Business
void problem3();        //Gaddis 6thEd Chap7 Prob13 - Grade Book
void problem4();        //Gaddis 6thEd Chap7 Prob7 - Lowercase to Uppercase Converter
void problem5();        //Gaddis 6thEd Chap7 Prob10 - Payroll
void problem6();        //Gaddis 6thEd Chap7 Prob11 - Driver's License Exam
void problem7();        //Gaddis 6thEd Chap8 Prob1 - Charge Account Validation
void problem8();        //Gaddis 6thEd Chap8 Prob3 - Lottery Winners Binary
void problem9();        //Gaddis 6thEd Chap8 Prob8 - Search Benchmarks
void problem10();       //Gaddis 6thEd Chap7 Prob
int getNum();
string getName();
float getGrad();
float getAver(float [][4], int);
void shwGrad(float,string);
int getHour();
float getRate();
char getCh();
void score(char [],char [],int, int &);
int linSear(int [],int,int);
int binSear(int [],int,int);
int binSear(int [],int,int,int &);


//Begin execution
int main(int argc, char** argv) {
    
    //Seed the RNG
    srand(time(0));
    
    //Declare and initialize variables
    int choice;
    
    //Display Menu
    do{
        menu();

        //User selection
        choice=slction();

        //Problems
        callPrb(choice);
        
    }while(choice<11);
    
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
            "          *    Glenning, Patrick - Assignment 6 - 46023    *" << endl <<
            "          *                                                *" << endl <<
            "          *    1)  Largest/Smallest Array Values           *" << endl <<
            "          *    2)  Monkey Business                         *" << endl <<
            "          *    3)  Grade Book                              *" << endl <<
            "          *    4)  Lowercase to Uppercase Converter        *" << endl <<
            "          *    5)  Payroll                                 *" << endl <<
            "          *    6)  Driver's License Exam                   *" << endl <<
            "          *    7)  Charge Account Validation               *" << endl <<
            "          *    8)  Lottery Winners Binary                  *" << endl <<
            "          *    9)  Search Benchmarks                       *" << endl <<
            "          *    10)                                         *" << endl <<
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
        if(n<1 || n>11) cout << "             Please enter a valid input: ";
        if(n>0 && n<12){
            x=false;
            cout << string(50,'\n');
        }
    }while(x);
    return n;
}

/*
 * Input
 *      choice
 * Output
 *      none
 */
void callPrb(int x){
    switch(x){
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
            cout << "Exiting program..." << endl << endl;
            break;
        }
    }
}

void cntinue(){
    char x;
    cout << endl;
    cin.get(x);
}

/*
 * Gaddis 6thEd Chap7 Prob1 - Largest/Smallest Array Values
 * Purpose: Displays the largest and smallest values in an array
 */
void problem1(){
    
    //Declare and initialize variables
    int num[10];
    int high, low;
    
    //User inputs
    for(int i=0; i<10; i++){
        num[i]=getNum();
    }
    
    //Find largest and smallest
    high=low=num[0];
    for(int i=1; i<10; i++){
        if(high<num[i]) high=num[i];
        if(low>num[i]) low=num[i];
    }
    
    //Display largest and smallest
    cout << "Highest: " << high << endl <<
            " Lowest: " << low << endl;
}

/*
 * Gaddis 6thEd Chap7 Prob4 - Monkey Business
 * Purpose: Record food intake of monkeys
 */
void problem2(){
    
    //Declare and initialize variables
    const int ROW=3, COL=7;
    int food[ROW][COL], sumTot, ave, lowX, lowY, highX, highY;
    
    //User inputs
    for(int i=0; i<3; i++){
        cout << "Enter how much food (in whole pounds) monkey " << i+1 << " consumed... " << endl;
        for(int n=0; n<7; n++){
            cout << "Day " << n+1 << ": ";
            do{
                cin >> food[i][n];
                cin.ignore();
                if(food[i][n]<0) cout << "Invalid weight entered, please re-enter: ";
            }while(food[i][n]<0);
        }
    }
    
    //Calculations
    sumTot=food[0][0];
    for(int i=0; i<3; i++){
        for(int n=0; n<7; n++){
            sumTot+=food[i][n];
        }
    }
    ave=sumTot/21;
    
    //Determine lowest and highest consumption
    lowX=0;
    lowY=0;
    highX=0;
    highY=0;
    for(int i=0; i<3; i++){
        for(int n=0; n<7; n++){
            if(food[lowY][lowX]>food[i][n]){
                lowX=n;
                lowY=i;
            }
            if(food[highY][highX]<food[i][n]){
                highX=n;
                highY=i;
            }
        }
    }
    
    //Display data
    cout << "Average daily consumption: " << ave << " pounds" << endl <<
            " Total weekly consumption: " << sumTot << " pounds." << endl <<
            " Most was consumed by monkey " << highY+1 << " on day " << highX+1 << 
            ": " << food[highY][highX] << " pounds." << endl <<
            "Least was consumed by monkey " << lowY+1 << " on day " << lowX+1 << 
            ": " << food[lowY][lowX] << " pounds." << endl;
}

/*
 * Gaddis 6thEd Chap7 Prob13 - Grade Book
 * Purpose: Store and display test scores for 5 students
 */
void problem3(){
    
    //Declare and Initialize Variables
    const int COL=4;
    const int STUD=5;
    string nam[STUD];
    float grade[STUD][COL];
    float ave[STUD];
    
    //User input
    for(int i=0; i<STUD; i++){
        cout << "Enter student " << i+1 << "'s name:" << endl;
        nam[i]=getName();
        for(int n=0; n<COL; n++){
            cout << "Enter " << nam[i] << "'s score for test " << n+1 << ": ";
            grade[i][n]=getGrad();
        }
    }
    cin.ignore();
    
    //Calculations
    for(int i=0; i<STUD; i++){
        ave[i]=getAver(grade,i);
    }
    
    //Display results
    for(int i=0; i<STUD; i++){
        shwGrad(ave[i], nam[i]);
    }
    
    
}

/*
 * Gaddis 6thEd Chap7 Prob7 - Lowercase to Uppercase Converter
 * Purpose: Converts any lowercase letters in a string to uppercase
 */
void problem4(){
    
    //Declare and initialize variables
    const int SIZE=25;
    string word;
    int length;
    char upper[SIZE];
    
    //User input
    do{
    cout << "Enter any string of characters, up to 25 characters in length: " << endl;
    cin >> word;
    length=word.size();
    cin.ignore();
    }while(length>25);
    
    //Convert string to char array
    for(int i=0; i<length; i++){
        upper[i]=word[i];
    }
    
    //Capitalize any lowercase letters
    for(int i=0; i<length; i++){
        if(upper[i]>=97 && upper[i]<=122){
            upper[i]-=32;
        }
    }
    
    //Display all uppercase string of characters
    for(int i=0; i<length; i++){
        cout << upper[i];
    }
    cout << endl << endl;
}

/*
 * Gaddis 6thEd Chap7 Prob10 - Payroll
 * Purpose: Calculates gross wages for employees
 */
void problem5(){
    
    //Declare and initialize variables
    const int SIZE=7;
    int eID[SIZE]={5658845,4520125,7895122,8777541,8451277,1302850,7580489};
    int hours[SIZE];
    float payRate[SIZE];
    float wages[SIZE];
    
    //User inputs
    for(int i=0; i<SIZE; i++){
        cout << "Enter pay information for employee " << eID[i] << endl;
        hours[i]=getHour();
        payRate[i]=getRate();
        cin.ignore();
        cout << endl;
    }
    
    //Calculate gross wages for all employees
    for(int i=0; i<SIZE; i++){
        wages[i]=payRate[i]*hours[i];
    }
    
    //Display gross wages
    cout << "Employee | Gross Wages" << endl;
    for(int i=0; i<SIZE; i++){
        cout << setprecision(2) << fixed;
        cout << eID[i] << ":    $" << setw(7) << wages[i] << endl;
    }
}

/*
 * Gaddis 6thEd Chap7 Prob11 - Driver's License Exam
 * Purpose: Grades a Driver's License Exam
 */
void problem6(){
    
    //Declare and initialize variables
    const int SIZE=20;
    char ansKey[SIZE]={'B','D','A','A','C','A','B','A','C','D','B','C','D','A','D','C','C','B','D','A'};
    char answer[SIZE];
    int correct=0;
    
    //User input
    cout << "Enter the student's answer for" << endl;
    for(int i=0; i<SIZE; i++){
        cout << "Question " << i+1 << ": ";
        cin >> answer[i];
    }
    cin.ignore();
    
    //Compare answers with test key
        score(ansKey,answer,SIZE,correct);
    
    //Display whether passed or failed
    cout << endl;
    if(correct<15){
        cout << "Student failed the exam." << endl;
    }
    else cout << "Student passed the exam." << endl;
}

/*
 * Gaddis 6thEd Chap8 Prob1 - Charge Account Validation
 * Purpose: Determine whether an entered account number is valid
 */
void problem7(){
    
    //Declare and initialize variables
    const int SIZE=18;
    int account[SIZE]={5658845,8080152,1005231,4520125,4562555,6545231,7895122,5552012,3852085,8777541,5050552,7576651,8451277,7825877,7881200,1302850,1250255,4581002};
    int entry;
    int valid;
    
    //User input
    cout << "Enter your 7-digit account number: ";
    cin >> entry;
    cin.ignore();
    
    //Execute linear search to validate entered account number
    valid=linSear(account,SIZE,entry);
    
    //Display whether entered number is valid
    if(valid==(-1)) cout << "Invalid account number." << endl;
    else cout << "Valid account number entered." << endl;
}

/*
 * Gaddis 6thEd Chap8 Prob3 - Lottery Winners binary search
 * Purpose: Execute a binary search to determine whether a winner
 */
void problem8(){
    
    //Declare and initialize variables
    const int SIZE=10;
    int lottery[SIZE]={13579,26791,26792,33445,55555,62483,77777,79422,85647,93121};
    int winner;
    int match;
    
    //User input
    cout << "What was this week's winning 5-digit lottery combination? ";
    cin >> winner;
    cin.ignore();
    
    //Execute binary search for match
    match=binSear(lottery,SIZE,winner);
    
    //Display whether lottery ticket matches
    if(match==(-1)) cout << "None of your lottery tickets match." << endl;
    else cout << "You have a winner!!" << endl;
    cout << endl;
}

/*
 * Gaddis 6thEd Chap8 Prob8 - Search Benchmarks
 * Purpose: Benchmarks two different sorting algorithms
 */
void problem9(){
    
    //Seed the RNG
    //Declare and initialize variables
    const int SIZE=20;
    int one[SIZE]={1254,24,157,169,1485,126,32,1457,1496,254,857,9648,3547,1682,2596,4562,4568,3578,1598,1475};
    int two[SIZE]={12,35,125,264,321,405,489,578,598,604,672,756,792,831,844,888,892,921,1025,1476};
    int first=one[rand()%SIZE];
    int second=two[rand()%SIZE];
    int count1=0, count2=0;
    
    //Search for the randomly selected value
    count1=linSear(one,SIZE,first)+1;
    count2=binSear(two,SIZE,second,count2)+1;
    
    //Display the search counter value
    cout << "Linear search took " << count1 << " cycles." << endl <<
            "Binary search took " << count2 << " cycles." << endl << endl;
}

/*
 * Gaddis 6thEd Chap7 Prob
 * Purpose: 
 */
void problem10(){
    
}

/*
 * 
 * 
 */
int getNum(){
    int x;
    cout << "Enter a number: ";
    cin >> x;
    return x;
}

/*
 * Function that receives and returns an input name
 * Input:
 *      none
 * Output:
 *      name
 */
string getName(){
    string x;
    cin >> x;
    return x;
}

/*
 * Function that receives and returns an input grade
 * Input:
 *      none
 * Output:
 *      grade
 */
float getGrad(){
    float x;
    do{
        cin >> x;
        if(x<0 || x>100) cout << "Invalid grade input, please re-enter: ";
    }while(x<0 || x>100);
    return x;
}

/*
 * Function that gets the average of 4 test scores
 * Input:
 *      grade, i
 * Output: 
 *      ave
 */
float getAver(float g[][4], int x){
    float sum=0;
    float ave;
    for(int i=0; i<4; i++){
        sum+=g[x][i];
    }
    ave=sum/4;
    return ave;
}

/*
 * Function that displays the average grades of three students
 * Input:
 *      ave, name
 * Output:
 *      none
 */
void shwGrad(float x, string y){
    cout << y << ": ";
    if(x<60.0f){
        cout << "F" << endl;
    }
    if(x>=60.0f && x<70.0f){
        cout << "D" << endl;
    }
    if(x>=70.0f && x<80.0f){
        cout << "C" << endl;
    }
    if(x>=80.0f && x<90.0f){
        cout << "B" << endl;
    }
    if(x>=90.0f && x<=100.0f){
        cout << "A" << endl;
    }
}

/*
 * 
 * 
 */
int getHour(){
    int h;
    cout << "Enter hours worked: ";
    cin >> h;
    return h;
}

/*
 * 
 * 
 */
float getRate(){
    float r;
    cout << "Enter hourly pay rate: ";
    cin >> r;
    return r;
}

/*
 * 
 * 
 */
void score(char x[], char y[], int z, int &s){
    for(int i=0; i<z; i++){
        if(x==y || x==(y-32)) s++;
    }
}

/*
 * 
 * 
 */
int linSear(int x[], int s, int y){
    int i=0;
    int pos=(-1);
    bool found=false;
    while(i<s && !found){
        if(x[i]==y){
            found=true;
            pos=i;
        }
        i++;
    }
    return pos;
}

/*
 * Function which executes a binary search for a match
 * Input:
 *      lottery, SIZE, winner
 * Output:
 *      match
 */
int binSear( int array[], int s, int x){
    int first=0, last=(s-1), mid, pos=(-1);
    bool found=false;
    while(!found && first<=last){
        mid=(first+last)/2;
        if(array[mid]==x){
            found=true;
            pos=mid;
        }
        else if(array[mid]>x){
            last=mid-1;
        }
        else{
            first=mid+1;
        }
    }
    return pos;
}

/*
 * Function which executes a binary search for a match
 * Input:
 *      lottery, SIZE, winner
 * Output:
 *      match
 */
int binSear( int array[], int s, int x, int &c){
    int first=0, last=(s-1), mid;
    bool found=false;
    while(!found && first<=last){
        mid=(first+last)/2;
        if(array[mid]==x){
            found=true;
        }
        else if(array[mid]>x){
            last=mid-1;
        }
        else{
            first=mid+1;
        }
        c++;    //Increments counter for search
    }
    return c;
}