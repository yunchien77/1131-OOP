#include "../include/Character.hpp"

Character::Character(std::string id, Point startPos)
    : id(id),
      position(startPos) {}

Point Character::GetPosition() const {
    return position;
}

void Character::SetPosition(int x, int y) {
    // Boundary check
    position.x = std::max(0, std::min(x, 15));
    position.y = std::max(0, std::min(y, 15));
}

void Character::SetPosition(Point newPos) {
    SetPosition(newPos.x, newPos.y);
}

bool Character::IsColliding(const Character *other) const {
    return position.x == other->GetPosition().x &&
           position.y == other->GetPosition().y;
}

void Character::SetPacmanPosition(Point pos) {}