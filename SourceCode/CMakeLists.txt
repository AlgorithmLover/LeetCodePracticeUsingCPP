cmake_minimum_required(VERSION 3.3)
project(LeetCodePractice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Hard
add_executable(287FindTheDuplicateNumberBin 287FindTheDuplicateNumber/FindDuplicateNumber.cpp my_header.h)

#Medium
add_executable(307RangeSumQueryBin 307RangeSumQuery/RangeSumQuery.cpp my_header.h)
add_executable(148SortListBin 148SortList/SortListConstantMemory.cpp my_header.h)
add_executable(264UglyNumber2Bin 264UglyNumber2/UglyNumber2.cpp my_header.h)
add_executable(236LowestCommonAncestorOfABinaryTreeBin 236LowestCommonAncestorOfABinaryTree/LowestCommonAncestorOfBinaryTree.cpp my_header.h)
add_executable(137SingleNumber2Bin 137SingleNumber2/SingleNumber2.cpp my_header.h)
add_executable(260SingleNumber3Bin 260SingleNumber3/SingleNumber3.cpp my_header.h)
add_executable(136SingleNumberBin 136SingleNumber/SingleNumber.cpp my_header.h)
add_executable(268MissingNumberBin 268MissingNumber/MissingNumber.cpp my_header.h)
add_executable(316RemoveDuplicateLetterBin 316RemoveDuplicateLetter/TestRemoveDuplicateNumber.cpp my_header.h)

#Easy
add_executable(257BinaryTreePathsBin 257BinaryTreePaths/BinaryTreePaths.cpp my_header.h)
add_executable(299BullsAndCowsBin 299BullsAndCows/BullsAndCows.cpp my_header.h)
add_executable(290WordPatternBin 290WordPattern/WordPattern.cpp my_header.h)
add_executable(231PowerOfTwoBin 231PowerOfTwo/PowerOfTwo.cpp my_header.h)
add_executable(263UglyNumberBin 263UglyNumber/UglyNumber.cpp my_header.h)
add_executable(242ValidAnagramBin 242ValidAnagram/ValidAnagram.cpp my_header.h)
add_executable(283MoveZerosBin 283MoveZeros/MoveZeros.cpp my_header.h)
add_executable(292NimGameBin 292NimGame/NimGame.cpp my_header.h)
add_executable(322CoinChangeBin 322CoinChange/CoinChange.cpp my_header.h)

#Pending
add_executable(324WiggleSort2Bin 324WiggleSort2/WiggleSort.cpp my_header.h)
#add_executable(284PeekingIteratorBin 284PeekingIterator/PeekingIterator.cpp my_header.h)
#add_executable(306AdditiveNumberBin 306AdditiveNumber/AdditiveNumber.cpp my_header.h)
