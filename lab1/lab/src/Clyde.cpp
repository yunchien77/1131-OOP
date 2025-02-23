#include "../include/Clyde.hpp"
#include <cmath>

Clyde::Clyde(std::string id)
    : Character(id, {7, 7}) {}

void Clyde::SetPacmanPosition(Point pos) {
    pacmanPosition = pos;
}

void Clyde::DoBehavior() {
    int dx = pacmanPosition.x - position.x;
    int dy = pacmanPosition.y - position.y;

    if (std::abs(dx) == 0 || std::abs(dy) == 0) {
        // Horizontal or vertical alignment
        SetPosition(position.x + (dx == 0 ? 0 : (dx > 0 ? 2 : -2)),
                    position.y + (dy == 0 ? 0 : (dy > 0 ? 2 : -2)));
    } else {
        // Diagonal movement
        SetPosition(position.x + (dx > 0 ? 3 : -3),
                    position.y + (dy > 0 ? 3 : -3));
    }
}