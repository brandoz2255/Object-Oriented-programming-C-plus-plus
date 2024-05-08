#ifndef POKEMON_H
#define POKEMON_H 

class Pokemon{
    public:
    // constructors 
    Pokemon();
    Pokemon(string name, int hpm int att, int def, vector<string> type);

    virtual void speak();
    virtual void printStats();

    protected:

    string name;
    int hp;
    int attack;
    int defense;
    vector<string> type;
};

#endif