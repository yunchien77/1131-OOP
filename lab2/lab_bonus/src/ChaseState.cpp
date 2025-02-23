#include "State/ChaseState.hpp"
#include "iostream"
namespace State {
Object::GamePosition ChaseState::Behavior(GhostType type,
                                          Object::GamePosition pos,
                                          Object::GamePosition playerPos) {
  switch (type) {
  case GhostType::BLINKY:
    return Blinky(pos, playerPos);
  case GhostType::INKY:
    return Inky(pos, playerPos);
  case GhostType::PINKY:
    return Pinky(pos, playerPos);
  case GhostType::CLYDE:
    return Clyde(pos, playerPos);
  default:
    return pos;
  }
}

bool ChaseState::IsOutRange(Object::GamePosition pos) {
  return pos.x < 0 || pos.x >= 12 || pos.y < 0 || pos.y >= 12;
}

Object::GamePosition ChaseState::Blinky(Object::GamePosition pos,
                                        Object::GamePosition playerPos) {
  Object::GamePosition newPos = pos;

  // Move towards player in X direction
  if (pos.x < playerPos.x)
    newPos.x++;
  else if (pos.x > playerPos.x)
    newPos.x--;

  // Move towards player in Y direction
  if (pos.y < playerPos.y)
    newPos.y++;
  else if (pos.y > playerPos.y)
    newPos.y--;

  return IsOutRange(newPos) ? pos : newPos;
}

Object::GamePosition ChaseState::Clyde(Object::GamePosition pos,
                                       Object::GamePosition playerPos) {
  // Check if player is within 4 units range
  bool inRange = abs(pos.x - playerPos.x) <= 4 && abs(pos.y - playerPos.y) <= 4;

  if (inRange) {
    return Blinky(pos, playerPos); // Chase like Blinky
  } else {
    // Random movement
    static bool seeded = false;
    if (!seeded) {
      srand(time(nullptr));
      seeded = true;
    }

    Object::GamePosition newPos = pos;
    newPos.x += (rand() % 3) - 1; // -1, 0, or 1
    newPos.y += (rand() % 3) - 1; // -1, 0, or 1

    return IsOutRange(newPos) ? pos : newPos;
  }
}

Object::GamePosition ChaseState::Inky(Object::GamePosition pos,
                                      Object::GamePosition playerPos) {
  // Calculate target position (player pos + (player pos - ghost pos))
  Object::GamePosition target = {playerPos.x + (playerPos.x - pos.x),
                                 playerPos.y + (playerPos.y - pos.y)};

  Object::GamePosition newPos = pos;

  // Move towards target
  if (pos.x < target.x)
    newPos.x++;
  else if (pos.x > target.x)
    newPos.x--;

  if (pos.y < target.y)
    newPos.y++;
  else if (pos.y > target.y)
    newPos.y--;

  return IsOutRange(newPos) ? pos : newPos;
}

Object::GamePosition ChaseState::Pinky(Object::GamePosition pos,
                                       Object::GamePosition playerPos) {
  // Target is 4 spaces ahead of player in X direction
  Object::GamePosition target = {playerPos.x + 4, playerPos.y};

  Object::GamePosition newPos = pos;

  if (pos.x < target.x)
    newPos.x++;
  else if (pos.x > target.x)
    newPos.x--;

  if (pos.y < target.y)
    newPos.y++;
  else if (pos.y > target.y)
    newPos.y--;

  return IsOutRange(newPos) ? pos : newPos;
}
} // namespace State
