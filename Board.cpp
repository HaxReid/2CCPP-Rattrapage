#include "Board.h"
#include <iostream>

Board::Board(int height, int width, const Player& player, int** exampleData)
        : height(height), width(width), player(player), exampleBoardData(exampleData) {

    board = new Square*[height];
    for (int i = 0; i < height; ++i) {
        board[i] = new Square[width];
        for (int j = 0; j < width; ++j) {
            board[i][j] = Square(exampleData[i][j]);
        }
    }

    board[player.getLine()][player.getColumn()] = Square(2);
}


Board::~Board() {
    for (int i = 0; i < height; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

void Board::display() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == player.getLine() && j == player.getColumn()) {
                std::cout << "P ";
            } else {
                int value = board[i][j].getValue();
                if (value == 0) {
                    std::cout << ". ";
                } else if (value == 1) {
                    std::cout << "X ";
                } else if (value == 3) {
                    std::cout << "+ ";
                } else if (value == 4) {
                    std::cout << "O ";
                } else if (value == 5) {
                    std::cout << "# ";
                }
            }
        }
        std::cout << std::endl;
    }
}

void Board::move(char direction) {
    int newRow = player.getLine();
    int newCol = player.getColumn();

    if (direction == 'N') {
        newRow--;
    } else if (direction == 'S') {
        newRow++;
    } else if (direction == 'E') {
        newCol++;
    } else if (direction == 'W') {
        newCol--;
    }

    if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width) {
        Square& targetSquare = board[newRow][newCol];
        if (targetSquare.getValue() == 0 || targetSquare.getValue() == 4) {
            if (targetSquare.getValue() == 4) {
                targetSquare.setValue(3);
            }
            board[player.getLine()][player.getColumn()].setValue(0);
            player.setLine(newRow);
            player.setColumn(newCol);
            board[newRow][newCol].setValue(2);
        }
    }
}

bool Board::testWin() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (board[i][j].getValue() == 4) {
                return true;
            }
        }
    }
    return false;
}

void Board::reset() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            board[i][j].setValue(exampleBoardData[i][j]);
        }
    }

    int newPlayerLine = -1;
    int newPlayerColumn = -1;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (board[i][j].getValue() == 2) {
                newPlayerLine = i;
                newPlayerColumn = j;
                break;
            }
        }
        if (newPlayerLine != -1) {
            break;
        }
    }

    player.setLine(newPlayerLine);
    player.setColumn(newPlayerColumn);
}

