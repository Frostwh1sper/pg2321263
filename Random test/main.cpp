/* 
 * File:   main.cpp
 * Author: Patrick Glenning
 *
 * Created on June 26, 2014, 12:44 AM
 */

#include <iostream>
#include <cstdlib>  //For rand()
#include <ctime>

using namespace std;

//Begin execution
int main(int argc, char** argv) {

    
    //Declare and initialize variables
    short u, v, w, x, y, z, ac, atBonus, hit;
    int critNrm, critSnk, dmg, dmgSnk;
    char snk;
    
    //Get the system time
    unsigned seed = time(0);
    
    //Seed the RNG
    srand(seed);
    
    //Calculations
    v = rand() % 20;
    w = v + 6;
    x = rand() % 20;
    y = rand() % 4;
    z = rand() % 4;
    u = rand() % 6;
        
    //Inputs
    cout << "What is the AC of the creature you are attacking? ";
    cin >> ac;
    cin.ignore();
    
    cout << "What is your attack bonus? ";
    cin >> atBonus;
    cin.ignore();
    
    cout << "Is this a sneak attack? (y/n) " ;
    cin>>snk;
    cin.ignore();
    
    //Fix zeroes for % calculations
    hit = ac - atBonus;
    if (v == 0) {
        v = 20;
    }
    if (x == 0) {
        x = 20;
    }
    if (y == 0) {
        y = 4;
    }
    if (z == 0) {
        z = 4;
    }
    if (u ==0) {
        u = 6;
    }
    
//Calculate damages
    critNrm = y + z;
    critSnk = y + z + u;
    dmg = y;
    dmgSnk = y + u;
    
//Successful hit
    if (v >= hit) {
    //Critical
        if (v >= 19) {
            if (x >= hit) {

        //Sneak attack
                if (snk = 'y') {
                    cout << "You deal " << critSnk << " critical damage!" << endl;
                }
        //Normal attack
                else {
                    cout << "You deal " << critNrm << " critical damage!" << endl;
                }
        }
        }
    //Non-critical
        if (v < 19) {
        //Sneak attack
            if (snk = 'y') {
                cout << "You deal " << dmgSnk << " damage!" << endl;
            }
        //Normal attack
            else {
                cout << "You deal " << dmg << " damage!" << endl;
            }
        }
    }        
//Missed attack
    else {
        cout << "You missed." << endl;
    }
    
    //Finish him!!
    return 0;
}

