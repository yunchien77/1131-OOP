//
// Created by 陳世昂 on 2024/11/24.
//

#ifndef OOP_VECTOR_HPP
#define OOP_VECTOR_HPP

#include "Config.hpp"
#include <stdexcept>
#include <vector>

#if TESTING_TARGET2
template <typename T>
class List {
private:
    std::vector<T> m_data;

public:
    int GetLength();
    void AddElement(T elem);
    T PopElement();
};
#endif

#include "List.inl"

#endif // OOP_VECTOR_HPP