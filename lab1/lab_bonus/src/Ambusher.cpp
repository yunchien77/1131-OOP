#include "../include/Ambusher.hpp"
#include <cmath>

Ambusher::Ambusher(std::string id)
    : Character(id, {8, 8}),
      gen(rd()) {}

void Ambusher::SetPacmanPosition(Point pos) {
    pacmanPosition = pos;
}

void Ambusher::DoBehavior() {
    // 可能的移動方向
    std::vector<Point> possibleMoves = {
        {pacmanPosition.x, pacmanPosition.y + 3}, // W
        {pacmanPosition.x - 3, pacmanPosition.y}, // A
        {pacmanPosition.x, pacmanPosition.y - 3}, // S
        {pacmanPosition.x + 3, pacmanPosition.y}  // D
    };

    // 隨機數生成器
    std::uniform_int_distribution<> dis(0, 3);

    // 隨機選擇一個移動方向
    Point selectedMove = possibleMoves[dis(gen)];

    // 移動到選定的位置
    SetPosition(selectedMove);
}