//
// Created by 陳世昂 on 2024/11/24.
//

#ifndef OOP_FURNACE_HPP
#define OOP_FURNACE_HPP

#include <memory>
#include <vector>

#include "CoalOre.hpp"
#include "DiamondOre.hpp"
#include "GoldOre.hpp"
#include "IronOre.hpp"
#include "List.hpp"
#include "Ore.hpp"
#include "SmeltableOre.hpp"

#include "Config.hpp"

class Furnace final {
private:
    // 儲存可熔煉的礦物
    std::vector<std::shared_ptr<SmeltableOre>> m_SmeltableOres;

    // 當前正在熔煉的礦物類型（用於限制只能熔煉同一類型的礦物）
    Product m_CurrentSmeltingType;

    // 是否已開始熔煉
    bool m_IsSmeltingStarted = false;

public:
    void AddIronOre(std::shared_ptr<IronOre> ore);

    void AddGoldOre(std::shared_ptr<GoldOre> ore);

    std::vector<Product> PickupProduct();

#if TESTING_TARGET2
    void AddOre(std::shared_ptr<SmeltableOre> ore);
#endif
#if TESTING_TARGET3
    void AddAnyOre(std::shared_ptr<Ore> ore);
#endif
};

#endif // OOP_FURNACE_HPP
