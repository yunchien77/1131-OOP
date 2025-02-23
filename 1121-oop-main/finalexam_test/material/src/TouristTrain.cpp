//
// Created by sigtu on 1/2/2024.
//
#include "TouristTrain.hpp"

TouristTrain::TouristTrain(std::shared_ptr<TrainInfo> trainInfo,
                           std::shared_ptr<EnergyInfo> energyInfo)
    : Train(trainInfo, energyInfo) {}

ReserveTicketInfo TouristTrain::Reserve(int startStationIndex,
                                        int endStationIndex) {
    return ReserveTicketInfo(startStationIndex, endStationIndex,
                             GetTrainInfo());
}