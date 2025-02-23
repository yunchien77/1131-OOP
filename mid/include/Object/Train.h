//
// Created by adven on 10/24/2024.
//

#ifndef OOP_MIDTERM_TRAIN_H
#define OOP_MIDTERM_TRAIN_H

#include "Vehicle.h"
#include <string>

class Train : public Vehicle {
private:
  /* member */
  int carriage;
  int maxCarriage;

public:
  Train(std::string country, std::string model, int durability,
        VehicleType type, int carriage, int maxCarriage);

  virtual FuelType GetFuelType() override;
  virtual VehicleType GetVehicleType() override;
  virtual void ConsumeDurability() override;

  int GetCarriage() const;
  int GetMaxCarriage() const;

  void SetCarriage(int value);
  void SetMaxCarriage(int value);
};

#endif // OOP_MIDTERM_TRAIN_H
