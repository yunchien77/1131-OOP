#include "Furnace.hpp"

#include <stdexcept>
void Furnace::Smelt() {
    if (!input_) {
        throw std::runtime_error("No input material");
    }
    if (output_) {
        throw std::runtime_error("Output slot is not empty");
    }
    output_ = input_->Smelt();
}

void Furnace::SetInput(std::shared_ptr<ISmeltable> input) {
    input_ = input;
}

std::shared_ptr<Ingot> Furnace::GetOutput() {
    if (!output_) {
        throw std::runtime_error("No output available");
    }
    auto result = output_;
    output_ = nullptr;
    return result;
}