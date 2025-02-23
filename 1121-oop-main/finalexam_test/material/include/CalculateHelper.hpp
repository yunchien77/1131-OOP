//
// Created by 黃漢軒 on 2023/12/18.
//

#ifndef OOP_DISTANCEHELPER_HPP
#define OOP_DISTANCEHELPER_HPP

#include <stdexcept>
#include <cmath>

class CalculateHelper {
public:
    int CalculateDieselDistance(int dieselEnergyLeft) {
        // Constants for the formula (adjust as needed)
        const double baseDistance = 50.0; // Base distance the train can cover
        const double energyFactor = 2.0;  // Energy impact factor

        // Ensure that energyLeft is non-negative
        if (dieselEnergyLeft < 0.0) {
            throw std::invalid_argument("Energy left cannot be negative.");
        }

        // Use a complex formula to calculate distance (adjust as needed)
        double distance = static_cast<int>(
            baseDistance * (1.0 - std::exp(-energyFactor * dieselEnergyLeft)));

        return distance;
    }

    int CalculateDieselArrivalTime(double energyLeft) {
        // Ensure that energyLeft is non-negative
        if (energyLeft < 0.0) {
            throw std::invalid_argument("Energy left cannot be negative.");
        }

        // Complex formula for arrival time (adjust as needed)
        int arrivalTime = static_cast<int>(50.0 * std::exp(-0.05 * energyLeft) +
                                           10.0 * std::sqrt(energyLeft + 1.0));

        return arrivalTime;
    }

    int CalculateElectricDistance(double electricEnergyLeft) {
        // Ensure that energyLeft is non-negative
        if (electricEnergyLeft < 0.0) {
            throw std::invalid_argument("Energy left cannot be negative.");
        }

        // Complex formula (adjust as needed)
        double distance =
            static_cast<int>(50.0 * std::log(electricEnergyLeft + 1.0) *
                             std::sqrt(electricEnergyLeft));

        return distance;
    }

    int CalculateElectricArrivalTime(double energyLeft) {
        // Ensure that energyLeft is non-negative
        if (energyLeft < 0.0) {
            throw std::invalid_argument("Energy left cannot be negative.");
        }

        // Complex formula for arrival time (adjust as needed)
        int arrivalTime = static_cast<int>(10.0 * std::exp(0.1 * energyLeft) +
                                           5.0 * std::sqrt(energyLeft + 1.0));

        return arrivalTime;
    }
};

#endif // OOP_DISTANCEHELPER_HPP
