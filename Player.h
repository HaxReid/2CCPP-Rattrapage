#ifndef RESIT_PLAYER_H
#define RESIT_PLAYER_H

#include <string>

class Player{
private:

    std::basic_string<char> name;
    int line;
    int column;

public:
    Player(std::__cxx11::basic_string<char> name, int line, int column);

    void setName(char name);

    void setLine(int line);

    void setColumn(int column);

    int getLine() const;

    const std::basic_string<char> getName() const;

    int getColumn() const;
};


#endif //RESIT_PLAYER_H
