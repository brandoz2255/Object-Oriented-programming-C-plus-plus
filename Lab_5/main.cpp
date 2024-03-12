#include <iostream>
#include "RPG.h"

using namespace std;

// Function to print dotted lines
void printDottedLine() {
    std::cout << "----------------------------------------" << std::endl;
}

int main() {

    printDottedLine();
    // Create two RPG characters
    RPG player("Player", 100, 15, "Warrior", 20);
    RPG enemy("Enemy", 80, 10, "Goblin", 15);

    // Set skills for both characters
    player.setSkills();
    enemy.setSkills();


    printDottedLine();

    // Print initial character stats
    cout << "Player stats: Name: " << player.getName() << ", Health: " << player.getHealth() << ", Strength: " << player.getStrength() << ", Defense: " << player.getDefense() << endl;
    cout << "Enemy stats: Name: " << enemy.getName() << ", Health: " << enemy.getHealth() << ", Strength: " << enemy.getStrength() << ", Defense: " << enemy.getDefense() << endl;

    // Perform an attack
    player.attack(&enemy);



    printDottedLine();
    // Print updated character stats after attack
    cout << "Player stats: Name: " << player.getName() << ", Health: " << player.getHealth() << ", Strength: " << player.getStrength() << ", Defense: " << player.getDefense() << endl;
    cout << "Enemy stats: Name: " << enemy.getName() << ", Health: " << enemy.getHealth() << ", Strength: " << enemy.getStrength() << ", Defense: " << enemy.getDefense() << endl;

    return 0;
}