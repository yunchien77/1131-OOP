
#include "Cheque.hpp"

namespace Ticket {
Cheque::Cheque(Info info)
    : Ticket(info) {}

Info Cheque::GetTicketInfo() {
    return ticketinfo;
}

} // namespace Ticket