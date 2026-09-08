#include <list>
#include "CircleArray.hpp"

template <typename E>
class LinkedQueue {
private:
    std::list<E> list;

public:
    void push(const E& e) { list.push_back(e); }

    E pop() {
        E front = list.front();
        list.pop_front();
        return front;
    }

    E peek() { return list.front(); }

    size_t size() { return list.size(); }
};

template <typename E>
class ArrayQueue {
private:
    CircleArray<E> arr;

public:
    ArrayQueue() { arr = CircleArray<E>(); }

    void push(E t) { arr.addLast(t); }

    E pop() { return arr.removeForward(); }

    E peek() { return arr.getForward(); }

    int size() { return arr.size(); }
};