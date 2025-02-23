//
// Created by 黃漢軒 on 2023/12/19.
//

#ifndef OOP_TICKETINFO_HPP
#define OOP_TICKETINFO_HPP

#include <memory>

#include "TrainInfo.hpp"

class TicketInfo {
private:
    std::shared_ptr<TrainInfo> trainInfo;

public:
    TicketInfo(std::shared_ptr<TrainInfo> trainInfo);
    std::shared_ptr<TrainInfo> GetTrainInfo();
    virtual int GetPrice();
};

#endif // OOP_TICKETINFO_HPP
