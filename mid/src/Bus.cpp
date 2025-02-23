//
// Created by 陳世昂 on 2024/11/12.
//

//
// Created by 陳世昂 on 2024/11/12.
//
#include "Object/Bus.h"
#include <iostream>
#include <stdexcept>

Bus::Bus(std::string country, std::string model, int durability,
         VehicleType type, int wheel, int maxSpeed)
    : Vehicle(country, model, durability, type) {
  // std::cout << country << std::endl
  //           << model << std::endl
  //           << durability << std::endl
  //           << wheel << std::endl
  //           << maxSpeed;
  if (wheel < 0) {
    throw std::invalid_argument("hhh");
  }
  if (maxSpeed < 0) {
    throw std::invalid_argument("hhh");
  }
  if (wheel > 12) {
    throw std::invalid_argument("hhh");
  }
  if (maxSpeed > 80) {
    throw std::invalid_argument("hhh");
  }
  this->wheel = wheel;
  this->maxSpeed = maxSpeed;
}

FuelType Bus::GetFuelType() { return FuelType::Gasoline; }
VehicleType Bus::GetVehicleType() { return VehicleType::BUS; }

void Bus::ConsumeDurability() {
  if (country == "USA") {
    durability -= 5;
  } else if (country == "Japan") {
    durability -= 1;
  } else {
    durability -= 10;
  }
  if (durability < 0) {
    throw std::runtime_error("error");
  }
}

int Bus::GetWheel() const { return wheel; }
int Bus::GetMaxSpeed() const { return maxSpeed; }

void Bus::SetMaxSpeed(int value) {
  if (value > 80) {
    throw std::invalid_argument("hhh");
  }
  maxSpeed = value;
}

void Bus::SetWheel(int value) {
  if (value > 12) {
    throw std::invalid_argument("hhh");
  }
  wheel = value;
}
