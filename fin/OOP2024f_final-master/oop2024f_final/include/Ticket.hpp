//
// Created by User on 2024/12/27.
//

#ifndef TICKET_HPP
#define TICKET_HPP

#include "Account.hpp"
#include "Money.hpp"
#include <memory>
#include <string>
namespace Ticket {

enum class TicketType {
    Deposits,
    Loan,
    Cheque,
};

struct Info {
    std::string drawer;
    std::string payee;
    int amount;
    double rate;
    MoneyType moneyType;
    TicketType ticketType;
};

class ITimely {
public:
    virtual std::string GetTime() = 0;
};

class Ticket {
protected:
    Info ticketinfo;

public:
    Ticket(Info info); //
    virtual ~Ticket() = default;

    virtual Info GetTicketInfo() = 0;
};

}; // namespace Ticket
#endif
