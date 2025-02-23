set(SRC_FILES
        FactoryJapan.cpp
        FactoryUSA.cpp
        Vehicle.cpp
        Train.cpp
        Plane.cpp
        Boat.cpp
        Bus.cpp
        EnergyStation.cpp
        MaintenanceSystem.cpp
        TicketSystem.cpp
)

set(INCLUDE_FILES
        Factory/FactoryJapan.h
        Factory/FactoryUSA.h
        Object/Boat.h
        Object/Bus.h
        Object/Plane.h
        Object/Train.h
        Object/Vehicle.h
        # System/TicketSystem.hpp
        # System/EnergyStation.hpp
        # System/MaintenanceSystem.hpp
)

set(TEST_FILES
        ut_Vehicle.cpp
        ut_Train.cpp
        ut_Plane.cpp
        ut_Bus.cpp
        ut_Boat.cpp
        ut_FactoryJapan.cpp
        ut_FactoryUSA.cpp
        # ut_MaintenceSystem.cpp
        # ut_EnergyStation.cpp
        # ut_TicketSystem.cpp
)