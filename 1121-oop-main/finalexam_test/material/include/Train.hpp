//
// Created by 黃漢軒 on 2023/12/19.
//

#ifndef OOP_TRAIN_HPP
#define OOP_TRAIN_HPP

#include "EnergyInfo.hpp"
#include "TrainInfo.hpp"
#include <memory>

class Train {
private:
    std::shared_ptr<TrainInfo> trainInfo;
    std::shared_ptr<EnergyInfo> energyInfo;

public:
    Train(std::shared_ptr<TrainInfo> trainInfo,
          std::shared_ptr<EnergyInfo> energyInfo);
    std::shared_ptr<TrainInfo> GetTrainInfo();
    std::shared_ptr<EnergyInfo> GetEnergyInfo();
};

#endif // OOP_TRAIN_HPP
