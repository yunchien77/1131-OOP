//
// Created by 黃漢軒 on 2023/12/18.
//

#ifndef OOP_DIESELENERGY_HPP
#define OOP_DIESELENERGY_HPP

#include "CalculateHelper.hpp"
#include "EnergyInfo.hpp"
#include "ICalculable.hpp"

class DieselEnergy : public EnergyInfo {
private:
    CalculateHelper calculate;

public:
    DieselEnergy(int energy);
    int GetDistance() override;
    int GetTerminalStationArrivalTimeInSecond() override;
};

#endif // OOP_DIESELENERGY_HPP
