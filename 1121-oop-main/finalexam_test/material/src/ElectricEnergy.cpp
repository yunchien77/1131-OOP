//
// Created by sigtu on 1/2/2024.
//
#include "ElectricEnergy.hpp"

ElectricEnergy::ElectricEnergy(int energy)
    : EnergyInfo(energy) {}

int ElectricEnergy::GetDistance() {
    return calculate.CalculateElectricDistance(GetEnergy());
}

int ElectricEnergy::GetTerminalStationArrivalTimeInSecond() {
    return calculate.CalculateElectricArrivalTime(GetEnergy());
}
