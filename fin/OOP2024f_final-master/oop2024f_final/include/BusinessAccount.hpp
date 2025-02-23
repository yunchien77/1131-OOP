#ifndef BUSINESS_ACCOUNT_HPP
#define BUSINESS_ACCOUNT_HPP

#include "Account.hpp"
#include <stdexcept>
#include <vector>

class BusinessAccount : public Account {
private:
public:
    BusinessAccount(std::string id, AccountType type);
    void Modify(Operation oper, MoneyType type, int amount) override;
};

#endif