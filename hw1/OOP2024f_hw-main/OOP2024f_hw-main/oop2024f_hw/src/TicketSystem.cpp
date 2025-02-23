#include "TicketSystem.hpp"
#include <iostream>
#include <stdexcept>

int CheckTicketPrice(Order ticket) {
    if (ticket.quantity <= 0) {
        throw std::invalid_argument("quantity not in the range");
    }
    int basePrice = 0;
    switch (ticket.type) {
    case TicketType::Adult:
        basePrice = 350 * ticket.quantity;
        break;
    case TicketType::Child:
        basePrice = 280 * ticket.quantity;
        break;
    case TicketType::Elder:
        basePrice = 240 * ticket.quantity;
        break;
    default:
        throw std::invalid_argument("no type");
    }
    if (ticket.quantity >= 10) {
        // std::cout << "get a discount" << basePrice << std::endl;
        basePrice = basePrice * 0.8;
        // std::cout << "get a discount" << basePrice << std::endl;
    }
    return basePrice;
}
int CheckTodaySales(std::vector<Order> tickets) {
    int todayPrice = 0;
    for (int i = 0; i < tickets.size(); i++) {
        todayPrice += CheckTicketPrice(tickets[i]);
    }
    return todayPrice;
}
int CheckTodayTicketSales(std::vector<Order> tickets) {
    int todayQuantity = 0;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i].quantity <= 0) {
            throw std::invalid_argument("quantity not in the range");
        }
        todayQuantity += tickets[i].quantity;
    }
    return todayQuantity;
}
int CheckSpecificTicketSales(TicketType type, std::vector<Order> tickets) {
    int specificPrice = 0;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i].type == type) {
            specificPrice += CheckTicketPrice(tickets[i]);
        }
    }
    return specificPrice;
}
int CheckSpecificOrdersTicketPrice(int idx, std::vector<Order> tickets) {
    if (idx >= tickets.size()) {
        throw std::invalid_argument("idx not in the range");
    }
    return CheckTicketPrice(tickets[idx]);
}
