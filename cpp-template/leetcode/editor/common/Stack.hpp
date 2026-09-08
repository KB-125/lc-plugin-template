#include <list>
#include <vector>

template <typename E>
class LinkedStack {
private:
    std::list<E> list;

public:
    // 向栈顶加入元素，时间复杂度 O(1)
    void push(const E& e) { list.push_back(e); }

    // 从栈顶弹出元素，时间复杂度 O(1)
    E pop() {
        E value = list.back();
        list.pop_back();
        return value;
    }

    // 查看栈顶元素，时间复杂度 O(1)
    E peek() const { return list.back(); }

    // 返回栈中的元素个数，时间复杂度 O(1)
    int size() const { return list.size(); }
};

template <typename E>
class MyArrayStack {
private:
    std::vector<E> arr;

public:
    // 向栈顶加入元素，时间复杂度 O(1)
    void push(const E& e) { arr.push_back(e); }

    // 从栈顶弹出元素，时间复杂度 O(1)
    E pop() {
        E topElement = arr.back();
        arr.pop_back();
        return topElement;
    }

    // 查看栈顶元素，时间复杂度 O(1)
    E peek() const { return arr.back(); }

    // 返回栈中的元素个数，时间复杂度 O(1)
    int size() const { return arr.size(); }
};