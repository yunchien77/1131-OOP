

#include <Order.hpp>

Order::Order(std::vector<Production> product,
             std::vector<Ingredients> addtional, std::vector<bool> larger) {
    this->addtional = addtional;
    this->product = product;
    this->larger = larger;
}

// Order::Order(std::vector<Production> product,
//             std::vector<Ingredients> additional,
//             std::vector<bool> larger)
//     : product(product), addtional(additional), larger(larger) {}

std::vector<Production> Order::GetProductInfo() {
    return product;
}
std::vector<Ingredients> Order::GetAddtionalInfo() {
    return addtional;
}
std::vector<bool> Order::GetLargerInfo() {
    return larger;
}