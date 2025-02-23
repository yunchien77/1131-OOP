//
// Created by adven on 11/28/2024.
//

#include "Furnace.hpp"
#include "Config.hpp"
#include "Product.hpp"
#include "SmeltableOre.hpp"
#include <stdexcept>

void Furnace::AddIronOre(std::shared_ptr<IronOre> ore) {
    if (m_SmeltableOres.size() >= 64) {
        throw std::invalid_argument("a");
    }
    if (m_IsSmeltingStarted && m_CurrentSmeltingType != Product::Iron) {
        throw std::invalid_argument("c");
    }
    m_SmeltableOres.push_back(ore);
    m_CurrentSmeltingType = Product::Iron;
    m_IsSmeltingStarted = true;
    // std::cout << productToString(m_CurrentSmeltingType);
}

void Furnace::AddGoldOre(std::shared_ptr<GoldOre> ore) {
    std::cout << "AddGoldOre";
    if (m_SmeltableOres.size() >= 64) {
        throw std::invalid_argument("b");
    }
    // std::cout << "hh" << productToString(m_CurrentSmeltingType);
    if (m_IsSmeltingStarted && m_CurrentSmeltingType != Product::Gold) {
        throw std::invalid_argument("d");
    }
    m_SmeltableOres.push_back(ore);
    m_CurrentSmeltingType = Product::Gold;
    m_IsSmeltingStarted = true;
    // std::cout << productToString(m_CurrentSmeltingType);
}

std::vector<Product> Furnace::PickupProduct() {
    std::vector<Product> products;
    for (const auto &ore : m_SmeltableOres) {
        products.push_back(ore->GetProduct());
    }
    m_SmeltableOres.clear(); // 清空所有礦物
    m_IsSmeltingStarted = false;
    return products;
}

#if TESTING_TARGET2

void Furnace::AddOre(std::shared_ptr<SmeltableOre> ore) {
    if (m_SmeltableOres.size() >= 64) {
        throw std::invalid_argument("a");
    }
    if (m_IsSmeltingStarted && m_CurrentSmeltingType != ore->getProduct()) {
        throw std::invalid_argument("c");
    }
    m_SmeltableOres.push_back(ore);
    m_CurrentSmeltingType = ore->getProduct();
    m_IsSmeltingStarted = true;
}

#endif
#if TESTING_TARGET3

void Furnace::AddAnyOre(std::shared_ptr<Ore> ore) {}
#endif
