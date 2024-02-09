#include "MaxHeap.hpp"

#include <limits.h>

int MaxHeap::parent(int child) const
{
    return (child - 1) / 2;
}

int MaxHeap::left(int parent) const
{
    return parent * 2 + 1;
}

int MaxHeap::right(int parent) const
{
    return parent * 2 + 2;
}

void MaxHeap::maxHeapify(int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largestIndex = i;

    if (left < size && heap[largestIndex] < heap[left]) {
        largestIndex = left;
    }
    if (right < size && heap[largestIndex] < heap[right]) {
        largestIndex = right;
    }

    if (largestIndex != i) {
        std::swap(heap[i], heap[largestIndex]);
        maxHeapify(largestIndex);
    }
}

MaxHeap::MaxHeap()
    : size(0)
{
}

void MaxHeap::insertKey(int key)
{
    ++size;
    int i = size - 1;
    heap.push_back(key);

    while (i != 0 && heap[parent(i)] < heap[i]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

int MaxHeap::getMax() const
{
    return heap[0];
}

int MaxHeap::extractMax()
{
    if (empty()) {
        return INT_MIN;
    }
    if (size == 1) {
        --size;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    --size;
    maxHeapify(0);

    return root;
}

void MaxHeap::increaseKey(int i, int new_val)
{
    heap[i] = new_val;

    while (i != 0 && heap[parent(i)] < heap[i]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

bool MaxHeap::empty() const
{
    return size == 0;
}