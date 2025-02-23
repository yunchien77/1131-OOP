#include "Util/CherryManager.hpp"

namespace Util {
CherryManager::CherryManager(std::shared_ptr<Object::Player> player,
                             std::vector<Object::GamePosition> pos)
    : player(player), points_pos(pos) {
  for (auto &pos_elem : points_pos) {
    points.push_back(std::make_shared<Object::Cherry>(pos_elem));
  }
};

CherryManager::~CherryManager() = default;

std::vector<std::shared_ptr<Object::Cherry>> CherryManager::GetPointList() {
  return points;
}

std::size_t CherryManager::GetPointListSize() { return points.size(); }

bool CherryManager::IsOverlapping() {
  for (auto &point : points) {
    if (point->GetPosition().x == player->GetPosition().x &&
        point->GetPosition().y == player->GetPosition().y) {
      points.erase(std::remove(points.begin(), points.end(), point),
                   points.end());
      return true;
    }
  }
  return false;
}
} // namespace Util
