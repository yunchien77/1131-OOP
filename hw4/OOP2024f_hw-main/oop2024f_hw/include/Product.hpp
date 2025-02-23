//
// Created by 陳世昂 on 2024/11/24.
//

#ifndef OOP_PRODUCT_HPP
#define OOP_PRODUCT_HPP
#include <iostream>
enum class Product { Iron, Gold, Coal, Diamond };

inline std::string productToString(Product product) {
    switch (product) {
    case Product::Iron:
        return "Iron";
    case Product::Gold:
        return "Gold";
    case Product::Coal:
        return "Coal";
    case Product::Diamond:
        return "Diamond";
    default:
        return "Unknown";
    }
}

#endif // OOP_PRODUCT_HPP
