#ifndef IRON_INGOT_HPP
#define IRON_INGOT_HPP

#include "ICraftable.hpp"
#include "Ingot.hpp"

class IronIngot final : public Ingot, public ICraftable {
public:
    Armor CraftArmor() override;
};

#endif
