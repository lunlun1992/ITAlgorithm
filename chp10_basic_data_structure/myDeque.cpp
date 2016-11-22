#include <iostream>
#include <vector>
using namespace std;

template <class T>
class myDeque
{
public:
    myDeque(int size);
    bool pushhead(T val);
    T pophead();
    bool pushtail(T val);
    T poptail();
private:
    vector<T> inner_array;
    int size;
    int tail;
    int head;
};

template <class T>
myDeque<T>::myDeque(int size)
{
    inner_array.assign(size, 0);
    tail = 0;
    head = 0;
    myDeque::size = size;
}

template <class T>
bool myDeque<T>::pushtail(T val)
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
T myDeque<T>::pophead()
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

template <class T>
bool myDeque<T>::pushhead(T val)
{
    if((head - 1) % size == tail)
        return false;
    else
    {
        head = (head - 1) % size;
        inner_array[head] = val;
        return true;
    }
}

template <class T>
T myDeque<T>::poptail()
{
    if(head == tail)
        return false;
    else {
        tail = (tail - 1) % size;
        return inner_array[tail];
    }
}

int main()
{
    myDeque<int> que(10);
    for(int i = 10; i < 21; i++)
        cout << que.pushtail(i) << endl;
    for(int i = 0; i < 11; i++)
        cout << que.poptail() << endl;
    return 0;
}