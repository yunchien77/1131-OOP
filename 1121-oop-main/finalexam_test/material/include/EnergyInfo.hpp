//
// Created by 黃漢軒 on 2023/12/19.
//

#ifndef OOP_ENERGYINFO_HPP
#define OOP_ENERGYINFO_HPP

#include "ICalculable.hpp"

class EnergyInfo : public ICalculable {
private:
    int energy;
    // int distance;
    // int time;

public:
    EnergyInfo(int energy);
    int GetEnergy();

    virtual int GetDistance() = 0;
    virtual int GetTerminalStationArrivalTimeInSecond() = 0;
};

#endif // OOP_ENERGYINFO_HPP
