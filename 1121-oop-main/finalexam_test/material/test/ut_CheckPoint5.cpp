//
// Created by sigtu on 1/2/2024.
//

#include "DieselEnergy.hpp"
#include "ElectricEnergy.hpp"
#include "ExpressTrain.hpp"
#include "LocalTrain.hpp"
#include "TouristTrain.hpp"
#include "TrainSystem.hpp"
#include <gtest/gtest.h>

TEST(CheckPoint5, TestTrainSystemConstructorShouldSetupTrainCorrectly) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<TrainInfo> anotherTrainInfo = std::make_shared<TrainInfo>(
        8, 45, 175, "Puyuma", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> electricEnergyInfo =
        std::make_shared<ElectricEnergy>(10);
    std::shared_ptr<EnergyInfo> dieselEnergyInfo =
        std::make_shared<DieselEnergy>(80);

    std::shared_ptr<Train> expressTrain =
        std::make_shared<ExpressTrain>(trainInfo, electricEnergyInfo);
    std::shared_ptr<Train> localTrain =
        std::make_shared<LocalTrain>(anotherTrainInfo, dieselEnergyInfo);
    std::shared_ptr<Train> touristTrain =
        std::make_shared<TouristTrain>(anotherTrainInfo, electricEnergyInfo);
    std::shared_ptr<Train> anotherTouristTrain =
        std::make_shared<TouristTrain>(trainInfo, electricEnergyInfo);

    TrainSystem trainSystem(
        {expressTrain, localTrain, touristTrain, anotherTouristTrain});
    ASSERT_EQ(trainSystem.GetSize(), 4);
}

TEST(CheckPoint5, TestTrainSystemGetTrainShouldReturnCorrectTrain) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<TrainInfo> anotherTrainInfo = std::make_shared<TrainInfo>(
        8, 45, 175, "Puyuma", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> electricEnergyInfo =
        std::make_shared<ElectricEnergy>(10);
    std::shared_ptr<EnergyInfo> dieselEnergyInfo =
        std::make_shared<DieselEnergy>(80);
    std::shared_ptr<Train> expressTrain =
        std::make_shared<ExpressTrain>(trainInfo, electricEnergyInfo);
    std::shared_ptr<Train> localTrain =
        std::make_shared<LocalTrain>(anotherTrainInfo, dieselEnergyInfo);
    std::shared_ptr<Train> touristTrain =
        std::make_shared<TouristTrain>(anotherTrainInfo, electricEnergyInfo);
    std::shared_ptr<Train> anotherTouristTrain =
        std::make_shared<TouristTrain>(trainInfo, electricEnergyInfo);

    TrainSystem trainSystem(
        {expressTrain, localTrain, touristTrain, anotherTouristTrain});

    std::shared_ptr<Train> queryTrain = trainSystem.GetTrain(2);
    ASSERT_EQ(queryTrain->GetTrainInfo()->GetTrain(), 8);
    ASSERT_EQ(queryTrain->GetTrainInfo()->GetSeat(), 45);
    ASSERT_EQ(queryTrain->GetTrainInfo()->GetPricePerStation(), 175);
    ASSERT_EQ(queryTrain->GetTrainInfo()->GetName(), "Puyuma");
    ASSERT_EQ(queryTrain->GetTrainInfo()->GetStation(1), "Tainan");
}

TEST(CheckPoint5,
     TestTrainSystemGetTotalArrivalTimeShouldReturnCorrectArrivalTime) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<TrainInfo> anotherTrainInfo = std::make_shared<TrainInfo>(
        8, 45, 175, "Puyuma", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> electricEnergyInfo =
        std::make_shared<ElectricEnergy>(10);
    std::shared_ptr<EnergyInfo> dieselEnergyInfo =
        std::make_shared<DieselEnergy>(80);
    std::shared_ptr<Train> expressTrain =
        std::make_shared<ExpressTrain>(trainInfo, electricEnergyInfo);
    std::shared_ptr<Train> localTrain =
        std::make_shared<LocalTrain>(anotherTrainInfo, dieselEnergyInfo);
    std::shared_ptr<Train> touristTrain =
        std::make_shared<TouristTrain>(anotherTrainInfo, electricEnergyInfo);
    std::shared_ptr<Train> anotherTouristTrain =
        std::make_shared<TouristTrain>(trainInfo, electricEnergyInfo);

    TrainSystem trainSystem(
        {expressTrain, localTrain, touristTrain, anotherTouristTrain});

    CalculateHelper calculateHelper;
    ASSERT_EQ(trainSystem.GetTotalArrivalTime(),
              calculateHelper.CalculateElectricArrivalTime(10) * 3 +
                  calculateHelper.CalculateDieselArrivalTime(80) * 1);
}

TEST(CheckPoint5,
     TestTrainSystemGetTotalDistanceShouldReturnCorrectArrivalTime) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<TrainInfo> anotherTrainInfo = std::make_shared<TrainInfo>(
        8, 45, 175, "Puyuma", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> electricEnergyInfo =
        std::make_shared<ElectricEnergy>(10);
    std::shared_ptr<EnergyInfo> dieselEnergyInfo =
        std::make_shared<DieselEnergy>(80);
    std::shared_ptr<Train> expressTrain =
        std::make_shared<ExpressTrain>(trainInfo, electricEnergyInfo);
    std::shared_ptr<Train> localTrain =
        std::make_shared<LocalTrain>(anotherTrainInfo, dieselEnergyInfo);
    std::shared_ptr<Train> touristTrain =
        std::make_shared<TouristTrain>(anotherTrainInfo, electricEnergyInfo);
    std::shared_ptr<Train> anotherTouristTrain =
        std::make_shared<TouristTrain>(trainInfo, electricEnergyInfo);

    TrainSystem trainSystem(
        {expressTrain, localTrain, touristTrain, anotherTouristTrain});

    CalculateHelper calculateHelper;
    ASSERT_EQ(trainSystem.GetTotalDistance(),
              calculateHelper.CalculateElectricDistance(10) * 3 +
                  calculateHelper.CalculateDieselDistance(80) * 1);
}
