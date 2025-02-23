//
// Created by User on 2024/10/29.
//

#include "Package.hpp"

Package::Package() {}
void Package::CountMoney() {
    if (sidedish) {
        money += sidedish->GetMoney();
    }
    if (maindish) {
        money += maindish->GetMoney();
    }
    if (drink) {
        money += drink->GetMoney();
    }
    if (sidedish && maindish && drink) {
        money -= 15;
    }
}
void Package::SetMainDish(MainDish maindish) {
    this->maindish = std::make_shared<MainDish>(maindish);
}
void Package::SetSideDish(SideDish sidedish) {
    this->sidedish = std::make_shared<SideDish>(sidedish);
}
void Package::SetDrink(Drink drink) {
    this->drink = std::make_shared<Drink>(drink);
}
int Package::GetMoney() {
    return money;
}
