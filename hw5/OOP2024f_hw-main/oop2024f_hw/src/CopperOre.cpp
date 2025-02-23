#include "CopperOre.hpp"

#include "CopperIngot.hpp"
#include <memory>

bool CopperOre::BreakableBy(Pickaxe pickaxe) {
    return (pickaxe == Pickaxe::Iron) || (pickaxe == Pickaxe::Stone) ||
           (pickaxe == Pickaxe::Diamond);
}

std::shared_ptr<Ingot> CopperOre::Smelt() {
    return std::make_shared<CopperIngot>();
}
