//
// Created by adven on 11/28/2024.
//

#include "GoldOre.hpp"
#include "Product.hpp"

GoldOre::GoldOre()
    : SmeltableOre(Product::Gold) {}

bool GoldOre::Break(Pickaxe tool) {
    // Gold ore can be broken by iron, golden, and diamond pickaxes
    return tool >= Pickaxe::Iron;
}

float GoldOre::GetBreakExp() {
    return 0;
}

float GoldOre::GetSmeltExp() {
    return 1.0f;
}