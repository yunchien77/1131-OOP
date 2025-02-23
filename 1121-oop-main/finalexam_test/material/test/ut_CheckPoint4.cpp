#include <gtest/gtest.h>
#include <memory>
#include <vector>

#include "DieselEnergy.hpp"
#include "ElectricEnergy.hpp"
#include "ExpressTrain.hpp"
#include "LocalTrain.hpp"
#include "TouristTrain.hpp"

TEST(CheckPoint4, TestLocalTrainConstructorShouldHaveCorrectTrain) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<ElectricEnergy>(450);

    LocalTrain train(trainInfo, energyInfo);

    ASSERT_EQ(train.GetTrainInfo()->GetName(), "ZhiChang");
    ASSERT_EQ(train.GetTrainInfo()->GetPricePerStation(), 75);
    ASSERT_EQ(train.GetTrainInfo()->GetSeat(), 45);
    ASSERT_EQ(train.GetTrainInfo()->GetTrain(), 8);
    ASSERT_EQ(train.GetTrainInfo()->GetStation(0), "Taipei");
    ASSERT_EQ(train.GetEnergyInfo()->GetEnergy(), 450);
}

TEST(CheckPoint4, TestLocalTrainGetTicketShouldHaveCorrectTicket) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<ElectricEnergy>(450);

    LocalTrain train(trainInfo, energyInfo);

    TicketInfo ticketInfo = train.GetTicket();
    ASSERT_EQ(ticketInfo.GetTrainInfo()->GetName(), "ZhiChang");
    ASSERT_EQ(ticketInfo.GetTrainInfo()->GetPricePerStation(), 75);
    ASSERT_EQ(ticketInfo.GetTrainInfo()->GetSeat(), 45);
    ASSERT_EQ(ticketInfo.GetTrainInfo()->GetTrain(), 8);
    ASSERT_EQ(ticketInfo.GetTrainInfo()->GetStation(0), "Taipei");
    ASSERT_EQ(ticketInfo.GetPrice(), 75);
}

TEST(CheckPoint4, TestTrainGetArrivalTimeShouldHaveCorrectArrivalTime) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<ElectricEnergy>(450);
    LocalTrain train(trainInfo, energyInfo);

    CalculateHelper calculateHelper;
    ASSERT_EQ(train.GetEnergyInfo()->GetTerminalStationArrivalTimeInSecond(),
              calculateHelper.CalculateElectricArrivalTime(450));
}

TEST(CheckPoint4, TestLocalTrainGetDistanceShouldHaveCorrectDistance) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<ElectricEnergy>(450);
    LocalTrain train(trainInfo, energyInfo);

    CalculateHelper calculateHelper;
    ASSERT_EQ(train.GetEnergyInfo()->GetDistance(),
              calculateHelper.CalculateElectricDistance(450));
}

TEST(CheckPoint4, TestExpressTrainConstructorShouldHaveCorrectTrain) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<ElectricEnergy>(450);

    ExpressTrain train(trainInfo, energyInfo);

    ASSERT_EQ(train.GetTrainInfo()->GetName(), "ZhiChang");
    ASSERT_EQ(train.GetTrainInfo()->GetPricePerStation(), 75);
    ASSERT_EQ(train.GetTrainInfo()->GetSeat(), 45);
    ASSERT_EQ(train.GetTrainInfo()->GetTrain(), 8);
    ASSERT_EQ(train.GetTrainInfo()->GetStation(0), "Taipei");
    ASSERT_EQ(train.GetEnergyInfo()->GetEnergy(), 450);
}

TEST(CheckPoint4, TestExpressTrainReserveSeatShouldHaveCorrectReserveInfo) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang",
        std::vector<std::string>{"Taipei", "HsinChu", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<ElectricEnergy>(450);
    ExpressTrain train(trainInfo, energyInfo);

    ReserveTicketInfo reserveTicketInfo = train.Reserve(0, 2);

    ASSERT_EQ(reserveTicketInfo.GetReserveInfo().GetTrain(), 1);
    ASSERT_EQ(reserveTicketInfo.GetReserveInfo().GetSeat(), 1);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetName(), "ZhiChang");
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetPricePerStation(), 75);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetSeat(), 45);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetTrain(), 8);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetStation(0), "Taipei");
    ASSERT_EQ(reserveTicketInfo.GetPrice(), 150);
}

