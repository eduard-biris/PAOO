#include <iostream>
#include "ArrayInterface.h"

void ArrayInterface::print() {
    std::cout << "[";

    for(int i=0; i<n; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << "\b]\n";
}