#include <iostream>
#include <vector>
using namespace std;

template <class T>
class myQueue
{
public:
    myQueue(int size);
    bool enqueue(T val);
    T dequeue();
private:
    vector<T> inner_array;
    int size;
    int tail;
    int head;
};

template <class T>
myQueue<T>::myQueue(int size)
{
    inner_array.assign(size, 0);
    tail = 0;
    head = 0;
    myQueue::size = size;
}

template <class T>
bool myQueue<T>::enqueue(T val)
{
    if((tail + 1) % size == head)
        return false;
    else {
        inner_array[tail] = val;
        tail = (tail + 1) % size;
        return true;
    }
}

template <class T>
T myQueue<T>::dequeue()
{
    if(head == tail)
        return false;
    else
    {
        T ret = inner_array[head];
        head = (head + 1) % size;
        return ret;
    }
}

int main()
{
    myQueue<int> que(10);
    for(int i = 10; i < 21; i++)
        cout << que.enqueue(i) << endl;
    for(int i = 0; i < 11; i++)
        cout << que.dequeue() << endl;
    return 0;
}