
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


/* @breif attackl decreases the opponents health by strenght opponents defense in other worsd
the oponents defense should soften the blow fron the attack 
for example if the opponents health is 100 oponents defense its 5 and plares strenght is 20

first caclulate the opponets healththen use (*opponent.getUpdate(new_health) */


void RPG::attack(RPG* opponent) {
    // Calculate the base damage as a percentage of the attacker's strength
    int baseDamage = strength * 0.5; // Example: 50% of strength
    // Apply the defense reduction
    int damage = baseDamage - (opponent->getDefense() * 0.5); // Example: Reduce damage by 50% of defense
   
    damage = std::max(damage, 1);
    // Update the target's health
    opponent->updateHealth(opponent->getHealth() - damage);
    // Output the attack and damage
    cout << name << " attacked " << opponent->getName() << " for " << damage << " damage!" << endl;
}

bool RPG::isAlive() const {
    return health > 0;
}


/* @brief prompts the user to choose a slill and calls the printAction() 
and attack()!
@param opponent  */
void RPG::useSkill(int skillIndex, RPG* opponent) {
    // Step 1: Use a for loop to print out all the player's skills.
    cout << "Available skills:" << endl;
    for (int i = 0; i < SKILL_SIZE; i++) {
        cout << i << ": " << skills[i] << endl;
    }

    
    cout << "Choose a skill to use (enter 0 or 1): ";
    int chosen_skill_index;
    cin >> chosen_skill_index;

    // Ensure the chosen skill index is within the valid range.
    if (chosen_skill_index < 0 || chosen_skill_index >= SKILL_SIZE) {
        cout << "Invalid skill index. Please choose a valid index." << endl;
        return;
    }

   
    string chosen_skill = skills[chosen_skill_index];

    // Step 5: Call printAction with the chosen skill and the opponent as parameters.
    printAction(chosen_skill, *opponent);
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
