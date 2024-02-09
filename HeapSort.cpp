#include <iostream>

void maxHeapify(int* arr, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largestIndex = i;

    if (left < n && arr[largestIndex] < arr[left]) {
        largestIndex = left;
    }
    if (right < n && arr[largestIndex] < arr[right]) {
        largestIndex = right;
    }

    if (largestIndex != i) {
        std::swap(arr[i], arr[largestIndex]);
        maxHeapify(arr, n, largestIndex);
    }
}

void buildMaxHeap(int* arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; --i) {
        maxHeapify(arr, n, i);
    }
}

void heapSort(int* arr, int n)
{
    buildMaxHeap(arr, n);

    for (int i = n - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    int arr[] = { 60 ,20 ,40 ,70, 30, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMaxHeap(arr, n);

    std::cout << "After heapifying array is \n";
    printArray(arr, n);

    heapSort(arr, n);
 
    std::cout << "Sorted array is \n";
    printArray(arr, n); 

    return 0;
}