#include <iostream>
#include "charmander.h"

using namespace std;

Charmander::Charmander(): Pokemon() {
    type.push_back("Fire");
    skills.push_back("Growl");
    skills.push_back("Scratch");
    cout << "Default Constructor (Charmander)\n";
}

/**
 * 
 */
Charmander::Charmander(string name, int hp, int att, int def, vector<string> t, vector<string> s)
: Pokemon(name, hp, att, def, t) {  
    skills = s; 
    cout << "Overloaded Constructor (Charmander)\n";  // Removed unnecessary endl here
}

void Charmander::speak() {
    cout << "Charmander says: Roar!" << endl;
}

void Charmander::printStats() {
    Pokemon::printStats();  
    cout << "Skills: ";
    for (int i = 0; i < skills.size(); i++) {
        cout << skills[i];
        if (i < skills.size() - 1) cout << ", ";  // Adds comma separation between skills
    }
    cout << "\n";  // Clean up with a single newline at the end
}
