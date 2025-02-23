//
// Created by 黃漢軒 on 2023/12/18.
//

#ifndef OOP_EXPRESSTRAIN_HPP
#define OOP_EXPRESSTRAIN_HPP

#include "IReservable.hpp"
#include "ReserveTicketInfo.hpp"
#include "Train.hpp"

class ExpressTrain : public Train, public IReservable {
public:
    ExpressTrain(std::shared_ptr<TrainInfo> trainInfo,
                 std::shared_ptr<EnergyInfo> energyInfo);
    ReserveTicketInfo Reserve(int startStationIndex,
                              int endStationIndex) override;
};

#endif // OOP_EXPRESSTRAIN_HPP
