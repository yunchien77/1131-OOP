#include "Object/Clyde.hpp"
#include "State/ChaseState.hpp"
#include "State/ScatterState.hpp"
#include <iostream>

namespace Object {

// Clyde::Clyde(){};
Clyde::Clyde() = default;

std::string Clyde::GetName() const { return name; };

Object::GamePosition Clyde::GetPosition() const { return pos; };

void Clyde::SetState(Object::MonsterState s) {
  switch (s) {
  case MonsterState::Chase:
    std::cout << "Clyde Chase" << std::endl;
    state = std::make_shared<State::ChaseState>();
    break;
  case MonsterState::Scatter:
    std::cout << "Clyde Scatter" << std::endl;
    state = std::make_shared<State::ScatterState>();
    pos = {CLYDE_INITIAL_POS_X, CLYDE_INITIAL_POS_Y};
    std::cout << "pos: " << pos.x << " " << pos.y << std::endl;
    break;
  }
}

void Clyde::Move(const Object::GamePosition &playerPos) {
  pos = state->Behavior(GhostType::CLYDE, pos, playerPos);
}
} // namespace Object
