#ifndef CHARMANDER_H
#define CHARMANDER_H

#include <string>
#include <vector>
#include "pokemon.h"

using namespace std;

class Charmander : public Pokemon {
public:
    // Constructors
    Charmander();
    Charmander(string name, int hp, int att, int def, vector<string> t, vector<string> s);

    // Mutator Functions
    virtual void speak() override;
    void printStats() override; // Corrected spelling and added override keyword

private:
    vector<string> skills;
};

#endif


