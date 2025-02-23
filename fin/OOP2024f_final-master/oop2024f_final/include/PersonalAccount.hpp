//
// Created by User on 2024/12/27.
//

#ifndef OOP_PERSONALACCOUNT_HPP
#define OOP_PERSONALACCOUNT_HPP

#include "Account.hpp"
#include <stdexcept>

class PersonalAccount : public Account {
private:
    MoneyType moneytype;

public:
    PersonalAccount(std::string id, AccountType type,
                    MoneyType AccountMoneyType);
    MoneyType GetMoneyInfo();
    void Modify(Operation oper, MoneyType type, int amount) override;
};
#endif // OOP_PERSONALACCOUNT_HPP
