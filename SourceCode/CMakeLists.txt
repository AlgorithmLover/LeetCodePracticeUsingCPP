cmake_minimum_required(VERSION 3.3)
project(LeetCodePractice)

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

#SourceCode
add_executable(257BinaryTreePaths 257BinaryTreePaths/BinaryTreePaths.cpp my_header.hpp)
add_executable(299BullsAndCows 299BullsAndCows/BullsAndCows.cpp my_header.hpp)
add_executable(290WordPattern 290WordPattern/WordPattern.cpp my_header.hpp)
add_executable(231PowerOfTwo 231PowerOfTwo/PowerOfTwo.cpp my_header.hpp)
add_executable(263UglyNumber 263UglyNumber/UglyNumber.cpp my_header.hpp)
add_executable(242ValidAnagram 242ValidAnagram/ValidAnagram.cpp my_header.hpp)
add_executable(283MoveZeros 283MoveZeros/MoveZeros.cpp my_header.hpp)
add_executable(292NimGame 292NimGame/NimGame.cpp my_header.hpp)

#Pending
add_executable(RemoveDuplicateLetter RemoveDuplicateLetter/TestRemoveDuplicateNumber.cpp my_header.hpp)