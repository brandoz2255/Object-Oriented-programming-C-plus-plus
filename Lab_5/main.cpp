#include <iostream>
#include "RPG.h"
#include "RPG.cpp"

using namespace std;

// Function to print dotted lines
void printDottedLine() {
    cout << "----------------------------------------" << endl;
}

int main() {
    // Create two RPG characters
    RPG player("Da Wiz", 100, 15, "mage", 20);
    RPG enemy("Shrek", 80, 10, "Goblin", 15);

    // Set skills for both characters
    player.setSkills();
    enemy.setSkills();

    // Print initial stats
    cout << "Player stats: Name: " << player.getName() << ", Health: " << player.getHealth() << ", Strength: " << player.getStrength() << ", Defense: " << player.getDefense() << endl;
    cout << "Enemy stats: Name: " << enemy.getName() << ", Health: " << enemy.getHealth() << ", Strength: " << enemy.getStrength() << ", Defense: " << enemy.getDefense() << endl;

    // Variable to keep track of whose turn it is
    bool playerTurn = true;

    // Game loop
    while (player.isAlive() && enemy.isAlive()) {
        if (playerTurn) {
            // Player's turn
            printDottedLine();
            cout << "Player's Turn:" << endl;
            // Display player's skills
            cout << "Choose a skill to use:" << endl;
            player.setSkills();

            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            // Perform skill usage
            player.printAction(player.getSkills()[choice - 1], enemy);
            // player.useSkill(choice - 1, &enemy); // Commented out as this function isn't implemented yet
        } else {
            // Enemy's turn
            printDottedLine();
            cout << "Enemy's Turn:" << endl;
            // Randomly choose a skill for the enemy
            int enemyChoice = rand() % SKILL_SIZE;
            enemy.printAction(enemy.getSkills()[enemyChoice], player);
            player.updateHealth(player.getHealth() - enemy.getStrength()); // Enemy attacks player
        }

        // Switch turns
        playerTurn = !playerTurn;
    }

    // Print final stats
    cout << "Player stats: Name: " << player.getName() << ", Health: " << player.getHealth() << ", Strength: " << player.getStrength() << ", Defense: " << player.getDefense() << endl;
    cout << "Enemy stats: Name: " << enemy.getName() << ", Health: " << enemy.getHealth() << ", Strength: " << enemy.getStrength() << ", Defense: " << enemy.getDefense() << endl;

    // Determine the winner
    if (player.isAlive()) {
        cout << "Congratulations! You defeated the enemy!" << endl;
    } else {
        cout << "Game over! The enemy has defeated you." << endl;
    }

    return 0;
}
