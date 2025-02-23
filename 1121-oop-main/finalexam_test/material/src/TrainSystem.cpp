//
// Created by sigtu on 1/2/2024.
//

#include "TrainSystem.hpp"

TrainSystem::TrainSystem(std::vector<std::shared_ptr<Train>> trains) {
    this->trains = trains;
}

int TrainSystem::GetTotalDistance() {
    int totalDis = 0;
    for (auto train : trains) {
        totalDis += train->GetEnergyInfo()->GetDistance();
    }
    return totalDis;
}

int TrainSystem::GetTotalArrivalTime() {
    int totalT = 0;
    for (auto train : trains) {
        totalT +=
            train->GetEnergyInfo()->GetTerminalStationArrivalTimeInSecond();
    }
    return totalT;
}

int TrainSystem::GetSize() {
    return trains.size();
}

std::shared_ptr<Train> TrainSystem::GetTrain(int index) {
    return trains[index];
}