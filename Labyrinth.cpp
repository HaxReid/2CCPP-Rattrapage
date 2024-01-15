#include "Labyrinth.h"
#include <iostream>

Labyrinth::Labyrinth(const std::string &playerName, int boardHeight, int boardWidth, int **exampleData)
        : board(boardHeight, boardWidth, Player(playerName, 0, 0), exampleData), playerName(playerName) {}

void Labyrinth::play() {
    char restart;
    bool gameOver = false;

    do {
        std::cout << "Welcome, " << playerName << "! Let's play the labyrinth game." << std::endl;

        while (!gameOver) {
            std::cout << "Enter a direction (N/S/E/W) or 'R' to restart: ";
            char direction;
            std::cin >> direction;

            if (direction == 'R' || direction == 'r') {
                std::cout << "Restarting the game." << std::endl;
                gameOver = true;
            } else {
                board.move(direction);
                board.display();

                if (!board.testWin()) {
                    std::cout << "Congratulations, you have won the game!" << std::endl;
                    gameOver = true;
                }
            }
        }

        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> restart;
        if (restart == 'Y' || restart == 'y') {
            board.reset();
            gameOver = false;
        } else {
            std::cout << "Thank you for playing!" << std::endl;
        }
    } while (restart == 'Y' || restart == 'y');
}


