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

    // Variable to keep track of whose turn it is
    bool playerTurn = true;

    // Game loop
    while (player.isAlive() && enemy.isAlive()) {
        printDottedLine();

        if (playerTurn) {
            // Player's turn
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
            cout << "Enemy's Turn:" << endl;
            // Randomly choose a skill for the enemy
            int enemyChoice = rand() % SKILL_SIZE;
            enemy.printAction(enemy.getSkills()[enemyChoice], player);
            // enemy.useSkill(enemyChoice, &player); // Commented out as this function isn't implemented yet
        }

        // Switch turns
        playerTurn = !playerTurn;
    }

    // Determine the winner
    if (player.isAlive()) {
        cout << "Congratulations! You defeated the enemy!" << endl;
    } else {
        cout << "Game over! The enemy has defeated you." << endl;
    }

    return 0;
}