TEST(CheckPoint4,
     TestExpressTrainReserveSeatWithMultiplePollShouldHaveCorrectReserveInfo) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang",
        std::vector<std::string>{"Taipei", "HsinChu", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<ElectricEnergy>(450);
    ExpressTrain train(trainInfo, energyInfo);
    for (int i = 0; i < 7 * 45; i++) {
        trainInfo->ReserveSeat();
    }

    ReserveTicketInfo reserveTicketInfo = train.Reserve(0, 1);

    ASSERT_EQ(reserveTicketInfo.GetReserveInfo().GetTrain(), 8);
    ASSERT_EQ(reserveTicketInfo.GetReserveInfo().GetSeat(), 1);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetName(), "ZhiChang");
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetPricePerStation(), 75);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetSeat(), 45);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetTrain(), 8);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetStation(0), "Taipei");
    ASSERT_EQ(reserveTicketInfo.GetPrice(), 75);
}

TEST(CheckPoint4, TestExpressTrainGetArrivalTimeShouldHaveCorrectArrivalTime) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<ElectricEnergy>(450);
    ExpressTrain train(trainInfo, energyInfo);

    CalculateHelper calculateHelper;
    ASSERT_EQ(train.GetEnergyInfo()->GetTerminalStationArrivalTimeInSecond(),
              calculateHelper.CalculateElectricArrivalTime(450));
}

TEST(CheckPoint4, TestExpressTrainGetDistanceShouldHaveCorrectDistance) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<ElectricEnergy>(450);
    ExpressTrain train(trainInfo, energyInfo);

    CalculateHelper calculateHelper;
    ASSERT_EQ(train.GetEnergyInfo()->GetDistance(),
              calculateHelper.CalculateElectricDistance(450));
}

TEST(CheckPoint4, TestTouristTrainConstructorShouldHaveCorrectTrain) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<ElectricEnergy>(450);

    TouristTrain train(trainInfo, energyInfo);

    ASSERT_EQ(train.GetTrainInfo()->GetName(), "ZhiChang");
    ASSERT_EQ(train.GetTrainInfo()->GetPricePerStation(), 75);
    ASSERT_EQ(train.GetTrainInfo()->GetSeat(), 45);
    ASSERT_EQ(train.GetTrainInfo()->GetTrain(), 8);
    ASSERT_EQ(train.GetTrainInfo()->GetStation(0), "Taipei");
    ASSERT_EQ(train.GetEnergyInfo()->GetEnergy(), 450);
}

TEST(CheckPoint4, TestTouristTrainReserveSeatShouldHaveCorrectReserveInfo) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<ElectricEnergy>(450);
    TouristTrain train(trainInfo, energyInfo);

    ReserveTicketInfo reserveTicketInfo = train.Reserve(0, 2);

    ASSERT_EQ(reserveTicketInfo.GetReserveInfo().GetTrain(), 1);
    ASSERT_EQ(reserveTicketInfo.GetReserveInfo().GetSeat(), 1);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetName(), "ZhiChang");
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetPricePerStation(), 75);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetSeat(), 45);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetTrain(), 8);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetStation(0), "Taipei");
    ASSERT_EQ(reserveTicketInfo.GetPrice(), 150);
}

TEST(CheckPoint4,
     TestTouristTrainReserveSeatWithMultiplePollShouldHaveCorrectReserveInfo) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<ElectricEnergy>(450);
    TouristTrain train(trainInfo, energyInfo);
    for (int i = 0; i < 7 * 45; i++) {
        trainInfo->ReserveSeat();
    }

    ReserveTicketInfo reserveTicketInfo = train.Reserve(0, 1);

    ASSERT_EQ(reserveTicketInfo.GetReserveInfo().GetTrain(), 8);
    ASSERT_EQ(reserveTicketInfo.GetReserveInfo().GetSeat(), 1);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetName(), "ZhiChang");
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetPricePerStation(), 75);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetSeat(), 45);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetTrain(), 8);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetStation(0), "Taipei");
    ASSERT_EQ(reserveTicketInfo.GetPrice(), 75);
}

TEST(CheckPoint4, TestTouristTrainGetArrivalTimeShouldHaveCorrectArrivalTime) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<ElectricEnergy>(450);
    TouristTrain train(trainInfo, energyInfo);

    CalculateHelper calculateHelper;
    ASSERT_EQ(train.GetEnergyInfo()->GetTerminalStationArrivalTimeInSecond(),
              calculateHelper.CalculateElectricArrivalTime(450));
}

TEST(CheckPoint4, TestTouristTrainGetDistanceShouldHaveCorrectDistance) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    std::shared_ptr<EnergyInfo> energyInfo =
        std::make_shared<ElectricEnergy>(450);
    TouristTrain train(trainInfo, energyInfo);

    CalculateHelper calculateHelper;
    ASSERT_EQ(train.GetEnergyInfo()->GetDistance(),
              calculateHelper.CalculateElectricDistance(450));
}