#ifndef LOAN_HPP
#define LOAN_HPP

#include "Ticket.hpp"

namespace Ticket {

class Loan : public Ticket, public ITimely {
private:
    std::string time = "";

public:
    Loan(Info info, std::string time);
    Info GetTicketInfo() override;
    std::string GetTime() override;
};

} // namespace Ticket

#endif