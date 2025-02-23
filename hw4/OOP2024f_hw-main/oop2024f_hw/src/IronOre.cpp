//
// Created by adven on 11/28/2024.
//

#include "IronOre.hpp"
#include "Pickaxe.hpp"
#include "Product.hpp"
#include "SmeltableOre.hpp"

IronOre::IronOre()
    : SmeltableOre(Product::Iron) {}

bool IronOre::Break(Pickaxe tool) {
    if (tool >= Pickaxe::Stone) {
        return 1;
    }
    return 0;
}

float IronOre::GetBreakExp() {
    return 0;
}

float IronOre::GetSmeltExp() {
    return 0.7f;
}