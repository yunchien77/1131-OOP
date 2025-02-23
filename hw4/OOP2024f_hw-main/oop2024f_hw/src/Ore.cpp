//
// Created by adven on 11/28/2024.
//

#include "Ore.hpp"

Ore::Ore(Product pro)
    : exp(0),
      product(pro) {
    // this->product = pro;
    // exp = 0;
}

Product Ore::GetProduct() const {
    return product;
}