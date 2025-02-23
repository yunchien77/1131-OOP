#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "Character.hpp"

class Pacman : public Character {
public:
    Pacman(std::string id = "Pacman");
    void DoBehavior() override;
    void Move(char direction);
};

#endif