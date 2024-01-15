#include "Square.h"

Square::Square(int value) : value(value) {}

int Square::getValue() const {
    return value;
}

void Square::setValue(int value) {
    this->value = value;
}

Square::Square() {

}
