#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP

#include <vector>

class MaxHeap
{
public:
    MaxHeap();
    void insertKey(int);
    int getMax() const;
    int extractMax();
    void increaseKey(int, int);
    bool empty() const;

private:
    std::vector<int> heap;
    int size;
    int parent(int) const;
    int left(int) const;
    int right(int) const;
    void maxHeapify(int);
};

#endif // MAXHEAP_HPP