#include <iostream>
#include <vector>
using namespace std;

void counting_sort(vector<int> &nums, int k)
{
    vector<int> temp(k, 0);
    vector<int> ret(nums);
    for(auto a : nums)
        temp[a]++;
    for(int i = 1; i < k; i++)
        temp[i] += temp[i - 1];
    for(int i = nums.size() - 1; i >= 0; i--)
        ret[--temp[nums[i]]] = nums[i];
    nums.assign(ret.begin(), ret.end());
}

int main()
{
    vector<int> input = {1,3,2,4,6,8,2,6,3};
    counting_sort(input, 10);
    for(auto a : input)
        cout << a << endl;
    return 0;
}