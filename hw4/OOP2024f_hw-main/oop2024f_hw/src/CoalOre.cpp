//
// Created by adven on 11/28/2024.
//

#include "CoalOre.hpp"

CoalOre::CoalOre()
    : Ore(Product::Coal) {}

bool CoalOre::Break(Pickaxe tool) {
    return 1;
}

float CoalOre::GetBreakExp() {
    return 2.0f;
}
