//
// Created by 陳世昂 on 2024/11/12.
//

//
// Created by 陳世昂 on 2024/11/12.
//

//
// Created by 陳世昂 on 2024/11/12.
//
#include "Object/Boat.h"
#include <stdexcept>

Boat::Boat(std::string country, std::string model, int durability,
           VehicleType type, int maxSpeed)
    : Vehicle(country, model, durability, type) {
  if (maxSpeed < 0) {
    throw std::invalid_argument("no posve");
  }
  if (maxSpeed > 30) {
    throw std::invalid_argument("no posve");
  }
  this->maxSpeed = maxSpeed;
}

FuelType Boat::GetFuelType() { return FuelType::Gasoline; }
VehicleType Boat::GetVehicleType() { return VehicleType::BOAT; }

void Boat::ConsumeDurability() {

  if (country == "USA") {
    durability -= 4;
  } else if (country == "Japan") {
    durability -= 5;
  } else {
    durability -= 10;
  }
  if (durability < 0) {
    throw std::runtime_error("error");
  }
}

bool Boat::GetSailing() const { return sailing; }
int Boat::GetMaxSpeed() const { return maxSpeed; }

void Boat::SetMaxSpeed(int value) {
  if (value > 30) {
    throw std::invalid_argument("no posve");
  }
  maxSpeed = value;
}

void Boat::SetSailing(bool status) { sailing = status; }
