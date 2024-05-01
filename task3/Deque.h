#ifndef TASK3_DEQUE_H
#define TASK3_DEQUE_H

#include <vector>

template <typename T>
class Deque {
private:
    std::vector<T> data;

public:
    Deque();
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    T& front();
    T& back();
    int size() const;
};


#endif //TASK3_DEQUE_H
