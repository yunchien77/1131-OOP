//
// Created by 陳世昂 on 2024/11/12.
//

#include "Object/Vehicle.h"
#include <iostream>
#include <stdexcept>

Vehicle::Vehicle(std::string country, std::string model, int durability,
                 VehicleType type) {
  // std::cout << "input: " << durability;
  if (durability < 0) {
    throw std::invalid_argument("hi");
  }
  if (durability > 100) {
    throw std::invalid_argument("hi");
  }
  this->country = country;
  this->model = model;
  this->type = type;
  // std::cout << "d= " << std::endl << d;
  this->durability = durability;
}

int Vehicle::GetDurability() { return durability; }
int Vehicle::GetEnergy() { return energy; }
std::string Vehicle::GetCountry() { return country; }
std::string Vehicle::GetModel() { return model; }

void Vehicle::AddDurability(int value) {
  if (value > 100) {
    throw std::invalid_argument("not in the range");
  }
  if (value < 0) {
    throw std::invalid_argument("not in the range");
  }
  durability += value;
}

void Vehicle::AddEnergy(int value) {
  if (value > 1000) {
    throw std::invalid_argument("not in range");
  }
  if (value < 0) {
    throw std::invalid_argument("not in the range");
  }
  energy += value;
}

bool Vehicle::IsDurabilityZero() {
  if (durability == 0) {
    return true;
  }
  return false;
}
