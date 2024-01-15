#ifndef LABYRINTH_H
#define LABYRINTH_H

#include "Board.h"
#include <string>

class Labyrinth {
private:
    Board board;
    std::string playerName;

public:
    Labyrinth(const std::string &playerName, int boardHeight, int boardWidth, int **exampleData);

    void play();
};

#endif // LABYRINTH_H
