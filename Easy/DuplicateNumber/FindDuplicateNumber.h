//
// Created by cheyulin on 11/16/15.
//

#ifndef EASY_FINDDUPLICATENUMBER_H
#define EASY_FINDDUPLICATENUMBER_H

#endif //EASY_FINDDUPLICATENUMBER_H

#include <vector>
using namespace std;
class FindDuplicateNumber{
public:
    int findDuplicateNaive(vector<int> &nums);
    int findDuplicateBinarySearch(vector<int> &nums);
    int findDuplicateCyclicList(vector<int> &nums);
};