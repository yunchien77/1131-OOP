//
// Created by 黃漢軒 on 2023/12/19.
//

#ifndef OOP_RESERVETICKETINFO_HPP
#define OOP_RESERVETICKETINFO_HPP

#include "ReserveInfo.hpp"
#include "TicketInfo.hpp"
#include "TrainInfo.hpp"

class ReserveTicketInfo : public TicketInfo {
private:
    int startStationIndex;
    int endStationIndex;
    ReserveInfo reserveInfo;

public:
    ReserveTicketInfo(int startStationIndex, int endStationIndex,
                      std::shared_ptr<TrainInfo> trainInfo);
    std::string GetStartStation();
    std::string GetEndStation();
    int GetPrice() override;
    ReserveInfo GetReserveInfo();
};
#endif // OOP_RESERVETICKETINFO_HPP
