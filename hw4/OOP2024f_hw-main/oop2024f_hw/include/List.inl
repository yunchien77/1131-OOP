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
    return m_data.pop_back();
}

template class List<int>;

#endif
#endif // OOP_LIST_INL
