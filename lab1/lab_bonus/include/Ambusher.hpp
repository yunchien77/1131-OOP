#ifndef AMBUSHER_HPP
#define AMBUSHER_HPP
#include "Character.hpp"
#include <random>

class Ambusher : public Character {
private:
    Point pacmanPosition;
    std::random_device rd;
    std::mt19937 gen;

public:
    Ambusher(std::string id = "Ambusher");
    void SetPacmanPosition(Point pos) override;
    void DoBehavior() override;
};
#endif