# Sorting Algorithms Analysis

This project implements and analyzes various sorting algorithms to compare their performance characteristics.

## Implemented Algorithms
- Bubble Sort
- Quick Sort
- STL Sort (C++ Standard Library Sort)

## Building the Project

### Prerequisites
- C++ compiler (supporting C++17 or later)
- CMake (3.10 or later)
- Git

### Build Instructions
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Running the Program
After building, run the executable:
```bash
./sorting_analysis
```

The program will:
1. Generate random data sets of various sizes
2. Sort them using different algorithms
3. Measure and compare performance
4. Output results to console and CSV file

## Analysis
Results are saved in `sorting_results.csv` for further analysis. Use Excel or similar software to:
- Create performance graphs
- Analyze time complexity
- Compare algorithm efficiency

## License
MIT License