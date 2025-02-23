#include "../include/Pacman.hpp"
#include <iostream>

Pacman::Pacman(std::string id)
    : Character(id, {10, 10}) {}

void Pacman::DoBehavior() {
    char move;
    std::cout << "Enter move (W/A/S/D): ";
    std::cin >> move;
    Move(move);
}

void Pacman::Move(char direction) {
    switch (direction) {
    case 'W':
        SetPosition(position.x, position.y - 3);
        break;
    case 'A':
        SetPosition(position.x - 3, position.y);
        break;
    case 'S':
        SetPosition(position.x, position.y + 3);
        break;
    case 'D':
        SetPosition(position.x + 3, position.y);
        break;
    }
}