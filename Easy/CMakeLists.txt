cmake_minimum_required(VERSION 3.3)
project(Easy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Hard
add_executable(287FindTheDuplicateNumber 287FindTheDuplicateNumber/FindDuplicateNumber.cpp my_header.hpp)

#Medium
add_executable(307RangeSumQuery 307RangeSumQuery/RangeSumQuery.cpp my_header.hpp)
add_executable(148SortList 148SortList/SortListConstantMemory.cpp my_header.hpp)
add_executable(264UglyNumber2 264UglyNumber2/UglyNumber2.cpp my_header.hpp)
add_executable(236LowestCommonAncestorOfABinaryTree 236LowestCommonAncestorOfABinaryTree/LowestCommonAncestorOfBinaryTree.cpp my_header.hpp)
add_executable(137SingleNumber2 137SingleNumber2/SingleNumber2.cpp my_header.hpp)
add_executable(260SingleNumber3 260SingleNumber3/SingleNumber3.cpp my_header.hpp)
add_executable(136SingleNumber 136SingleNumber/SingleNumber.cpp my_header.hpp)
add_executable(260MissingNumber 260MissingNumber/MissingNumber.cpp my_header.hpp)
#add_executable(Easy ${SOURCE_FILES})
#add_executable(260MissingNumber 260MissingNumber/260MissingNumber.h 260MissingNumber/260MissingNumber.cpp 260MissingNumber/testBinarySearch.cpp)

#add_executable(TestCal BasicCal/testCal.cpp)
#add_executable(LCATree Tree/lowest_common_ancestor.cpp Tree/lowest_common_ancestor.h Tree/test_lca.cpp)
#add_executable(BinaryTreePath Tree/binary_tree_path.h Tree/test_binary_tree_path.cpp)
#add_executable(TestSingleNumber Array/testSingleNumber.cpp Array/SingleNumber.cpp Array/SingleNumber.h)
#add_executable(RemoveDuplicateLetter RemoveDuplicateLetter/TestRemoveDuplicateNumber.cpp)