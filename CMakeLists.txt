cmake_minimum_required(VERSION 3.7)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES dp/dp.cpp)
#set(SOURCE_FILES mergeSort/MergeSort.cpp )
#set(SOURCE_FILES quickSort/QuickSort.cpp)
#set(SOURCE_FILES main.cpp )
set(SOURCE_FILES backTrack/queen.cpp unsortBinSearch/unsortBinSerch.cpp heap/heap.cpp)

add_executable(Algorithm ${SOURCE_FILES})