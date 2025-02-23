//
// Created by 黃漢軒 on 2023/10/30.
//

#ifndef OOP_ALCOHOL_H
#define OOP_ALCOHOL_H

#include <string>

class Alcohol {
protected:
    std::string type;
    int price;
    int alcoholContent;
    std::vector<std::string> toppings;

public:
    std::string GetType();
    int GetAlcoholContent();
    int GetPrice();
    std::vector<std::string> GetTopping();

    void SetAlcoholContent(int alcoholContent);
    int GetQuality();
};

#endif // OOP_ALCOHOL_H
