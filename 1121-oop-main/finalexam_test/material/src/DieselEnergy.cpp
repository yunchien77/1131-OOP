//
// Created by sigtu on 1/2/2024.
//

#include "DieselEnergy.hpp"
#include "EnergyInfo.hpp"

DieselEnergy::DieselEnergy(int energy)
    : EnergyInfo(energy) {}

int DieselEnergy::GetDistance() {
    return calculate.CalculateDieselDistance(GetEnergy());
}

int DieselEnergy::GetTerminalStationArrivalTimeInSecond() {
    return calculate.CalculateDieselArrivalTime(GetEnergy());
}
