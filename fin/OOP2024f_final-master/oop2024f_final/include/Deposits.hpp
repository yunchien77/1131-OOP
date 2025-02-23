#ifndef DEPOSIT_HPP
#define DEPOSIT_HPP

#include "Ticket.hpp"

namespace Ticket {

class Deposits : public Ticket, public ITimely {
private:
    std::string time = "";

public:
    Deposits(Info info, std::string time);
    Info GetTicketInfo() override;
    std::string GetTime() override;
};

} // namespace Ticket

#endif