#include <stdexcept>
#include <vector>

template<typename T>
class CircleArray{
    std::vector<T> array;
    size_t start;
    size_t end;
    size_t count;
    
    /**
     * @brief 自动扩缩容
     * 
     * @param[in]  newSize  
     * 
     */
    void resize(int newSize){
        std::vector<T> newArray(newSize);
        for (int i=0; i<count; ++i) {
            newArray[i] = array[(start+i)%array.size()];
        }
        array = std::move(newArray);
        //重置start end索引
        start = 0;
        end = count;
    }

    public:
    
    CircleArray():CircleArray(1){}

    explicit CircleArray(int size)
        :array(size),start(0),end(0),count(0){}
        
    void addForward(const T& val){
        if (isFull()) {
            resize(array.size()*2);
        }

        //start 是左闭右开[start, end)，先左移再赋值
        start = (start-1+array.size())%array.size();
        array[start] = val;
        count++;
    }

    T removeForward(){
        if (isFull()) {
            throw std::runtime_error("Array is empty");
        }
        //左闭右开[start, end), 先赋值载右移
        T val = array[start];
        array[start] = T{};
        start = (start+1)%array.size();
        count--;

        if (count>0 && count == array.size()/4) {
            resize(array.size()/2);
        }
        return val;
    }

    void addLast(const T& val){
        if (isFull()) {
            resize(array.size()*2);
        }

        //end侧为开区间，先赋值再右移
        array[end] = val;
        end = (end+1)%array.size();
        count++;
    }

    T removeLast(){
        if (isEmpty()) {
            throw std::runtime_error("Array is empty");
        }

        //end侧为开区间，先左移再赋值
        end=(end-1+array.size())%array.size();
        T val = array[end];
        array[end] = T{};
        count--;
        //缩容处理
        if (count>0 && count == array.size()/4) {
            resize(array.size()/2);
        }
        return val;

    }

    T getForward() const{
        if (isEmpty()) {
            throw std::runtime_error("Array is empty");
        }
        return array[start];
    }

    T getLast() const {
        if (isEmpty()) {
            throw std::runtime_error("Array is empty");
        }
        return array[(end-1+array.size())%array.size()];
    }


    bool isFull() const {
        return array.size() == count;
    }

    bool size() const {
        return count;
    }

    bool isEmpty() const {
        return 0 == count;
    }
};