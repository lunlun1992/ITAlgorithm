#include <iostream>
#include <vector>
using namespace std;

template <class T>
class myStack
{
public:
    myStack(int size);
    T pop();
    bool push(T val);
private:
    vector<T> inner_array;
    int top;
    int assize;
};

template <class T>
myStack<T>::myStack(int size)
{
    inner_array.assign(size, 0);
    top = 0;
    assize = size;
}

template <class T>
bool myStack<T>::push(T val)
{
    if (top < assize)
    {
        inner_array[top++] = val;
        return true;
    }
    else
        return false;
}

template <class T>
T myStack<T>::pop()
{
    if(top > 0)
        return inner_array[--top];
    else
        return NULL;
};

int main()
{

    myStack<int> st(10);
    for(int i = 10; i < 21; i++)
        cout << st.push(i) << endl;
    for(int i = 0; i < 11; i++)
        cout << st.pop() << endl;
    return 0;
}