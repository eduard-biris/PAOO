#pragma once

#include <vector>

class SmartArray {
    private:
        int n = 0;
        int avMemory = 0;
        int *array = NULL;
    public:
        SmartArray(int totalSize);
        SmartArray(const SmartArray& arrayToCopy);
        SmartArray &operator=(const SmartArray& arrayToCopy);
        SmartArray(SmartArray&& arrayToMove);
        SmartArray &operator=(SmartArray&& arrayToMove);
        SmartArray(std::vector<int> initialData = {});
        ~SmartArray();
        void push(int x);
        void pop();
        void sortArray();
        void print();
};
