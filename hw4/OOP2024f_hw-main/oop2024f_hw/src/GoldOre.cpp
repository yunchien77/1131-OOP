//
// Created by adven on 11/28/2024.
//

#include "GoldOre.hpp"
#include "Pickaxe.hpp"
#include "Product.hpp"

GoldOre::GoldOre()
    : SmeltableOre(Product::Gold) {}

bool GoldOre::Break(Pickaxe tool) {
    if (tool >= Pickaxe::Iron) {
        return 1;
    }
    return 0;
}

float GoldOre::GetBreakExp() {
    return 0;
}

float GoldOre::GetSmeltExp() {
    return 1.0f;
}