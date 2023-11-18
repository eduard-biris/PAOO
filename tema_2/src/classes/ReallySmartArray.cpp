#include <iostream>
#include "ReallySmartArray.h"
#include "utils.h"

ReallySmartArray::ReallySmartArray(std::vector<int> initialData) {
    std::cout << "Called ReallySmartArray constructor with default data\n";

    int totalSize = initialData.size();

    array = (int*)malloc(totalSize * sizeof(int));
    if(!array) {
        std::cout << "Allocation error. Exiting...\n";
        exit(1);
    }

    avMemory = totalSize;

    for(int& x: initialData) {
        array[n++] = x;
    }
}

int ReallySmartArray::partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;

    std::swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}

void ReallySmartArray::quickSort(int arr[], int start, int end)
{
    if (start >= end) return;
 
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

void ReallySmartArray::sortArray() {
    std::cout << "Using quicksort instead of bubble sort...\n";
    quickSort(array, 0, n);
}

void ReallySmartArray::print() {
    std::cout << "ReallySmartArray::: ";
    utils::printArrayOfInt(array, n);
}