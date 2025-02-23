#ifndef INKY_HPP
#define INKY_HPP

#include "Character.hpp"

class Inky : public Character {
private:
    enum class Direction { TOPLEFT, BOTTOMRIGHT };
    Direction currentDirection;

public:
    Inky(std::string id = "Inky");
    void DoBehavior() override;
};

#endif