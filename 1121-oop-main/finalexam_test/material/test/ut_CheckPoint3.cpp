#include <gtest/gtest.h>
#include <memory>
#include <vector>

#include "DieselEnergy.hpp"
#include "Train.hpp"

TEST(CheckPoint3, TestTrainConstructorShouldHaveCorrectTrain) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<DieselEnergy>(450);

    Train train(trainInfo, energyInfo);

    ASSERT_EQ(train.GetTrainInfo()->GetName(), "ZhiChang");
    ASSERT_EQ(train.GetTrainInfo()->GetPricePerStation(), 75);
    ASSERT_EQ(train.GetTrainInfo()->GetSeat(), 45);
    ASSERT_EQ(train.GetTrainInfo()->GetTrain(), 8);
    ASSERT_EQ(train.GetTrainInfo()->GetStation(0), "Taipei");
    ASSERT_EQ(train.GetEnergyInfo()->GetEnergy(), 450);
}

TEST(CheckPoint3, TestTrainReserveSeatShouldHaveCorrectReserveInfo) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<DieselEnergy>(450);
    Train train(trainInfo, energyInfo);

    ReserveInfo reserveInfo = train.GetTrainInfo()->ReserveSeat();

    ASSERT_EQ(reserveInfo.GetTrain(), 1);
    ASSERT_EQ(reserveInfo.GetSeat(), 1);
}

TEST(CheckPoint3,
     TestTrainReserveSeatWithMultiplePollShouldHaveCorrectReserveInfo) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<DieselEnergy>(450);
    Train train(trainInfo, energyInfo);
    for (int i = 0; i < 7 * 45; i++) {
        trainInfo->ReserveSeat();
    }

    ReserveInfo reserveInfo = train.GetTrainInfo()->ReserveSeat();

    ASSERT_EQ(reserveInfo.GetTrain(), 8);
    ASSERT_EQ(reserveInfo.GetSeat(), 1);
}

TEST(CheckPoint3, TestTrainGetArrivalTimeShouldHaveCorrectArrivalTime) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<DieselEnergy>(450);
    Train train(trainInfo, energyInfo);

    CalculateHelper calculateHelper;
    ASSERT_EQ(train.GetEnergyInfo()->GetTerminalStationArrivalTimeInSecond(),
              calculateHelper.CalculateDieselArrivalTime(450));
}

TEST(CheckPoint3, TestTrainGetDistanceShouldHaveCorrectDistance) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<DieselEnergy>(450);
    Train train(trainInfo, energyInfo);

    CalculateHelper calculateHelper;
    ASSERT_EQ(train.GetEnergyInfo()->GetDistance(),
              calculateHelper.CalculateDieselDistance(450));
}