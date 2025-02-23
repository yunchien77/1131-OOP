#include "Object/Blinky.hpp"
#include "State/ChaseState.hpp"
#include "State/ScatterState.hpp"
#include <iostream>

namespace Object {

// Blinky::Blinky() {}
Blinky::Blinky() = default;

std::string Blinky::GetName() const { return name; };

Object::GamePosition Blinky::GetPosition() const { return pos; };

void Blinky::SetState(Object::MonsterState s) {
  switch (s) {
  case MonsterState::Chase:
    // std::cout << "Blinky Chase" << std::endl;
    state = std::make_shared<State::ChaseState>();
    break;
  case MonsterState::Scatter:
    // std::cout << "Blinky Scatter" << std::endl;
    state = std::make_shared<State::ScatterState>();
    pos = {0, 0};
    // std::cout << "pos: " << pos.x << " " << pos.y << std::endl;
    break;
  }
}

void Blinky::Move(const Object::GamePosition &playerPos) {
  pos = state->Behavior(GhostType::BLINKY, pos, playerPos);
};
} // namespace Object
