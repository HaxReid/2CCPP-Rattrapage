#ifndef BOARD_H
#define BOARD_H

#include "Player.h"
#include "Square.h"

class Board {
private:
    int height;
    int width;
    Player player;
    Square** board;
    int** exampleBoardData;

public:
    Board(int height, int width, const Player &player, int **exampleData);

    ~Board();

    void display() const;

    void move(char direction);

    bool testWin() const;

    void reset();
};

#endif // BOARD_H
