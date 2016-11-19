//
//  heap.cpp
//  ITA_Heap
//
//  Created by Weilun Feng on 11/19/16.
//  Copyright © 2016 Weilun Feng. All rights reserved.
//

#include "heap.hpp"

Heap::Heap(vector<int> &vec)
{
    inner_nums.assign(vec.begin(), vec.end());
}

int Heap::leftidx(int idx)
{
    return (idx + 1) * 2 - 1;
}

int Heap::rightidx(int idx)
{
    return (idx + 1) * 2;
}


void Heap::max_heapify(int idx)
{
    int l = leftidx(idx);
    int r = rightidx(idx);
    size_t heapsize = inner_nums.size();
    bool changed = false;
    int largest = idx;
    do
    {
        changed = false;
        if(l < heapsize && inner_nums[l] > inner_nums[idx])
        {
            changed = true;
            largest = l;
        }
        else
            largest = idx;
        if(r < heapsize && inner_nums[r] > inner_nums[largest])
        {
            changed = true;
            largest = r;
        }
        int temp = inner_nums[largest];
        inner_nums[largest] = inner_nums[idx];
        inner_nums[idx] = temp;
        l = leftidx(largest);
        r = rightidx(largest);
        idx = largest;
    }while(changed);
}

void Heap::build_max_heap()
{
    int heapsize = (int)inner_nums.size();
    for(int i = heapsize / 2 - 1; i >= 0; i--)
        max_heapify(i);
}

void Heap::heap_sort()
{
    build_max_heap();
    int heapsize = (int)inner_nums.size();
    for(int i = heapsize - 1; i >= 0; i--)
    {
        int temp = inner_nums[i];
        inner_nums[i] = inner_nums[0];
        inner_nums[0] = temp;
        cout << inner_nums[i] << endl;
        inner_nums.pop_back();
        max_heapify(0);
    }
}



