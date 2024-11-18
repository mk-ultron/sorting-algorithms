cmake_minimum_required(VERSION 3.10)
project(sorting_algorithms CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# For Windows: Prevent MSVC from using min/max macros
if(MSVC)
    add_definitions(-DNOMINMAX)
endif()

# Add executable
add_executable(sorting_analysis src/sorting.cpp)