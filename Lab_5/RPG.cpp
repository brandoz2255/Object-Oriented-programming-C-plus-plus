
#include "RPG.h"
#include <iostream>
#include <algorithm> // for max function

// Constructor definitions
RPG::RPG() : name("NPC_1"), health(100), strength(10), defense(10), type("Warrior"){
    //Starts the Skills Array 
    skills[0] = "slash";
    skills[1] = "parry"; 
}

RPG::RPG(string name, int health, int defense, string type, int strength)
    : name(name), health(health), strength(strength), defense(defense), type(type) {}

// Member function definitions
std::array<std::string, SKILL_SIZE> RPG::getSkills() const {
    return skills;
}

void RPG::setSkills() {
    if (type == "mage") {
        skills[0] = "fire";
        skills[1] = "thunder";
    } else if (type == "thief") {
        skills[0] = "pilfer";
        skills[1] = "jab";
    } else if (type == "archer") {
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    } else {
        skills[0] = "splash";
        skills[1] = "parry";
    }
}

void RPG::updateHealth(int newHealth) {
    health = newHealth;
}

void RPG::printAction(string skill, RPG opponent) {
    cout << name << " used " << skill << " on " << opponent.getName() << endl;
}

void RPG::attack(RPG* target) {
    int damage = strength - target->getDefense();
    damage = std::max(damage, 1);
    target->updateHealth(target->getHealth() - damage);
    cout << name << " attacked " << target->getName() << " for " << damage << " damage!" << endl;
}

bool RPG::isAlive() const {
    return health > 0;
}

string RPG::getName() const {
    return name;
}

int RPG::getHealth() const {
    return health;
}

int RPG::getStrength() const {
    return strength;
}

int RPG::getDefense() const {
    return defense;
}
