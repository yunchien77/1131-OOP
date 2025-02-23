//
// Created by adven on 11/28/2024.
//

#include "CoalOre.hpp"

CoalOre::CoalOre()
    : Ore(Product::Coal) {}

bool CoalOre::Break(Pickaxe tool) {
    // Coal ore can be broken by wooden, stone, iron, gold, and diamond pickaxes
    return tool >= Pickaxe::Wooden;
}

float CoalOre::GetBreakExp() {
    return 2.0f; // Breaking coal ore gives 2.0 experience
}
