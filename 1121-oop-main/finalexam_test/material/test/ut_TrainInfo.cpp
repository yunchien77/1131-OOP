//
// Created by sigtu on 1/2/2024.
//

#include <vector>
#include <gtest/gtest.h>
#include <memory>

#include "Train.hpp"

TEST(TrainInfo, TestTrainConstructorShouldHaveCorrectTrain){
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});

    ASSERT_EQ(trainInfo->GetName(), "ZhiChang");
    ASSERT_EQ(trainInfo->GetPricePerStation(), 75);
    ASSERT_EQ(trainInfo->GetSeat(), 45);
    ASSERT_EQ(trainInfo->GetTrain(), 8);
    ASSERT_EQ(trainInfo->GetStation(0), "Taipei");
}

TEST(TrainInfo, TestTrainReserveSeatShouldHaveCorrectReserveInfo){
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});

    ReserveInfo reserveInfo = trainInfo->ReserveSeat();
    ASSERT_EQ(reserveInfo.GetTrain(), 1);
    ASSERT_EQ(reserveInfo.GetSeat(), 1);
}

TEST(TrainInfo, TestTrainReserveSeatWithMultiplePollShouldHaveCorrectReserveInfo){
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 45; j++){
            trainInfo->ReserveSeat();
        }
    }
    ReserveInfo reserveInfo = trainInfo->ReserveSeat();
    ASSERT_EQ(reserveInfo.GetTrain(), 5);
    ASSERT_EQ(reserveInfo.GetSeat(), 1);
}