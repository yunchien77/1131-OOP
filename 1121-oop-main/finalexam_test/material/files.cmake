set(SRC_FILES
    # CheckPoint 1
    EnergyInfo.cpp
    ElectricEnergy.cpp
    DieselEnergy.cpp
    # CheckPoint 2
    TicketInfo.cpp
    ReserveInfo.cpp
    ReserveTicketInfo.cpp
    # CheckPoint 3
    Train.cpp
    # CheckPoint 4
    ExpressTrain.cpp
    LocalTrain.cpp
    TouristTrain.cpp
    # CheckPoint 5
    TrainSystem.cpp
)

set(INCLUDE_FILES
    # Should compile (Done)
    ICalculable.hpp
    IReservable.hpp
    CalculateHelper.hpp
    TrainInfo.hpp
    # CheckPoint 1
    EnergyInfo.hpp
    DieselEnergy.hpp
    ElectricEnergy.hpp
    # CheckPoint 2
    TicketInfo.hpp
    ReserveInfo.hpp
    ReserveTicketInfo.hpp
    # CheckPoint 3
    Train.hpp
    # CheckPoint 4
    ExpressTrain.hpp
    LocalTrain.hpp
    TouristTrain.hpp
    # CheckPoint 4
    TrainSystem.hpp
)

set(TEST_FILES
    ut_CheckPoint1.cpp
    ut_CheckPoint2.cpp
    ut_CheckPoint3.cpp
    ut_CheckPoint4.cpp
    ut_CheckPoint5.cpp
)
