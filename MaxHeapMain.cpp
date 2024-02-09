#include <iostream>
#include "MaxHeap.hpp"

int main()
{
    MaxHeap maxHeap;
    maxHeap.insertKey(16);
    maxHeap.insertKey(20);
    maxHeap.insertKey(1);
    maxHeap.insertKey(50);
    maxHeap.insertKey(0);
    maxHeap.insertKey(22);

    std::cout << maxHeap.getMax() << std::endl;
    std::cout << maxHeap.extractMax() << std::endl;
    std::cout << maxHeap.getMax() << std::endl;
    maxHeap.increaseKey(0, 58);
    std::cout << maxHeap.getMax() << std::endl;
}