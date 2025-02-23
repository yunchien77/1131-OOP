#include "CraftingTable.hpp"

#include <stdexcept>
void CraftingTable::CraftArmor() {
    if (!input_) {
        throw std::runtime_error("No input material");
    }
    if (output_) {
        throw std::runtime_error("Output slot is not empty");
    }
    output_ = std::make_shared<Armor>(input_->CraftArmor());
}

void CraftingTable::SetInput(std::shared_ptr<ICraftable> input) {
    input_ = input;
}

std::shared_ptr<Armor> CraftingTable::GetOutput() {
    if (!output_) {
        throw std::runtime_error("No output available");
    }
    auto result = output_;
    output_ = nullptr;
    return result;
}
