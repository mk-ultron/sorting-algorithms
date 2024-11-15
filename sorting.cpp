#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#include <fstream>

// Bubble Sort implementation
template<typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Quick Sort implementation
template<typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template<typename T>
void quickSortHelper(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

template<typename T>
void quickSort(std::vector<T>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}

// Function to generate random data
std::vector<int> generateRandomData(int size) {
    std::vector<int> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);
    
    for (int i = 0; i < size; i++) {
        data[i] = dis(gen);
    }
    return data;
}

// Function to measure sorting time
template<typename Func>
double measureSortingTime(std::vector<int>& data, Func sortFunc) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(data);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

int main() {
    std::vector<int> sizes = {100, 1000, 10000, 100000};
    std::ofstream outFile("sorting_results.csv");
    
    // Write CSV header
    outFile << "Size,Bubble Sort (ms),Quick Sort (ms),STL Sort (ms)\n";
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Performance Analysis of Sorting Algorithms\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Data Size | Bubble Sort | Quick Sort  | STL Sort\n";
    std::cout << "----------|-------------|-------------|----------\n";
    
    for (int size : sizes) {
        // Generate data
        auto data1 = generateRandomData(size);
        auto data2 = data1;  // Make copies for each sort
        auto data3 = data1;
        
        // Measure Bubble Sort
        double bubbleTime = measureSortingTime(data1, bubbleSort<int>);
        
        // Measure Quick Sort
        double quickTime = measureSortingTime(data2, quickSort<int>);
        
        // Measure STL Sort
        double stlTime = measureSortingTime(data3, 
            [](std::vector<int>& arr) { std::sort(arr.begin(), arr.end()); });
        
        // Print results
        std::cout << std::setw(9) << size << " | ";
        std::cout << std::setw(11) << bubbleTime << " | ";
        std::cout << std::setw(11) << quickTime << " | ";
        std::cout << std::setw(9) << stlTime << "\n";
        
        // Write to CSV
        outFile << size << "," << bubbleTime << "," << quickTime << "," << stlTime << "\n";
    }
    
    outFile.close();
    
    std::cout << "\nResults have been saved to 'sorting_results.csv' for further analysis.\n";
    std::cout << "\nAlgorithm Analysis:\n";
    std::cout << "1. Bubble Sort: O(n²) - Simple but inefficient for large datasets\n";
    std::cout << "2. Quick Sort: O(n log n) average case - Efficient for large datasets\n";
    std::cout << "3. STL Sort: O(n log n) - Highly optimized hybrid algorithm\n";
    
    return 0;
}