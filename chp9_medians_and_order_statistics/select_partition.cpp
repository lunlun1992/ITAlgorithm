#include <iostream>
#include <vector>
using namespace std;

int findMedian5(vector<int> &input, int idx)
{
    sort(input.begin() + idx, input.begin() + idx + 5);
    return input[idx + 2];
}

int partition(vector<int> &input, int aim, int s, int e)
{
    int r = input[e];
    int i = s - 1;
    for(int j = s; j < e; j++)
    {
        if(input[j] <= r)
            swap(input[++i], input[j]);
    }
    swap(input[i + 1], input[e]);
    return i + 1;
}

int select(vector<int> &input, int k, int s, int e)
{
    if(k <= 0 || k > e - s + 1)
        return INT_MAX;
    vector<int> medians;
    int len = e - s + 1;
    int i = 0;
    for(i = 0; i < len / 5; i++)
        medians.push_back(findMedian5(input, i * 5));
    i *= 5;
    medians.push_back(input[i]);
    int med = medians.size() == 1 ? medians[0] : select(medians, medians.size() / 2, 0, medians.size() - 1);
    int pos = partition(input, med, s, e);
    if(pos - s == k - 1)
        return input[pos];
    else if(pos - s > k - 1)
        return select(input, k, s, pos - 1);
    else
        return select(input, k - pos + s - 1, pos + 1, e);
}

int main()
{
    vector<int> input = {7,4,1,5,2,6,2,7,3,5,4,32,2,5,3,5,3,1,5};
    for(int i = 0; i < input.size(); i++)
        cout << select(input, i + 1, 0, input.size() - 1) << endl;
    return 0;
}