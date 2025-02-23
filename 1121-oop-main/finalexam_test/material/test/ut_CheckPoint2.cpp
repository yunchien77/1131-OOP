#include <gtest/gtest.h>
#include <memory>

#include "ReserveInfo.hpp"
#include "ReserveTicketInfo.hpp"
#include "TicketInfo.hpp"
#include "TrainInfo.hpp"

TEST(CheckPoint2, TestTicketInfoConstructorShouldSetupValueCorrectly) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    TicketInfo ticketInfo(trainInfo);

    ASSERT_EQ(ticketInfo.GetTrainInfo()->GetName(), "ZhiChang");
    ASSERT_EQ(ticketInfo.GetTrainInfo()->GetPricePerStation(), 75);
    ASSERT_EQ(ticketInfo.GetTrainInfo()->GetSeat(), 45);
    ASSERT_EQ(ticketInfo.GetTrainInfo()->GetTrain(), 8);
    ASSERT_EQ(ticketInfo.GetTrainInfo()->GetStation(0), "Taipei");
}

TEST(CheckPoint2, TestTicketInfoGetPriceShouldReturnCorrectPrice) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang", std::vector<std::string>{"Taipei", "Tainan"});
    TicketInfo ticketInfo(trainInfo);

    ASSERT_EQ(ticketInfo.GetPrice(), 75);
}

TEST(CheckPoint2, TestReserveInfoConstructorShouldSetupValueCorrectly) {
    ReserveInfo reserveInfo(5, 8);

    ASSERT_EQ(reserveInfo.GetTrain(), 5);
    ASSERT_EQ(reserveInfo.GetSeat(), 8);
}

TEST(CheckPoint2, TestReserveTicketInfoConstructorShouldSetupValueCorrectly) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang",
        std::vector<std::string>{"Taipei", "HsinChu", "Tainan"});
    ReserveTicketInfo reserveTicketInfo(0, 2, trainInfo);

    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetName(), "ZhiChang");
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetPricePerStation(), 75);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetSeat(), 45);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetTrain(), 8);
    ASSERT_EQ(reserveTicketInfo.GetTrainInfo()->GetStation(0), "Taipei");
}

TEST(CheckPoint2, TestReserveTicketGetStartStationShouldReturnCorrectStation) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang",
        std::vector<std::string>{"Taipei", "HsinChu", "Tainan"});
    ReserveTicketInfo reserveTicketInfo(0, 2, trainInfo);

    ASSERT_EQ(reserveTicketInfo.GetStartStation(), "Taipei");
}

TEST(CheckPoint2, TestReserveTicketGetEndStationShouldReturnCorrectStation) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang",
        std::vector<std::string>{"Taipei", "HsinChu", "Tainan"});
    ReserveTicketInfo reserveTicketInfo(0, 2, trainInfo);

    ASSERT_EQ(reserveTicketInfo.GetEndStation(), "Tainan");
}

TEST(CheckPoint2, TestReserveTicketGetPriceShouldReturnCorrectPrice) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang",
        std::vector<std::string>{"Taipei", "HsinChu", "Tainan"});
    ReserveTicketInfo reserveTicketInfo(0, 2, trainInfo);

    ASSERT_EQ(reserveTicketInfo.GetPrice(), 150);
}

TEST(CheckPoint2,
     TestReserveTicketGetReserveInfoShouldReturnCorrectReserveInfo) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang",
        std::vector<std::string>{"Taipei", "HsinChu", "Tainan"});
    ReserveTicketInfo reserveTicketInfo(0, 2, trainInfo);

    ASSERT_EQ(reserveTicketInfo.GetReserveInfo().GetTrain(), 1);
    ASSERT_EQ(reserveTicketInfo.GetReserveInfo().GetSeat(), 1);
}

TEST(CheckPoint2,
     TestReserveTicketWithMultipleTicketShouldReturnCorrectReserveInfo) {
    std::shared_ptr<TrainInfo> trainInfo = std::make_shared<TrainInfo>(
        8, 45, 75, "ZhiChang",
        std::vector<std::string>{"Taipei", "HsinChu", "Tainan"});
    ReserveTicketInfo reserveTicketInfo = ReserveTicketInfo(0, 2, trainInfo);

    for (int i = 0; i < 4 * 45 + 15; i++) {
        reserveTicketInfo = ReserveTicketInfo(0, 2, trainInfo);
    }

    ASSERT_EQ(reserveTicketInfo.GetReserveInfo().GetTrain(), 5);
    ASSERT_EQ(reserveTicketInfo.GetReserveInfo().GetSeat(), 16);
}