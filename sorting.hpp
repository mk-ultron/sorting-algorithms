#pragma once
#include <vector>

namespace sorting {
    template<typename T>
    void bubbleSort(std::vector<T>& arr);
    
    template<typename T>
    void quickSort(std::vector<T>& arr);
    
    std::vector<int> generateRandomData(int size);
    
    template<typename Func>
    double measureSortingTime(std::vector<int>& data, Func sortFunc);
}

// Template implementations
#include "sorting.cpp"