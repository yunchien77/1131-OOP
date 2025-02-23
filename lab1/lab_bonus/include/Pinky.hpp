#ifndef PINKY_HPP
#define PINKY_HPP

#include "Character.hpp"

class Pinky : public Character {
private:
    enum class Direction { TOPRIGHT, BOTTOMLEFT };
    Direction currentDirection;

public:
    Pinky(std::string id = "Pinky");
    void DoBehavior() override;
};

#endif