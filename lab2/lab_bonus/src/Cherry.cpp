#include "Object/Cherry.hpp"

namespace Object {
Cherry::Cherry(Object::GamePosition pos) : position(pos){};

uint8_t Cherry::GetPoint() { return 1; }

std::string Cherry::GetName() const { return "x"; }

Object::GamePosition Cherry::GetPosition() const { return position; }
} // namespace Object
