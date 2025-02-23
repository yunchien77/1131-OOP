//
// Created by sigtu on 1/2/2024.
//

#include "ExpressTrain.hpp"

ExpressTrain::ExpressTrain(std::shared_ptr<TrainInfo> trainInfo,
                           std::shared_ptr<EnergyInfo> energyInfo)
    : Train(trainInfo, energyInfo) {}

ReserveTicketInfo ExpressTrain::Reserve(int startStationIndex,
                                        int endStationIndex) {
    return ReserveTicketInfo(startStationIndex, endStationIndex,
                             GetTrainInfo());
}