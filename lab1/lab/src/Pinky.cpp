#include "../include/Pinky.hpp"

Pinky::Pinky(std::string id)
    : Character(id, {0, 15}),
      currentDirection(Direction::BOTTOMLEFT) {}

void Pinky::DoBehavior() {
    switch (currentDirection) {
    case Direction::BOTTOMLEFT:
        SetPosition(position.x + 3, position.y - 3);
        if (position.x >= 15 || position.y <= 0)
            currentDirection = Direction::TOPRIGHT;
        break;
    case Direction::TOPRIGHT:
        SetPosition(position.x - 3, position.y + 3);
        if (position.x <= 0 || position.y >= 15)
            currentDirection = Direction::BOTTOMLEFT;
        break;
    }
}