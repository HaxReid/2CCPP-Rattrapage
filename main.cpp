#include <iostream>
#include "Labyrinth.h"
#include "Board.h"

int main() {
    int boardHeight = 7;
    int boardWidth = 5;

    int exampleData[7][5] = {
            {1, 1, 1, 1, 1},
            {1, 2, 0, 0, 1},
            {1, 0, 3, 0, 1},
            {1, 1, 1, 0, 1},
            {1, 4, 3, 0, 1},
            {1, 0, 0, 4, 1},
            {1, 1, 1, 1, 1}
    };

    int* exampleDataPtr[7];
    for (int i = 0; i < 7; ++i) {
        exampleDataPtr[i] = exampleData[i];
    }

    std::string playerName;
    std::cout << "Enter your player name: ";
    std::cin >> playerName;

    Labyrinth labyrinth(playerName, boardHeight, boardWidth, exampleDataPtr);

    labyrinth.play();

    return 0;
}
