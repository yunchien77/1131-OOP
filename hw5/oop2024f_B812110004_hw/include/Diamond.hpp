#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "ICraftable.hpp"

class Diamond final : public ICraftable {
public:
    Armor CraftArmor() override;
};

#endif
