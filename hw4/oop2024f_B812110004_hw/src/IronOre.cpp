//
// Created by adven on 11/28/2024.
//

#include "IronOre.hpp"
#include "Product.hpp"

IronOre::IronOre()
    : SmeltableOre(Product::Iron) {}

bool IronOre::Break(Pickaxe tool) {
    // Iron ore can be broken by stone, iron, golden, and diamond pickaxes
    return tool >= Pickaxe::Stone;
}

float IronOre::GetBreakExp() {
    return 0;
}

float IronOre::GetSmeltExp() {
    return 0.7f;
}