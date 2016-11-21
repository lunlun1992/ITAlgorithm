#include <algorithm>
#include <iostream>
#define MAXSIZE 100000
using namespace std;

class Priority_queue
{
public:
	Priority_queue(int *arr, int length);
	~Priority_queue();
	void insert(int x);
	void max_heapify(int i);
	int maximum();
	int extract_max();
	void increase(int i, int k);
	void build_max_heap();
private:
	int info[MAXSIZE];
	int length;
};

Priority_queue::Priority_queue(int *arr, int length)
{
	this->length = length;
	memcpy(info, arr, sizeof(int) * length);
	build_max_heap();
}

Priority_queue::~Priority_queue()
{

}

void Priority_queue::insert(int x)
{
	length++;
	info[length - 1] = INT_MIN;
	increase(length - 1, x);
}

void Priority_queue::max_heapify(int i)
{
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	int large;
	if (l < length && info[l] > info[i])
		large = l;
	else large = i;
	if (r < length && info[r] > info[large])
		large = r;
	if (large != i)
	{
		int temp = info[i];
		info[i] = info[large];
		info[large] = temp;
		max_heapify(large);
	}
}

int Priority_queue::maximum()
{
	return info[0];
}

int Priority_queue::extract_max()
{
	int max;
	if (length < 1)
		return -1;
	max = info[0];
	info[0] = info[length - 1];
	length--;
	max_heapify(0);
	return max;
}

void Priority_queue::increase(int i, int k)
{
	if (k < info[i])
		return;
	info[i] = k;
	while (i > 0 && info[(i + 1) / 2 - 1] < info[i])
	{
		int temp = info[(i + 1) / 2 - 1];
		info[(i + 1) / 2 - 1] = info[i];
		info[i] = temp;
		i = (i + 1) / 2 - 1;
	}
}

void Priority_queue::build_max_heap()
{
	int i;
	for (i = length / 2; i >= 0; i--)
	{
		max_heapify(i);
	}
}

int main()
{
	int arr[] = { 2, 13, 9, 5, 12, 8, 7, 4, 0, 6 };
	Priority_queue pq = Priority_queue(arr, 10);
	pq.insert(15);
	return 0;
}
