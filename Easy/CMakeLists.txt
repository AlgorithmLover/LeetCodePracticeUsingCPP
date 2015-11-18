cmake_minimum_required(VERSION 3.3)
project(Easy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp NimGame/NimGame.cpp NimGame/NimGame.h WordPattern/WordPattern.cpp WordPattern/WordPattern.h SortList/SortListConstantMemory.cpp SortList/SortListConstantMemory.h)
add_executable(Easy ${SOURCE_FILES})
add_executable(SortList SortList/SortListConstantMemory.cpp SortList/SortListConstantMemory.h SortList/testSortList.cpp)
add_executable(MissingNumber MissingNumber/MissingNumber.h MissingNumber/MissingNumber.cpp MissingNumber/testBinarySearch.cpp)
add_executable(FindDuplicateNum DuplicateNumber/testFindDuplicateNum.cpp DuplicateNumber/FindDuplicateNumber.cpp DuplicateNumber/FindDuplicateNumber.h)
add_executable(TestCal BasicCal/testCal.cpp)
add_executable(RangeSumQuery Array/NumArray.cpp Array/NumArray.h Array/testRangeSumQuery.cpp)