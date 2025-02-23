//
// Created by 黃漢軒 on 2024/1/5.
//

#include "ReserveInfo.hpp"

ReserveInfo::ReserveInfo(int train, int seat)
    : train(train),
      seat(seat) {}

int ReserveInfo::GetTrain() {
    return train;
}

int ReserveInfo::GetSeat() {
    return seat;
}