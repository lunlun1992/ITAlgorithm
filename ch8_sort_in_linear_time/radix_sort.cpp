#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

void counting_sort_digits(vector<P> &digits, int k)
{
    vector<int> temp(k, 0);
    vector<P> ret(digits);
    for(auto a : digits)
        temp[a.second]++;
    for(int i = 1; i < k; i++)
        temp[i] += temp[i - 1];
    for(int i = digits.size() - 1; i >= 0; i--)
        ret[--temp[digits[i].second]] = digits[i];
    digits.assign(ret.begin(), ret.end());
}


void radix_sort(vector<int> &nums, int k)
{
    vector<int> sortnums(nums);
    for(int i = 0; i < k; i++)
    {
        //extract each digit
        vector<P> digits;
        for(int j = 0; j < nums.size(); j++)
        {
            digits.push_back(P(j, sortnums[j] % 10));
            sortnums[j] /= 10;
        }

        //sort with idx
        counting_sort_digits(digits, 10);

        //change the arrange of nums with new idx
        vector<int> tempnums;
        vector<int> tempsortnums;
        for(int j = 0; j < nums.size(); j++)
        {
            tempnums.push_back(nums[digits[j].first]);
            tempsortnums.push_back(sortnums[digits[j].first]);
        }
        nums.assign(tempnums.begin(), tempnums.end());
        sortnums.assign(tempsortnums.begin(), tempsortnums.end());
    }
}

int main()
{
    vector<int> input = {913, 741, 162, 312, 123, 412, 425};
    radix_sort(input, 3);
    for(auto a : input)
        cout << a << endl;
    return 0;
}