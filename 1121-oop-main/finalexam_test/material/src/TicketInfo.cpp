//
// Created by 黃漢軒 on 2024/1/5.
//
#include "TicketInfo.hpp"
TicketInfo::TicketInfo(std::shared_ptr<TrainInfo> trainInfo)
    : trainInfo(trainInfo) {}

std::shared_ptr<TrainInfo> TicketInfo::GetTrainInfo() {
    return trainInfo;
}

int TicketInfo::GetPrice() {
    return trainInfo->GetPricePerStation();
}
