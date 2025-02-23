//
// Created by 黃漢軒 on 2023/10/30.
//

#include <stdexcept>
#include <string>

#include "Alcohol.h"

std::string Alcohol::GetType() {
    return this->type;
}
int Alcohol::GetAlcoholContent() {
    return alcoholContent;
}
int Alcohol::GetPrice() {
    return price;
}
std::vector<std::string> Alcohol::GetTopping() {
    return toppings;
}

void Alcohol::SetAlcoholContent(int alcoholContent) {
    if (alcoholContent > 100) {
        throw std::invalid_argument("out of range");
    }
    this->alcoholContent = alcoholContent;
}
int Alcohol::GetQuality() {
    int b = 0;
    if (type == "Shot") {
        b = 7;
    } else if (type == "Cocktail") {
        b = 10;
    } else if (type == "Beer") {
        b = 8;
    }
    int qs = 0;
    int ts = toppings.empty() ? 5 : 10;
    int ps = price / 100 * 10;
    return 30 * b + 25 * alcoholContent + 20 * ts + 25 * ps;
}
