#ifndef OOPLAB_CHERRYMANAGER_HPP
#define OOPLAB_CHERRYMANAGER_HPP

#include "Object/Cherry.hpp"
#include "Object/GameObject.hpp"
#include "Object/Player.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

namespace Util {
class CherryManager {
  std::vector<Object::GamePosition> points_pos;
  std::vector<std::shared_ptr<Object::Cherry>> points;
  std::shared_ptr<Object::Player> player;

public:
  CherryManager(std::shared_ptr<Object::Player> player,
                std::vector<Object::GamePosition> pos);

  ~CherryManager();

  std::vector<std::shared_ptr<Object::Cherry>> GetPointList();

  std::size_t GetPointListSize();

  bool IsOverlapping();
};
} // namespace Util

#endif // OOPLAB_CHERRYMANAGER_HPP
