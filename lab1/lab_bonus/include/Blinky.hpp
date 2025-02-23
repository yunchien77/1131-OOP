#ifndef BLINKY_HPP
#define BLINKY_HPP

#include "Character.hpp"

class Blinky : public Character {
private:
    enum class Direction { TOPLEFT, TOPRIGHT, BOTTOMRIGHT, BOTTOMLEFT };
    Direction currentDirection;

public:
    Blinky(std::string id = "Blinky");
    void DoBehavior() override;
};

#endif