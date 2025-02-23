#include "Train.hpp"
#include "EnergyInfo.hpp"
#include "TrainInfo.hpp"

Train::Train(std::shared_ptr<TrainInfo> trainInfo,
             std::shared_ptr<EnergyInfo> energyInfo)
    : trainInfo(trainInfo),
      energyInfo(energyInfo) {}

std::shared_ptr<TrainInfo> Train::GetTrainInfo() {
    return trainInfo;
}

std::shared_ptr<EnergyInfo> Train::GetEnergyInfo() {
    return energyInfo;
}