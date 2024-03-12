
#ifndef RPG_H
#define RPG_H

#include <iostream> 
#include <string>
#include <array> 




using namespace std;


const int SKILL_SIZE = 2;


class RPG{
private:
    

    string name; 
    int health; 
    int defense;
    string type; 
    // array<string, SKILL_SIZE> skills;
    int strength; 
    


public:

    array<string, SKILL_SIZE> skills;

    //constructors
    RPG();
    RPG(string name, int health ,int defense, string type, int strength);

    std::array<std::string, SKILL_SIZE> getSkills() const;
    void setSkills();
    void updateHealth(int);
    void printAction(string, RPG);
    void attack(RPG*);
    void useSkill(int skillIndex, RPG* target);
    bool isAlive() const;
    string getName() const;
    int getHealth() const;
    int getStrength() const;
    int getDefense() const;
};

#endif // RPG_H
