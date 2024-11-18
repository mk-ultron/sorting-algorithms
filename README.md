# Sorting Algorithms Analysis

This project implements and analyzes various sorting algorithms to compare their performance characteristics.

## Quick Start
1. To run the program directly:
   - Navigate to the `bin` folder
   - Double-click `sorting.exe` or run from command line:
     ```
     cd bin
     sorting.exe
     ```

## Building from Source (Optional)
If you want to modify and rebuild the code:
1. Requirements:
   - C++ compiler (supporting C++17 or later)
   - CMake (3.10 or later)

2. Build Instructions:
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

## Program Output
The program will display a table showing:
- Different data sizes (100, 1000, 10000, 100000)
- Execution time for each sorting algorithm
- Performance comparisons

## Sample Results
```
Performance Analysis of Sorting Algorithms
----------------------------------------
Data Size | Bubble Sort | Quick Sort  | STL Sort
----------|-------------|-------------|----------
     100  |        0.5  |       0.1  |      0.1
    1000  |       48.3  |       0.9  |      0.8
   10000  |     4523.7  |      10.2  |      8.4
  100000  |   452837.1  |     121.5  |     98.2
```