#pragma once

#include <vector>
#include "SmartArray.h"

class ReallySmartArray : public SmartArray {
    private:
        int partition(int arr[], int start, int end);
        void quickSort(int arr[], int start, int end);
    public:
        ReallySmartArray(std::vector<int> initialData = {});
        void sortArray();
        void print();
};
