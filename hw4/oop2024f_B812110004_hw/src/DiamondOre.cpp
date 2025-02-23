//
// Created by adven on 11/28/2024.
//

#include "DiamondOre.hpp"
#include "Product.hpp"

DiamondOre::DiamondOre()
    : Ore(Product::Diamond) {}

bool DiamondOre::Break(Pickaxe tool) {
    // Diamond ore can be broken by iron, golden, and diamond pickaxes
    return tool >= Pickaxe::Iron;
}

float DiamondOre::GetBreakExp() {
    return 4.0f;
}
