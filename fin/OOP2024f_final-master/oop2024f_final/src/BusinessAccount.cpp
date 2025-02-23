#include "BusinessAccount.hpp"
#include "Account.hpp"
#include "Money.hpp"
#include <cmath>
#include <stdexcept>

BusinessAccount::BusinessAccount(std::string id, AccountType type)
    : Account(id, type) {}

void BusinessAccount::Modify(Operation oper, MoneyType type, int amount) {
    if (oper == Operation::Deposit) {
        if (type == MoneyType::TWP) {
            money += (amount * 8);
        } else if (type == MoneyType::OOTD) {
            money += (amount * 4);
        } else if (type == MoneyType::PUA) {
            money += (amount * 6);
        } else if (type == MoneyType::FS) {
            money += (amount * 2);
        } else if (type == MoneyType::OOP) {
            money += amount;
        }

    } else if (oper == Operation::Withdraw) {
        if (amount > money) {
            throw std::out_of_range("amount > money");
        }
        if (type == MoneyType::TWP) {
            money -= std::floor(amount / 8);
        } else if (type == MoneyType::OOTD) {
            money -= std::floor(amount / 4);
        } else if (type == MoneyType::PUA) {
            money -= std::floor(amount / 6);
        } else if (type == MoneyType::FS) {
            money -= std::floor(amount * 2);
        } else if (type == MoneyType::OOP) {
            money -= amount;
        }
    }
}
