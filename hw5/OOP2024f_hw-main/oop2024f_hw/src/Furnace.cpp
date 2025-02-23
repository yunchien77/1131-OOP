#include "Furnace.hpp"

#include <stdexcept>

void Furnace::Smelt() {
    if (_input == nullptr) {
        throw std::runtime_error("e");
    }
    if (_output != nullptr) {
        throw std::runtime_error("f");
    }
    _output = _input->Smelt();
}

void Furnace::SetInput(std::shared_ptr<ISmeltable> input) {
    _input = input;
}

std::shared_ptr<Ingot> Furnace::GetOutput() {
    if (_output == nullptr) {
        throw std::runtime_error("g");
    }
    return _output;
}