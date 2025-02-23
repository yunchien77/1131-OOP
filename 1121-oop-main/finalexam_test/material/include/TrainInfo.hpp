//
// Created by 黃漢軒 on 2023/12/18.
//

#ifndef OOP_TRAININFO_HPP
#define OOP_TRAININFO_HPP

#include "ReserveInfo.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class TrainInfo {
private:
    int seat;
    int train;
    int pricePerStation;
    std::string name;
    std::vector<std::string> station;
    int currentBookingTrain = 1;
    int currentBookingSeat = 1;

public:
    TrainInfo(int train, int seat, int pricePerStation, std::string name,
              std::vector<std::string> station) {
        this->train = train;
        this->seat = seat;
        this->pricePerStation = pricePerStation;
        this->station = station;
        this->name = name;
    }

    int GetSeat() { return seat; }

    int GetTrain() { return train; }

    std::string GetName() { return name; }

    int GetPricePerStation() { return pricePerStation; }

    std::string GetStation(unsigned int index) {
        if (index >= station.size()) {
            throw std::invalid_argument("Out of bound.");
        }
        return station[index];
    }

    ReserveInfo ReserveSeat() {

        if (currentBookingTrain > train) {
            throw std::invalid_argument("No enough seat!");
        }

        int reserveTrain = currentBookingTrain;
        int reserveSeat = currentBookingSeat;

        currentBookingSeat += 1;
        currentBookingTrain += currentBookingSeat / seat;
        currentBookingSeat %= seat;

        // std::cout << reserveSeat << ", " << reserveTrain << std::endl;
        // std::cout << train << ",, " << seat << std::endl;

        return ReserveInfo(reserveTrain, reserveSeat);
    };
};

#endif // OOP_TRAININFO_HPP