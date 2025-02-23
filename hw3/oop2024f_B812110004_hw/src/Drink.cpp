//
// Created by User on 2024/10/29.
//

#include "Drink.hpp"
#include "Ingredients.hpp"

Drink::Drink(Production id)
    : Food(id) {
    MakeFood();
}

void Drink::MakeFood() {
    switch (getId()) {
    case Production::Cola:
        ingredient = {Ingredients::Cola};
        money = 28;
        break;
    case Production::Spirit:
        ingredient = {Ingredients::Spirit};
        money = 28;
        break;
    case Production::CaramelMilktea:
        ingredient = {Ingredients::Caramel, Ingredients::Milktea};
        money = 44;
        break;
    case Production::Latte:
        ingredient = {Ingredients::Coffee, Ingredients::Milk};
        money = 45;
        break;
    default:
        throw std::invalid_argument("Unknown drink type");
    }
}

void Drink::MakeLarger() {
    if (getId() != Production::CaramelMilktea) {
        ml = 750;
        money += 10;
    }
}
int Drink::GetMl() {
    return ml;
}
