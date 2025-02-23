
#include "Deposits.hpp"

namespace Ticket {

Deposits::Deposits(Info info, std::string time)
    : Ticket(info),
      time(time) {}

Info Deposits::GetTicketInfo() {
    return ticketinfo;
}

std::string Deposits::GetTime() {
    return time;
}

} // namespace Ticket