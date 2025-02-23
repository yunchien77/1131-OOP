#include "State/ScatterState.hpp"
#include "Object/GameObject.hpp"

namespace State {
Object::GamePosition ScatterState::Behavior(GhostType type,
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
};

Object::GamePosition ScatterState::Blinky(
    Object::GamePosition pos,
    Object::GamePosition playerPos) { // Blinky 的初始位置是 (0,0)
  return Object::GamePosition{0, 0};
}

Object::GamePosition ScatterState::Clyde(
    Object::GamePosition pos,
    Object::GamePosition playerPos) { // Clyde 的初始位置是 (11,11)
  return Object::GamePosition{11, 11};
}

Object::GamePosition
ScatterState::Inky(Object::GamePosition pos,
                   Object::GamePosition playerPos) { // Inky 的初始位置是 (0,11)
  return Object::GamePosition{0, 11};
}

Object::GamePosition ScatterState::Pinky(
    Object::GamePosition pos,
    Object::GamePosition playerPos) { // Pinky 的初始位置是 (11,0)
  return Object::GamePosition{11, 0};
}
} // namespace State
