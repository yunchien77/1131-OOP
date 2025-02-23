//
// Created by User on 2024/10/29.
//
#include "Food.hpp"

Food::Food(Production id) {
    this->id = id;
}
Production Food::getId() const {
    return id;
}
std::vector<Ingredients> Food::GetIngredient() {
    return ingredient;
}

int Food::GetMoney() {
    return money;
}
