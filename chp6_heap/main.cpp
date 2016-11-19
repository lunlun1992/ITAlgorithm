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
int main(int argc, const char * argv[])
{
    vector<int> input = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    Heap heap(input);
    heap.heap_sort();
    return 0;
}
