cmake_minimum_required(VERSION 3.7)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES dp/dp.cpp)
set(SOURCE_FILES mergeSort/MergeSort.cpp)

add_executable(Algorithm ${SOURCE_FILES})