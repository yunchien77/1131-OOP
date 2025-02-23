//
// Created by User on 2024/10/29.
//

#include "MainDish.hpp"
#include "Ingredients.hpp"
#include <stdexcept>

MainDish::MainDish(Production id)
    : Food(id) {
    MakeFood();
}
void MainDish::MakeFood() {
    switch (id) {
    case Production::PorkBurger:
        ingredient = {Ingredients::PorkSteak, Ingredients::Lattuce,
                      Ingredients::BurgerBread, Ingredients::Cheese};
        money = 59;
        break;
    case Production::BeefBurger:
        ingredient = {Ingredients::BeefSteak, Ingredients::Lattuce,
                      Ingredients::BurgerBread, Ingredients::Cheese};
        money = 69;
        break;
    case Production::FishBurger:
        ingredient = {Ingredients::FishSteak, Ingredients::Lattuce,
                      Ingredients::BurgerBread, Ingredients::Cheese};
        money = 79;
        break;
    default:
        std::invalid_argument("jj");
    }
}
void MainDish::AddIngredients(std::vector<Ingredients> addtional) {
    for (auto add : addtional) {
        switch (add) {
        case Ingredients::PorkSteak:
            money += 20;
            break;
        case Ingredients::BeefSteak:
            money += 20;
            break;
        case Ingredients::FishSteak:
            money += 20;
            break;
        case Ingredients::Lattuce:
            money += 10;
            break;
        case Ingredients::Cheese:
            money += 10;
            break;
        default:
            throw std::invalid_argument("gg");
        }
        ingredient.push_back((add));
    }
}
