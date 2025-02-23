//
// Created by 陳世昂 on 2024/11/12.
//
#include "Object/Train.h"
#include <iostream>
#include <stdexcept>

Train::Train(std::string country, std::string model, int durability,
             VehicleType type, int carriage, int maxCarriage)
    : Vehicle(country, model, durability, type) {
  // std::cout << country << model << durability << carriage << maxCarriage;
  if (durability < 0) {
    throw std::invalid_argument("no pive");
  }
  if (carriage < 0) {
    throw std::invalid_argument("no posve");
  }
  if (maxCarriage < 0) {
    throw std::invalid_argument("no posit");
  }
  if (carriage > maxCarriage) {
    throw std::invalid_argument("nsitive");
  }
  this->carriage = carriage;
  this->maxCarriage = maxCarriage;
}

FuelType Train::GetFuelType() { return FuelType::Electricity; }
VehicleType Train::GetVehicleType() { return VehicleType::TRAIN; }

void Train::ConsumeDurability() {

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
// 請查看表格二，減少載具的耐久值。如果耐久值小於 0 的時候，則
// std::runtime_error。

int Train::GetCarriage() const { return carriage; }
int Train::GetMaxCarriage() const { return maxCarriage; }

void Train::SetMaxCarriage(int value) {
  if (value < 0) {
    throw std::invalid_argument("not positive");
  }
  if (value > 12) {
    throw std::invalid_argument("no ");
  }
  maxCarriage = value;
}

void Train::SetCarriage(int value) {
  if (value < 0) {
    throw std::invalid_argument("not positive");
  }
  if (value > maxCarriage) {
    throw std::invalid_argument("positive");
  }
  carriage = value;
}
