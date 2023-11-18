#pragma once

#include <vector>

class ArrayInterface {
    private:
        int n = 0;
        int *array = NULL;
    public:
        virtual void push(int x) = 0;
        virtual void pop() = 0;
        virtual void sortArray() = 0;
        virtual void print();
};
