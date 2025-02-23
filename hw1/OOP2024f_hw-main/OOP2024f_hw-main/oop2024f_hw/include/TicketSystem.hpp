#ifndef Ticket_System_HPP
#define Ticket_System_HPP

#include <stdexcept>
#include <string>
#include <vector>

enum class TicketType {
    Adult,
    Child,
    Elder,
};

struct Order {
    TicketType type; // 訂單資訊
    int quantity;    // 訂單張數
};

int CheckTicketPrice(Order ticket);
int CheckTodaySales(std::vector<Order> tickets);
int CheckTodayTicketSales(std::vector<Order> tickets);
int CheckSpecificTicketSales(TicketType type, std::vector<Order> tickets);
int CheckSpecificOrdersTicketPrice(int idx, std::vector<Order> tickets);

#endif
