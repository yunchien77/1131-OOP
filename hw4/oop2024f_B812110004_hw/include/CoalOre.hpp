//
// Created by 陳世昂 on 2024/11/24.
//

#ifndef OOP_COALORE_HPP
#define OOP_COALORE_HPP

#include "Ore.hpp"

// 煤炭礦
class CoalOre final : public Ore {
protected:
public:
    explicit CoalOre();

    bool Break(Pickaxe tool) override;
    float GetBreakExp() override;
};

#endif // OOP_COALORE_HPP
