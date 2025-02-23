#include "Object/Inky.hpp"
#include <iostream>

namespace Object {

// Inky::Inky(){};
Inky::Inky() = default;

std::string Inky::GetName() const { return name; };

Object::GamePosition Inky::GetPosition() const { return pos; };

void Inky::SetState(Object::MonsterState s) {
  switch (s) {
  case MonsterState::Chase:
    std::cout << "Inky Chase" << std::endl;
    state = std::make_shared<State::ChaseState>();
    break;
  case MonsterState::Scatter:
    std::cout << "Inky Scatter" << std::endl;
    state = std::make_shared<State::ScatterState>();
    pos = {INKY_INITIAL_POS_X, INKY_INITIAL_POS_Y};
    std::cout << "pos: " << pos.x << " " << pos.y << std::endl;
    break;
  }
}

void Inky::Move(const Object::GamePosition &playerPos) {
  pos = state->Behavior(GhostType::INKY, pos, playerPos);
}
} // namespace Object
