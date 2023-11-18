#include <cstdlib>
#include <iostream>
#include <vector>

#include "SmartArray.h"
#include "utils.h"

SmartArray::SmartArray(int totalSize) {
    std::cout << "Constructor called\n";

    array = (int*)malloc(totalSize * sizeof(int));
    if(!array) {
        std::cout << "Allocation error. Exiting...\n";
        exit(1);
    }

    avMemory = totalSize;
}

SmartArray::SmartArray(std::vector<int> initialData) {
    std::cout << "Called constructor with default data\n";

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

SmartArray::~SmartArray() {
    std::cout << "Freeing array memory...\n";
    free(array);
}

SmartArray::SmartArray(const SmartArray& arrayToCopy) {
    std::cout << "Copy constructor called\n";
    
    n = arrayToCopy.n;
    avMemory = arrayToCopy.avMemory;

    array = (int*)malloc(avMemory * sizeof(int));
    if(!array) {
        std::cout << "There was a problem copying the array. Exiting...\n";
        exit(1);
    }

    for(int i=0; i<n; i++) {
        array[i] = arrayToCopy.array[i];
    }
}

SmartArray &SmartArray::operator=(const SmartArray& arrayToCopy) {
    std::cout << "Copy asignment operator called\n";

    n = arrayToCopy.n;
    avMemory = arrayToCopy.avMemory;

    array = (int*)malloc(avMemory * sizeof(int));
    if(!array) {
        std::cout << "There was a problem copying the array. Eciting...\n";
        exit(1);
    }

    for(int i=0; i<n; i++) {
        array[i] = arrayToCopy.array[i];
    }

    return *this;
}

SmartArray::SmartArray(SmartArray&& arrayToMove) {
    std::cout << "Called move constructor\n";

    n = arrayToMove.n;
    avMemory = arrayToMove.avMemory;
    array = arrayToMove.array;

    arrayToMove.array = NULL;
}

SmartArray &SmartArray::operator=(SmartArray&& arrayToMove) {
    std::cout << "Called move asignment operator\n";

    n = arrayToMove.n;
    avMemory = arrayToMove.avMemory;
    array = arrayToMove.array;

    arrayToMove.array = NULL;

    return *this;
}

void SmartArray::push(int x) {
    if(n + 1 < avMemory) {
        array[n++] = x;
        return;
    }

    // Double memory space
    array = (int*)realloc(array, 2 * avMemory * sizeof(int));
    if(!array) {
        std::cout << "Out of memory. Exiting...\n";
        exit(1);
    };

    avMemory *= 2;
    array[n++] = x;
    return;
}

void SmartArray::pop() {
    if(n > 0) {
        n--;
        return;
    }

    std::cout << "Array is already empty...\n";
    return;
}

void SmartArray::sortArray() {
    if(!n) {
        std::cout << "Array is empty...\n";
        return;
    }

    int sortat = 0;
    while(!sortat) {
        sortat = 1;

        for(int i=1; i<n; i++) {
            if(array[i-1] > array[i]) {
                sortat = 0;

                int aux = array[i-1];
                array[i-1] = array[i];
                array[i] = aux;
            }
        }
    }

    std::cout << "Successfully sorted the array.\n";
    return;
}

void SmartArray::print() {
    std::cout << "SmartArray::: ";
    utils::printArrayOfInt(array, n);
}