//
// Created by adven on 11/28/2024.
//

#include "Ore.hpp"

Ore::Ore(Product pro) {
    this->pro = pro;
    this->exp = 0;
}

Product Ore::GetProduct() const {
    return pro;
}