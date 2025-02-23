//
// Created by User on 2024/12/27.
//

#include "PersonalAccount.hpp"
#include "Account.hpp"
#include <stdexcept>

PersonalAccount::PersonalAccount(std::string id, AccountType type,
                                 MoneyType AccountMoneyType)
    : Account(id, type),
      moneytype(AccountMoneyType) {}

MoneyType PersonalAccount::GetMoneyInfo() {
    return moneytype;
}

void PersonalAccount::Modify(Operation oper, MoneyType type, int amount) {
    if (type != moneytype) {
        throw std::invalid_argument("type not same");
    }
    if (oper == Operation::Deposit) {
        money += amount;
    } else if (oper == Operation::Withdraw) {
        // if (amount > GetTotal()) {
        //     throw std::out_of_range("amount out of range");
        // }
        if (amount > money) {
            throw std::out_of_range("amount out of range");
        }
        money -= amount;
    }
}