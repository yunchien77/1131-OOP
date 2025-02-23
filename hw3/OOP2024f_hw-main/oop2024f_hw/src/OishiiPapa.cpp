#include "OishiiPapa.hpp"

OishiiPapa::OishiiPapa() {}
void OishiiPapa::MakeDish() {
    if (chest.size() >= 15) {
        return;
    }
    if (pipeline.empty()) {
        throw std::out_of_range("No orders in pipeline");
    }

    Order order = pipeline.front();
    pipeline.pop();

    Package package;
    std::vector<Production> products = order.GetProductInfo();
    std::vector<Ingredients> addtionals = order.GetAddtionalInfo();
    std::vector<bool> large = order.GetLargerInfo();

    // 主餐
    if (products[0] != Production::_NULL) {
        MainDish main(products[0]);
        if (!addtionals.empty()) {
            main.AddIngredients(addtionals);
        }
        package.SetMainDish(main);
    }
    // 附餐
    if (products[1] != Production::_NULL) {
        SideDish side(products[1]);
        if (large[0]) {
            side.MakeLarger();
        }
        package.SetSideDish(side);
    }
    // 飲料
    if (products[2] != Production::_NULL) {
        Drink drink(products[2]);
        if (large[1]) {
            drink.MakeLarger();
        }
        package.SetDrink(drink);
    }
    package.CountMoney();
    chest.push(package);
}
Package OishiiPapa::Pickup() {
    if (chest.size() < 15 && !pipeline.empty()) {
        MakeDish();
    }

    if (chest.empty()) {
        throw std::out_of_range("No packages in chest");
    }

    Package package = chest.front();
    chest.pop();

    money += package.GetMoney();
    // std::cout << "kkkk: " << package.GetMoney() << std::endl;
    return package;
}
int OishiiPapa::GetMoney() {
    return money;
}
Order OishiiPapa::GetOrderInfo() {
    return pipeline.front();
}
void OishiiPapa::SendOrder(Order order) {
    pipeline.push(order);
}
