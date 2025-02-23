#ifndef OOPLAB_CHERRY_HPP
#define OOPLAB_CHERRY_HPP

#include "GameObject.hpp"
#include "Interface/GetPointer.hpp"

namespace Object {
class Cherry : public Object::GetPointer, public Object::GameObject {
  Object::GamePosition position;

public:
  Cherry(Object::GamePosition pos);

  ~Cherry() = default;

  uint8_t GetPoint() override;

  std::string GetName() const override;

  Object::GamePosition GetPosition() const override;
};
} // namespace Object

#endif // OOPLAB_CHERRY_HPP
