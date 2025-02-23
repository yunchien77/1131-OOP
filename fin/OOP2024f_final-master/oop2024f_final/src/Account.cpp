
#include "Account.hpp"

Account::Account(std::string id, AccountType type)
    : id(id),
      type(type) {}

int Account::GetTotal() {
    return money;
}

std::string Account::GetUser() {
    return id;
}

AccountType Account::GetAccountInfo() {
    return type;
}
