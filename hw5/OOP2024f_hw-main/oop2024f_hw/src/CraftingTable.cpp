#include "CraftingTable.hpp"
#include "ICraftable.hpp"

#include <stdexcept>

void CraftingTable::CraftArmor() {
    if (_input == nullptr) {
        throw std::runtime_error("a");
    }
    if (_output != nullptr) {
        throw std::runtime_error("b");
    }
    // _output = _input->CraftArmor();
    _output = std::make_shared<Armor>(_input->CraftArmor());
}

void CraftingTable::SetInput(std::shared_ptr<ICraftable> input) {
    _input = input;
}

std::shared_ptr<Armor> CraftingTable::GetOutput() {
    if (_output == nullptr) {
        throw std::runtime_error("d");
    }
    return _output;
}
