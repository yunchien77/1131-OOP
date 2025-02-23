

#include "Loan.hpp"

namespace Ticket {

Loan::Loan(Info info, std::string time)
    : Ticket(info),
      time(time) {}

Info Loan::GetTicketInfo() {
    return ticketinfo;
}

std::string Loan::GetTime() {
    return time;
}
} // namespace Ticket