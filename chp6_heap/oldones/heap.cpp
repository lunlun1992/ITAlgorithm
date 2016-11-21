#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

class Heap
{
public:
	Heap(int *arr, int length);
	~Heap();
	void max_heapify(Heap h, int i);
	void build_max_heap(Heap h);
	void heap_sort(Heap h);
	void print_heap();
private:
	int heap_size;
	int *heap_info;
};

Heap::Heap(int *arr, int length)
{
	heap_size = length;
	heap_info = (int *)malloc(sizeof(int) * heap_size);
	memcpy(heap_info, arr, sizeof(int) * length);

}

Heap::~Heap()
{
}

void Heap::max_heapify(Heap h, int i)
{
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	int large;
	if (l < h.heap_size && heap_info[l] > heap_info[i])
		large = l;
	else large = i;
	if (r < h.heap_size && heap_info[r] > heap_info[large])
		large = r;
	if (large != i)
	{
		int temp = heap_info[i];
		heap_info[i] = heap_info[large];
		heap_info[large] = temp;
		max_heapify(h, large);
	}

}

void Heap::build_max_heap(Heap h)
{
	int i;
	for (i = heap_size / 2; i >= 0; i--)
	{
		max_heapify(h, i);
	}
}

void Heap::heap_sort(Heap h)
{
	int i;
	build_max_heap(h);
	for (i = heap_size - 1; i >= 1; i--)
	{
		int temp = heap_info[i];
		heap_info[i] = heap_info[0];
		heap_info[0] = temp;
		h.heap_size--;
		max_heapify(h, 0);
	}
}

void Heap::print_heap()
{
	int i, len;
	len = 9;
	for (i = 0; i < len; i++)
	{
		printf("%d ", heap_info[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 5, 13, 2, 25, 7, 17, 20, 8, 4 };
	Heap h = Heap(arr, 9);
	h.heap_sort(h);
	h.print_heap();
	return 0;
}