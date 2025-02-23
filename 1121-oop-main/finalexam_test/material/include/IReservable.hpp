//
// Created by 黃漢軒 on 2023/12/17.
//

#ifndef OOP_IRESERVABLE_H
#define OOP_IRESERVABLE_H

#include "ReserveTicketInfo.hpp"

class IReservable {
public:
    virtual ReserveTicketInfo Reserve(int startStationIndex, int endStationIndex) = 0;
};

#endif // OOP_IRESERVABLE_H
