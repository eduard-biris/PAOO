#include <iostream>
#include "utils.h"

namespace utils {
    void printArrayOfInt(int *array, int n) {
        std::cout << "[";

        for(int i=0; i<n; i++) {
            std::cout << array[i] << " ";
        }

        std::cout << "\b]\n";
    }
}