#ifndef FURNACE_HPP
#define FURNACE_HPP

#include <memory>

#include "ISmeltable.hpp"
#include "Ingot.hpp"

class Furnace final {
public:
    void Smelt();
    void SetInput(std::shared_ptr<ISmeltable> input);
    std::shared_ptr<Ingot> GetOutput();

private:
    std::shared_ptr<ISmeltable> input_;
    std::shared_ptr<Ingot> output_;
};

#endif
