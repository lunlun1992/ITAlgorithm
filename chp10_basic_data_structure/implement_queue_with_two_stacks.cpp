#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <class T>
class myQueue
{
public:
    bool enqueue(T val);
    T dequeue();
private:
    stack<T> st1;
    stack<T> st2;
};

template <class T>
bool myQueue<T>::enqueue(T val)
{
    st1.push(val);
}

template <class T>
T myQueue<T>::dequeue()
{
    if(st1.empty() && st2.empty())
    {
        return NULL;
    }
    else if(!st2.empty())
    {
        int val = st2.top();
        st2.pop();
        return val;
    }
    else
    {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int val = st2.top();
        st2.pop();
        return val;
    }
}

int main()
{
    myQueue<int> que;
    for(int i = 10; i < 21; i++)
        cout << que.enqueue(i) << endl;
    for(int i = 0; i < 11; i++)
        cout << que.dequeue() << endl;
    return 0;
}