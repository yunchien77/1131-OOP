#include "../include/Blinky.hpp"

Blinky::Blinky(std::string id)
    : Character(id, {0, 0}),
      currentDirection(Direction::TOPLEFT) {}

void Blinky::DoBehavior() {
    switch (currentDirection) {
    case Direction::TOPLEFT:
        SetPosition(position.x, position.y + 3);
        if (position.y >= 15)
            currentDirection = Direction::TOPRIGHT;
        break;
    case Direction::TOPRIGHT:
        SetPosition(position.x + 3, position.y);
        if (position.x >= 15)
            currentDirection = Direction::BOTTOMRIGHT;
        break;
    case Direction::BOTTOMRIGHT:
        SetPosition(position.x, position.y - 3);
        if (position.y <= 0)
            currentDirection = Direction::BOTTOMLEFT;
        break;
    case Direction::BOTTOMLEFT:
        SetPosition(position.x - 3, position.y);
        if (position.x <= 0)
            currentDirection = Direction::TOPLEFT;
        break;
    }
}