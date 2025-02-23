#include <gtest/gtest.h>

#include "DieselEnergy.hpp"
#include "ElectricEnergy.hpp"

TEST(CheckPoint1, TestDieselEnergyConstructorShouldHaveCorrectValue) {
    DieselEnergy dieselEnergy(250);

    ASSERT_EQ(dieselEnergy.GetEnergy(), 250);
}

TEST(CheckPoint1, TestDieselEnergyGetDistanceShouldHaveCorrectDistance) {
    DieselEnergy dieselEnergy(250);

    CalculateHelper calculateHelper;
    ASSERT_EQ(dieselEnergy.GetDistance(),
              calculateHelper.CalculateDieselDistance(250));
}

TEST(CheckPoint1, TestDieselEnergyGetArrivalTimeShouldHaveCorrectArrivalTime) {
    DieselEnergy dieselEnergy(250);

    CalculateHelper calculateHelper;
    ASSERT_EQ(dieselEnergy.GetTerminalStationArrivalTimeInSecond(),
              calculateHelper.CalculateDieselArrivalTime(250));
}

TEST(CheckPoint1, TestElectricEnergyConstructorShouldHaveCorrectValue) {
    ElectricEnergy electricEnergy(399);

    ASSERT_EQ(electricEnergy.GetEnergy(), 399);
}

TEST(CheckPoint1, TestElectricEnergyGetDistanceShouldHaveCorrectDistance) {
    ElectricEnergy electricEnergy(399);

    CalculateHelper calculateHelper;
    ASSERT_EQ(electricEnergy.GetDistance(),
              calculateHelper.CalculateElectricDistance(399));
}

TEST(CheckPoint1,
     TestElectricEnergyGetArrivalTimeShouldHaveCorrectArrivalTime) {
    ElectricEnergy electricEnergy(399);

    CalculateHelper calculateHelper;
    ASSERT_EQ(electricEnergy.GetTerminalStationArrivalTimeInSecond(),
              calculateHelper.CalculateElectricArrivalTime(399));
}
