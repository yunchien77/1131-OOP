#include "Object/Pinky.hpp"
#include <iostream>

namespace Object {

// Pinky::Pinky(){};
Pinky::Pinky() = default;

std::string Pinky::GetName() const { return name; };

Object::GamePosition Pinky::GetPosition() const { return pos; };

void Pinky::SetState(Object::MonsterState s) {
  switch (s) {
  case MonsterState::Chase:
    // std::cout << "Pinky Chase" << std::endl;
    state = std::make_shared<State::ChaseState>();
    break;
  case MonsterState::Scatter:
    // std::cout << "Pinky Scatter" << std::endl;
    state = std::make_shared<State::ScatterState>();
    pos = {0, 11};
    // std::cout << "pos: " << pos.x << " " << pos.y << std::endl;
    break;
  }
}

void Pinky::Move(const Object::GamePosition &playerPos) {
  pos = state->Behavior(GhostType::PINKY, pos, playerPos);
}
} // namespace Object
