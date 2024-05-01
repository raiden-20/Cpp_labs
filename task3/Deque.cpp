#include "Deque.h"

template <typename T>
Deque<T>::Deque() = default;

template <typename T>
void Deque<T>::push_front(const T& value) {
    data.insert(data.begin(), value);
}

template <typename T>
void Deque<T>::push_back(const T& value) {
    data.push_back(value);
}

template <typename T>
void Deque<T>::pop_front() {
    if (!data.empty()) {
        data.erase(data.begin());
    }
}

template <typename T>
void Deque<T>::pop_back() {
    if (!data.empty()) {
        data.pop_back();
    }
}

template <typename T>
T& Deque<T>::front() {
    return data.front();
}

template <typename T>
T& Deque<T>::back() {
    return data.back();
}

template <typename T>
int Deque<T>::size() const {
    return data.size();
}