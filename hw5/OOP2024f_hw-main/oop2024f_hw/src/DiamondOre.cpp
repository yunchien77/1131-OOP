#include "DiamondOre.hpp"

bool DiamondOre::BreakableBy(Pickaxe pickaxe) {
    return (pickaxe == Pickaxe::Iron) || (pickaxe == Pickaxe::Diamond);
}
