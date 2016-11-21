#include <iostream>
#include <vector>
using namespace std;


int find_partition(vector<int> &input, int aim, int s, int e)
{
    int r = input[e];
    int i = s - 1;
    for(int j = s; j < e; j++)
    {
        if(input[j] <= r)
            swap(input[++i], input[j]);
    }
    swap(input[i + 1], input[e]);
    if(i + 1 == aim)
        return input[i + 1];
    else if(i + 1 < aim) //on the right side
        return find_partition(input, aim, i + 2, e);
    else //on the left side
        return find_partition(input, aim, s, i);
}

int main()
{
    vector<int> input = {913, 741, 162, 312, 123, 412, 425, 412, 5, 1, 5, 12 ,5, 2, 1, 51, 2};
    for(int i = 0; i < input.size(); i++)
        cout << find_partition(input, i, 0, input.size() - 1) << endl;
    return 0;
}