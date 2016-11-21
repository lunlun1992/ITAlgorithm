#include <iostream>
#include <vector>
using namespace std;

pair<int, int> minmax(vector<int> &input)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int i = 0;
    for(; i + 1 < input.size(); i += 2)
    {
        if(input[i] > input[i + 1])
        {
            mini = min(mini, input[i + 1]);
            maxi = max(maxi, input[i]);
        }
        else
        {
            mini = min(mini, input[i]);
            maxi = max(maxi, input[i + 1]);
        }
    }
    for(; i < input.size(); i++)
    {
        mini = min(mini, input[i]);
        maxi = max(maxi, input[i]);
    }
    return make_pair(mini, maxi);
}

int main()
{
    vector<int> input = {1,384,5,3,5,4,6,4,7,3,2,100};
    pair<int, int> p = minmax(input);
    cout << p.first << " " << p.second << endl;
    return 0;
}