//
// Created by 黃漢軒 on 2023/12/18.
//

#ifndef OOP_LOCALTRAIN_HPP
#define OOP_LOCALTRAIN_HPP

#include "IReservable.hpp"
#include "TicketInfo.hpp"
#include "Train.hpp"

class LocalTrain : public Train {
public:
    LocalTrain(std::shared_ptr<TrainInfo> trainInfo,
               std::shared_ptr<EnergyInfo> energyInfo);
    TicketInfo GetTicket();
};

#endif // OOP_LOCALTRAIN_HPP
