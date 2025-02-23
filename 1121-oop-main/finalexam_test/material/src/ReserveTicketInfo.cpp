//
// Created by 黃漢軒 on 2024/1/5.
//
#include "ReserveTicketInfo.hpp"
#include "ReserveInfo.hpp"
#include "TicketInfo.hpp"
#include "TrainInfo.hpp"

ReserveTicketInfo::ReserveTicketInfo(int startStationIndex, int endStationIndex,
                                     std::shared_ptr<TrainInfo> trainInfo)
    : TicketInfo(trainInfo),
      startStationIndex(startStationIndex),
      endStationIndex(endStationIndex),
      reserveInfo(trainInfo->ReserveSeat()) {}

std::string ReserveTicketInfo::GetStartStation() {
    return GetTrainInfo()->GetStation(startStationIndex);
}

std::string ReserveTicketInfo::GetEndStation() {
    return GetTrainInfo()->GetStation(endStationIndex);
}

int ReserveTicketInfo::GetPrice() {
    return (endStationIndex - startStationIndex) *
           GetTrainInfo()->GetPricePerStation();
}

ReserveInfo ReserveTicketInfo::GetReserveInfo() {
    return reserveInfo;
}