#include <iostream>
#include "RPG.h"
#include "RPG.cpp"

using namespace std;

// Function to print dotted lines
void printDottedLine() {
    cout << "----------------------------------------" << endl;
}


/* @brief prints both players name and their health
example output for names 
 */
void displayStats(const RPG& player, const RPG& enemy) {
    cout << "Player stats: Name: " << player.getName() << ", Health: " << player.getHealth() << ", Strength: " << player.getStrength() << ", Defense: " << player.getDefense() << endl;
    cout << "Enemy stats: Name: " << enemy.getName() << ", Health: " << enemy.getHealth() << ", Strength: " << enemy.getStrength() << ", Defense: " << enemy.getDefense() << endl;
}


void gameLoop(RPG& player, RPG& enemy) {
    bool playerTurn = true;

    // Display available skills before the loop starts
    player.setSkills();
    printDottedLine();
    cout << "Available skills:" << endl;
    cout << "0. " << player.getSkills()[0] << endl; // Display skill at index 0
    cout << "1. " << player.getSkills()[1] << endl; // Display skill at index 1

    while (player.isAlive() && enemy.isAlive()) {
        if (playerTurn) {
            printDottedLine();
            cout << "Player's Turn:" << endl;

            int choice;
            cout << "Choose a skill to use (0 or 1)-> "; // Changed the prompt message
            cin >> choice;

            // Use the chosen skill
            player.useSkill(choice, &enemy); // Pass choice directly

            // Display stats after player's turn
            displayStats(player, enemy);
        } else {
            printDottedLine();
            cout << "Enemy's Turn:" << endl;
            int enemyChoice = rand() % SKILL_SIZE;
            enemy.printAction(enemy.getSkills()[enemyChoice], player);
            player.updateHealth(player.getHealth() - enemy.getStrength());
            // Display stats after enemy's turn
            displayStats(player, enemy);
        }

        playerTurn = !playerTurn;
    }
}


/**
 * @brief displays who wins based on who is alive 
 * use an if statement to check whether player1 is 
 * alive if so print that they won else player 2
 * 
 * 
 * Example Output:
 * Da Wiz defeated Shrek: good game!\n
 * 
 * @param player 
 * @param enemy
 * 
 */

void displayEnd(const RPG& player, const RPG& enemy) {
    if (player.isAlive()) {
        cout << "\nCongratulations! You defeated the enemy!" << endl;
    } else {
        cout << "\nGame over! The enemy has defeated you." << endl;
    }
}







int main() {
    // Create two RPG characters
    RPG player("Da Wiz", 100, 15, "mage", 20);
    RPG enemy("Shrek", 80, 10, "Goblin", 15);

    // Set skills for both characters
    player.setSkills();
    enemy.setSkills();

    // Display initial stats
    displayStats(player, enemy);

    // Run the game loop
    gameLoop(player, enemy);

    // Display the final outcome
    displayEnd(player, enemy);

    // Display final stats
    displayStats(player, enemy);

    return 0;
}



