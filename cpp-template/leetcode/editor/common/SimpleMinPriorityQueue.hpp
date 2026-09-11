//#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class SimpleMinPQ {
    // 底层使用数组实现二叉堆
    vector<T> heap;

    // 堆中元素的数量
    int size;

    // 父节点的索引
    static int parent(int node) {
        return (node - 1) / 2;
    }

    // 左子节点的索引
    static int left(int node) {
        return node * 2 + 1;
    }

    // 右子节点的索引
    static int right(int node) {
        return node * 2 + 2;
    }

    // 上浮操作，时间复杂度是树高 O(logN)
    void swim(int node) {
        while (node > 0 && heap[parent(node)] > heap[node]) {
            swap(heap[parent(node)], heap[node]);
            node = parent(node);
        }
    }

    // 下沉操作，时间复杂度是树高 O(logN)
    void sink(int node) {
        while (left(node) < size || right(node) < size) {
            // 比较自己和左右子节点，看看谁最小
            int min = node;
            if (left(node) < size && heap[left(node)] < heap[min]) {
                min = left(node);
            }
            if (right(node) < size && heap[right(node)] < heap[min]) {
                min = right(node);
            }
            if (min == node) {
                break;
            }
            // 如果左右子节点中有比自己小的，就交换
            swap(heap[node], heap[min]);
            node = min;
        }
    }

public:
    // 构造函数，初始化容量
    SimpleMinPQ(int capacity) {
        heap.resize(capacity);
        size = 0;
    }

    // 返回堆的元素数量
    int getSize() const {
        return size;
    }

    // 查，返回堆顶元素，时间复杂度 O(1)
    int peek() {
        return heap[0];
    }

    // 增，向堆中插入一个元素，时间复杂度 O(logN)
    void push(int x) {
        // 把新元素追加到最后
        heap[size] = x;
        // 然后上浮到正确位置
        swim(size);
        size++;
    }

    // 删，删除堆顶元素，时间复杂度 O(logN)
    int pop() {
        int res = heap[0];
        // 把堆底元素放到堆顶
        size--;
        // 然后下沉到正确位置
        sink(0);
        return res;
    }
};

/* int main() {
    SimpleMinPQ<int> pq(5);
    pq.push(3);
    pq.push(2);
    pq.push(1);
    pq.push(5);
    pq.push(4);

    cout << pq.pop() << endl; // 1
    cout << pq.pop() << endl; // 2
    cout << pq.pop() << endl; // 3
    cout << pq.pop() << endl; // 4
    cout << pq.pop() << endl; // 5

    return 0;
} */