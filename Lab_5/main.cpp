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

    while (player.isAlive() && enemy.isAlive()) {
        if (playerTurn) {
            printDottedLine();
            cout << "Player's Turn:" << endl;
            player.setSkills();

            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            cout << "Available skills:" << endl;
            for (int i = 0; i < SKILL_SIZE; ++i) {
                cout << i + 1 << ". " << player.getSkills()[i] << endl; // Accessing skill names directly
            }
            cout << "Enter your choice (1 or 2): ";

            cin >> choice;

            player.printAction(player.getSkills()[choice - 1], enemy);
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
        cout << "Congratulations! You defeated the enemy!" << endl;
    } else {
        cout << "Game over! The enemy has defeated you." << endl;
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




/* 
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
 */