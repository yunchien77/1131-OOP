//
// Created by adven on 11/28/2024.
//

#include "DiamondOre.hpp"
#include "Pickaxe.hpp"

DiamondOre::DiamondOre()
    : Ore(Product::Diamond) {}

bool DiamondOre::Break(Pickaxe tool) {
    if (tool >= Pickaxe::Iron) {
        return 1;
    }
    return 0;
}

float DiamondOre::GetBreakExp() {
    return 4.0f;
}
