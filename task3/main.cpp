#include <iostream>
#include "Deque.h"
#include "Deque.cpp"

using namespace std;

int main() {
    Deque<int> intDeque;
    intDeque.push_back(1);
    intDeque.push_front(2);
    // intDeque = 21
    cout << "Size: " << intDeque.size() << endl;
    cout << "First element: " << intDeque.front() << endl;
    cout << "Last element: " << intDeque.back() << endl;
    intDeque.push_back(3);
    // intDeque = 213
    intDeque.pop_front();
    intDeque.pop_back();
    cout << "Size after pop_front and pop_back: " << intDeque.size() << endl;

    Deque<string> stringDeque;
    stringDeque.push_back("day");
    stringDeque.push_front("nice");
    cout << "Size: " << stringDeque.size() << endl;
    cout << "First element: " << stringDeque.front() << endl;
    cout << "Last element: " << stringDeque.back() << endl;
    stringDeque.pop_back();
    cout << "Size after pop_back: " << stringDeque.size() << endl;

    return 0;
}
