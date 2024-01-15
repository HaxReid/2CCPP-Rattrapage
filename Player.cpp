#include "Player.h"

Player::Player(std::basic_string<char> name, int line, int column) : name(name), line(line), column(column) {}

const std::basic_string<char> Player::getName() const {
    return name;
}

int Player::getLine() const {
    return line;
}

int Player::getColumn() const {
    return column;
}

void Player::setName(char name) {
    this->name = name;
}

void Player::setLine(int line) {
    this->line = line;
}

void Player::setColumn(int column) {
    this->column = column;
}
