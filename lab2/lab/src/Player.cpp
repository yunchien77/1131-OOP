#include "Object/Player.hpp"
#include "Object/GameObject.hpp"

namespace Object {

std::string Player::GetName() const { return name; };

Object::GamePosition Player::GetPosition() const { return pos; };

void Player::Move(char direction) {
  GamePosition newPos = pos;

  switch (direction) {
  case 'w':
    newPos.y++;
    break;
  case 's':
    newPos.y--;
    break;
  case 'a':
    newPos.x--;
    break;
  case 'd':
    newPos.x++;
    break;
  default:
    return;
  }

  // Update position if within bounds
  if (newPos.x >= 0 && newPos.x < 12 && newPos.y >= 0 && newPos.y < 12) {
    pos = newPos;
  }
}

bool Player::IsOutRange() {
  return pos.x < 0 || pos.x >= 12 || pos.y < 0 || pos.y >= 12;
}

} // namespace Object
