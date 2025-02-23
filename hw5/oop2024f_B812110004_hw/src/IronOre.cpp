#include "IronOre.hpp"

#include "IronIngot.hpp"
bool IronOre::BreakableBy(Pickaxe pickaxe) {
    return pickaxe == Pickaxe::Stone || pickaxe == Pickaxe::Iron ||
           pickaxe == Pickaxe::Diamond;
}

std::shared_ptr<Ingot> IronOre::Smelt() {
    return std::make_shared<IronIngot>();
}