//
// Created by sigtu on 1/2/2024.
//

#include "LocalTrain.hpp"
#include "TicketInfo.hpp"
#include "Train.hpp"

LocalTrain::LocalTrain(std::shared_ptr<TrainInfo> trainInfo,
                       std::shared_ptr<EnergyInfo> energyInfo)
    : Train(trainInfo, energyInfo) {}

TicketInfo LocalTrain::GetTicket() {
    return TicketInfo(GetTrainInfo());
}