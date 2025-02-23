//
// Created by adven on 12/2/2024.
//

#ifndef OOP_LIST_INL
#define OOP_LIST_INL

#if TESTING_TARGET2
template <typename T>
int List<T>::GetLength() {
    return m_data.size();
}

template <typename T>
void List<T>::AddElement(T elem) {
    m_data.push_back(elem);
}

template <typename T>
T List<T>::PopElement() {
    if (m_data.empty()) {
        throw std::out_of_range("Cannot pop from an empty list");
    }

    T lastElement = m_data.back();
    m_data.pop_back();
    return lastElement;
}

template class List<int>;
#endif

#endif // OOP_LIST_INL