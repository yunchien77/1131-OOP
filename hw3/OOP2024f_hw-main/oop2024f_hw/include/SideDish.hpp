//
// Created by User on 2024/10/29.
//

#ifndef OOP_SIDEDISH_HPP
#define OOP_SIDEDISH_HPP

#include "Food.hpp"
#include "Ingredients.hpp"
#include <stdexcept>
#include <string>

enum class SideDishType { BIG = 0, SMALL = 1 };

class SideDish final : public Food {
private:
    SideDishType type = SideDishType::SMALL;

public:
    SideDish(Production id);
    virtual void MakeFood() override;
    void MakeLarger();
    SideDishType GetType();
};

#endif // OOP_SIDEDISH_HPP
