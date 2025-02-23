#include "../include/Inky.hpp"

Inky::Inky(std::string id)
    : Character(id, {15, 15}),
      currentDirection(Direction::TOPLEFT) {}

void Inky::DoBehavior() {
    switch (currentDirection) {
    case Direction::TOPLEFT:
        SetPosition(position.x - 3, position.y - 3);
        if (position.x <= 0 || position.y <= 0)
            currentDirection = Direction::BOTTOMRIGHT;
        break;
    case Direction::BOTTOMRIGHT:
        SetPosition(position.x + 3, position.y + 3);
        if (position.x >= 15 || position.y >= 15)
            currentDirection = Direction::TOPLEFT;
        break;
    }
}