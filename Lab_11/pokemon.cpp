#include <iostream>
#include <cstdlib>
#include "pokemon.h"


using namespace std;

/**
 * contruct a new pokemon object
 * 
 */

Pokemon::Pokemon(){
    name = "Unidentified";
    hp = 0; 
    attack = 0;
    defense = 0; 
    cout<< "Default Constructor (Pokemon)\n" << endl; 


}


Pokemon::Pokemon(string name, int hp, int att, int def, vector<string> type){
    this ->name = name;
    this ->hp = hp;
    this ->attack = att; 
    this ->defense = def;
    this ->type = type; 
    cout << "Overloaded Consctuctor(pokemon)\n" << endl;
}

void Pokemon::speak() {
    cout << "RAHHHHH!\n" << endl;
    cout << "MEEE SPEAK\n" << endl;
    // I don't know pokemon that well otherwise I would've added some lore accurate diologue my bad
}



void Pokemon::printStats(){
    cout << "Name: " << name << "\tHP: " << hp << "\tDEF: " << defense << "\tATT: " << attack << endl;    cout << "Type: " << endl; 
    for (int i=0; i< type.size(); i++){
        cout << type[i] << "\t" << endl;
    }

    cout << endl;

}
