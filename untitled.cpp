#include <iostream>
#include <limit.h>

using namespace std;
int main()
{



	return 0;
}

class Heap
{
	int* heap;
	int capacity;
	int heapSize;

public:

	Heap(int capacity);

	void heapify();
	void insert(int item);
	void decrease(int key,int key_value);
	void delete_node();
	int get_min();
	int extract_Min();

	int get_left(int key) { return i*2+1; }
	int get_right(int key) { return i*2+2; }
	int get_parent(int key) { return (i-1)/2; }

};

Heap::Heap(int capacity)
{
	this->capacity = capacity;
	heap = new int[capacity];
	heapSize = 0;
}

void Heap::heapify(int key)
{
	int smallest = key;
	int left = get_left(key);
	int right = get_right(key);

	if(left < heapSize && heap[left] < heap[key])
		smallest = left;

	if(right < heapSize && heap[right] < heap[smallest])
		smallest = right;

	if (key != smallest)
	{
		int temp = heap[key];
		heap[key] = heap[smallest];
		heap[smallest] = temp;
		heapify(smallest);
	}

}

void insert()





