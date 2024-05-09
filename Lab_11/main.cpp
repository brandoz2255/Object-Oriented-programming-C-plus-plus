#include <iostream>
#include "charmander.h"
#include "pokemon.cpp"
#include "charmander.cpp"

using namespace std;

int main(){

    vector<string> pokemonType;
    pokemonType.push_back("Fire");

    vector<string> skills;
    skills.push_back("Growl");
    skills.push_back("Scratch");

    cout << "--------------------CONSTRUCTOR CREATED---------------\n" << endl;
    Charmander charlie = Charmander("Charlie", 100, 4, 4, pokemonType, skills);

    cout << "-------------DIRECT SPEAK-----------------" << endl;
    charlie.speak();

    Pokemon *p1 = &charlie;
    cout << "--------speak called from pokemon pointer-----------\n";
    p1->speak();  // Using -> is more conventional for pointers

    Charmander *c1 = &charlie;
    cout << "\n-------------speak called from Charmander Pointer-----------------\n";
    c1->speak();  // Again, using -> for consistency and readability

    cout << "\n-----------------Print Stats---------------------------\n";
    charlie.printStats();
}
