//
//  heap.hpp
//  ITA_Heap
//
//  Created by Weilun Feng on 11/19/16.
//  Copyright © 2016 Weilun Feng. All rights reserved.
//

#ifndef heap_hpp
#define heap_hpp
#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
    Heap(vector<int> &vec);
    void max_heapify(int idx);
    void build_max_heap();
    void heap_sort();
    void output();
private:
    int leftidx(int idx);
    int rightidx(int idx);
    vector<int> inner_nums;
};

#endif /* heap_hpp */
