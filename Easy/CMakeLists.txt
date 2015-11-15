cmake_minimum_required(VERSION 3.3)
project(Easy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp NimGame/NimGame.cpp NimGame/NimGame.h WordPattern/WordPattern.cpp WordPattern/WordPattern.h SortList/SortListConstantMemory.cpp SortList/SortListConstantMemory.h)
add_executable(Easy ${SOURCE_FILES})
add_executable(SortList SortList/SortListConstantMemory.cpp SortList/SortListConstantMemory.h SortList/testSortList.cpp)