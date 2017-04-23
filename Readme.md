# Algorithm

### 环境

- Cmake编译 选择需要的cpp文件即可

```cmake
cmake_minimum_required(VERSION 3.7)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES dp/dp.cpp)
#set(SOURCE_FILES mergeSort/MergeSort.cpp )
#set(SOURCE_FILES quickSort/QuickSort.cpp)
#set(SOURCE_FILES main.cpp )
set(SOURCE_FILES backTrack/queen.cpp unsortBinSearch/unsortBinSerch.cpp heap/heap.cpp)

add_executable(Algorithm ${SOURCE_FILES})
```

- g++ 编译

```shell
 ~/ProgramHomework/Algorithm   master  ls 
CMakeLists.txt    backTrack         cmake-build-debug dp                heap              main.cpp          mergeSort         quickSort         unsortBinSearch
 ~/ProgramHomework/Algorithm   master  cd backTrack 
 ~/ProgramHomework/Algorithm/backTrack   master  ls
queen.cpp
 ~/ProgramHomework/Algorithm/backTrack   master  g++ *.cpp
 ~/ProgramHomework/Algorithm/backTrack   master  ls
a.out     queen.cpp
 ~/ProgramHomework/Algorithm/backTrack   master  ./a.out 
0 4 7 5 2 6 1 3 
0 5 7 2 6 3 1 4 
0 6 3 5 7 1 4 2 
0 6 4 7 1 3 5 2 
...
```

- 测试环境

```
macOS Sierra v10.12.4
MacBook Pro 2016
```

### 算法

1. 回溯法 `backtrack`
2. 动态规划 `dp`
3. 归并排序 `mergeSort`
4. 快排 `quickSort`
5. 对未排序列表进行二分查找 `unsortBinSearch`

### 数据结构实现

1. 堆 `heap`