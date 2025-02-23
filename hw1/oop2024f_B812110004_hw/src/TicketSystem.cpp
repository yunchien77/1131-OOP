#include "TicketSystem.hpp"

// 回傳每個 ticket 的票價為多少
int CheckTicketPrice(Order ticket) {
    if (ticket.quantity <= 0) {
        throw std::invalid_argument("Quantity must be positive");
    }

    int basePrice;
    switch (ticket.type) {
    case TicketType::Adult:
        basePrice = 350;
        break;
    case TicketType::Child:
        basePrice = 280;
        break;
    case TicketType::Elder:
        basePrice = 240;
        break;
    }

    int totalPrice = basePrice * ticket.quantity;
    if (ticket.quantity >= 10) {
        totalPrice = totalPrice * 0.8; // 20% discount
    }

    return totalPrice;
}

// 計算今日總共賣出多少金額的電影票
int CheckTodaySales(std::vector<Order> tickets) {
    int totalSales = 0;
    for (const auto &ticket : tickets) {
        totalSales += CheckTicketPrice(ticket);
    }
    return totalSales;
}

// 計算今日總共賣出多少電影票
int CheckTodayTicketSales(std::vector<Order> tickets) {
    int totalTickets = 0;
    for (const auto &ticket : tickets) {
        if (ticket.quantity < 0) {
            throw std::invalid_argument("Quantity can't < 0.");
        }
        totalTickets += ticket.quantity;
    }
    return totalTickets;
}

// 計算今日售出特定類別電影票銷售額
int CheckSpecificTicketSales(TicketType type, std::vector<Order> tickets) {
    int speSales = 0;
    for (const auto &ticket : tickets) {
        if (ticket.type == type) {
            speSales += CheckTicketPrice(ticket);
        }
    }
    return speSales;
}

// 計算特定的訂單價格
int CheckSpecificOrdersTicketPrice(int idx, std::vector<Order> tickets) {
    if (idx < 0 || idx >= tickets.size()) {
        throw std::invalid_argument("Invalid index");
    }
    return CheckTicketPrice(tickets[idx]);
}

/*
#include "TicketSystem.hpp"

int CheckTicketPrice(Order ticket) {
    if (ticket.quantity <= 0) {
        throw std::invalid_argument("Quantity must be positive");
    }

    int basePrice;
    if (ticket.type == TicketType::Adult) {
        basePrice = 350;
    } else if (ticket.type == TicketType::Child) {
        basePrice = 280;
    } else if (ticket.type == TicketType::Elder) {
        basePrice = 240;
    }

    int totalPrice = basePrice * ticket.quantity;
    if (ticket.quantity >= 10) {
        totalPrice = (int)(totalPrice * 0.8);  // 20% discount
    }

    return totalPrice;
}

int CheckTodaySales(std::vector<Order> tickets) {
    int totalSales = 0;
    for (int i = 0; i < tickets.size(); i++) {
        totalSales += CheckTicketPrice(tickets[i]);
    }
    return totalSales;
}

int CheckTodayTicketSales(std::vector<Order> tickets) {
    int totalTickets = 0;
    for (int i = 0; i < tickets.size(); i++) {
        totalTickets += tickets[i].quantity;
    }
    return totalTickets;
}

int CheckSpecificTicketSales(TicketType type, std::vector<Order> tickets) {
    int totalSales = 0;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i].type == type) {
            totalSales += CheckTicketPrice(tickets[i]);
        }
    }
    return totalSales;
}

int CheckSpecificOrdersTicketPrice(int idx, std::vector<Order> tickets) {
    if (idx < 0 || idx >= tickets.size()) {
        throw std::invalid_argument("Invalid index");
    }
    return CheckTicketPrice(tickets[idx]);
}
*/