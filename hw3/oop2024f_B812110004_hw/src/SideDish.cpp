//
// Created by User on 2024/10/29.
//

#include "SideDish.hpp"
#include "Ingredients.hpp"

SideDish::SideDish(Production id)
    : Food(id) {
    MakeFood();
}

void SideDish::MakeFood() {
    switch (id) {
    case Production::Frenchfries:
        ingredient = {Ingredients::FranchFries};
        money = (type == SideDishType::SMALL) ? 44 : 59;
        break;
    case Production::Nugget:
        ingredient = {Ingredients::ChickenNugget};
        money = (type == SideDishType::SMALL) ? 44 : 59;
        break;
    case Production::Salad:
        ingredient = {Ingredients::Salad};
        money = 59;
        break;
    default:
        throw std::invalid_argument("Invalid side dish");
    }
}

void SideDish::MakeLarger() {
    if (getId() != Production::Salad) {
        type = SideDishType::BIG;
        money += 15;
    }
}
SideDishType SideDish::GetType() {
    return type;
}