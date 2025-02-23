//
// Created by adven on 11/28/2024.
//

#include "Furnace.hpp"
#include "Config.hpp"

void Furnace::AddIronOre(std::shared_ptr<IronOre> ore) {
    // 檢查礦物數量是否超過64個
    if (m_SmeltableOres.size() >= 64) {
        throw std::invalid_argument("Furnace cannot hold more than 64 ores");
    }

    // 檢查是否可以添加該類型的礦物
    if (m_IsSmeltingStarted && m_CurrentSmeltingType != Product::Iron) {
        throw std::invalid_argument(
            "Cannot add different type of ore while smelting");
    }

    m_SmeltableOres.push_back(ore);
    m_CurrentSmeltingType = Product::Iron;
    m_IsSmeltingStarted = true;
}

void Furnace::AddGoldOre(std::shared_ptr<GoldOre> ore) {
    // 檢查礦物數量是否超過64個
    if (m_SmeltableOres.size() >= 64) {
        throw std::invalid_argument("Furnace cannot hold more than 64 ores");
    }

    // 檢查是否可以添加該類型的礦物
    if (m_IsSmeltingStarted && m_CurrentSmeltingType != Product::Gold) {
        throw std::invalid_argument(
            "Cannot add different type of ore while smelting");
    }

    m_SmeltableOres.push_back(ore);
    m_CurrentSmeltingType = Product::Gold;
    m_IsSmeltingStarted = true;
}

std::vector<Product> Furnace::PickupProduct() {
    // 若沒有礦物在熔爐中，返回空列表
    if (m_SmeltableOres.empty()) {
        return {};
    }

    // 清空產物列表
    std::vector<Product> products;

    // 根據礦物數量生成對應數量的產物
    for (const auto &ore : m_SmeltableOres) {
        products.push_back(ore->GetProduct());
    }

    // 清空熔爐中的礦物
    m_SmeltableOres.clear();
    m_IsSmeltingStarted = false;

    return products;
}

#if TESTING_TARGET2
void Furnace::AddOre(std::shared_ptr<SmeltableOre> ore) {
    // 檢查礦物數量是否超過64個
    if (m_SmeltableOres.size() >= 64) {
        throw std::invalid_argument("Furnace cannot hold more than 64 ores");
    }

    // 檢查是否可以添加該類型的礦物
    if (m_IsSmeltingStarted && m_CurrentSmeltingType != ore->GetProduct()) {
        throw std::invalid_argument(
            "Cannot add different type of ore while smelting");
    }

    m_SmeltableOres.push_back(ore);
    m_CurrentSmeltingType = ore->GetProduct();
    m_IsSmeltingStarted = true;
}
#endif

#if TESTING_TARGET3
void Furnace::AddAnyOre(std::shared_ptr<Ore> ore) {
    // 嘗試將任意Ore轉換為SmeltableOre
    auto smeltableOre = std::dynamic_pointer_cast<SmeltableOre>(ore);

    // 若不是可熔煉的礦物，抛出異常
    if (!smeltableOre) {
        throw std::invalid_argument(
            "Only smeltable ores can be added to the furnace");
    }

    // 檢查礦物數量是否超過64個
    if (m_SmeltableOres.size() >= 64) {
        throw std::invalid_argument("Furnace cannot hold more than 64 ores");
    }

    // 檢查是否可以添加該類型的礦物
    if (m_IsSmeltingStarted &&
        m_CurrentSmeltingType != smeltableOre->GetProduct()) {
        throw std::invalid_argument(
            "Cannot add different type of ore while smelting");
    }

    m_SmeltableOres.push_back(smeltableOre);
    m_CurrentSmeltingType = smeltableOre->GetProduct();
    m_IsSmeltingStarted = true;
}
#endif
