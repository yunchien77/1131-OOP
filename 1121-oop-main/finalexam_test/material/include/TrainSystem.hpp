//
// Created by 黃漢軒 on 2023/12/19.
//

#ifndef OOP_TRAINSYSTEM_HPP
#define OOP_TRAINSYSTEM_HPP

#include "Train.hpp"
#include <vector>

class TrainSystem {
private:
    std::vector<std::shared_ptr<Train>> trains;

public:
    TrainSystem(std::vector<std::shared_ptr<Train>> trains);
    int GetTotalDistance();
    int GetTotalArrivalTime();
    int GetSize();
    std::shared_ptr<Train> GetTrain(int index);
};

#endif // OOP_TRAINSYSTEM_HPP
