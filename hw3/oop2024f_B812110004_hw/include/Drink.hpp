//
// Created by User on 2024/10/29.
//

#ifndef OOP_DRINK_HPP
#define OOP_DRINK_HPP

#include "Food.hpp"
#include "Ingredients.hpp"
#include <stdexcept>

class Drink final : public Food {
private:
    int ml;

public:
    Drink(Production id);
    virtual void MakeFood() override;
    void MakeLarger();
    int GetMl();
};

#endif // OOP_DRINK_HPP
