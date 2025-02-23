#ifndef CLYDE_HPP
#define CLYDE_HPP

#include "Character.hpp"

class Clyde : public Character {
private:
    Point pacmanPosition;

public:
    Clyde(std::string id = "Clyde");
    void SetPacmanPosition(Point pos) override;
    void DoBehavior() override;
};

#endif