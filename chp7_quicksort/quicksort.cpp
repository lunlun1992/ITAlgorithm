//
//  main.cpp
//  ITA_Heap
//
//  Created by Weilun Feng on 11/19/16.
//  Copyright © 2016 Weilun Feng. All rights reserved.
//

#include <iostream>
#include "heap.hpp"
using namespace std;

int partition(vector<int> &vec, int s, int e)
{
    int x = vec[e];
    int i = s - 1;
    for(int j = s; j < e; j++)
    {
        if(vec[j] < x)
        {
            i++;
            swap(vec[j], vec[i]);
        }
    }
    swap(vec[e], vec[i + 1]);
    return i + 1;
}

void quicksort(vector<int> &v, int s, int e)
{
    if(s >= e)
        return;
    int m = partition(v, 0, e);
    quicksort(v, s, m - 1);
    quicksort(v, m + 1, e);
    
}

int main(int argc, const char * argv[])
{
    vector<int> v = {2, 8, 7, 1, 3, 5, 6, 4};
    quicksort(v, 0, int(v.size() - 1));
    for(auto i : v)
        cout << i << endl;
    return 0;
}
