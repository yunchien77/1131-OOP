#include "EnergyInfo.hpp"

EnergyInfo::EnergyInfo(int energy)
    : energy(energy) {}

int EnergyInfo::GetEnergy() {
    return energy;
}
// int EnergyInfo::GetDistance() {
//     return distance;
// }
// int EnergyInfo::GetTerminalStationArrivalTimeInSecond() {
//     return time;
// }