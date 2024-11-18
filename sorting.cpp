#include <iostream>   // For input/output operations (cout, cin)
#include <vector>     // For std::vector container
#include <algorithm>  // For std::sort
#include <random>     // For random number generation
#include <chrono>     // For timing measurements
#include <iomanip>    // For output formatting (setw, setprecision)

// Bubble Sort 
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

// Quick Sort 
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

// Generate random data
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

int main() {
    std::vector<int> sizes = {100, 1000, 10000, 100000};
    
    std::cout << "Performance Analysis\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Data Size | Bubble Sort | Quick Sort  | STL Sort\n";
    std::cout << "----------|-------------|-------------|----------\n";
    
    for (int size : sizes) {
        auto data = generateRandomData(size);
        auto data2 = data;
        auto data3 = data;
        
        // Measure Bubble Sort
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(data);
        auto end = std::chrono::high_resolution_clock::now();
        auto bubbleTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        
        // Measure Quick Sort
        start = std::chrono::high_resolution_clock::now();
        quickSort(data2);
        end = std::chrono::high_resolution_clock::now();
        auto quickTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        
        // Measure STL Sort
        start = std::chrono::high_resolution_clock::now();
        std::sort(data3.begin(), data3.end());
        end = std::chrono::high_resolution_clock::now();
        auto stlTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        
        std::cout << std::setw(9) << size << " | ";
        std::cout << std::setw(11) << bubbleTime << " | ";
        std::cout << std::setw(11) << quickTime << " | ";
        std::cout << std::setw(9) << stlTime << "\n";
    }
    
    return 0;
}