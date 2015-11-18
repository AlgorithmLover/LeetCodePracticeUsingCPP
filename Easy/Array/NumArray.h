//
// Created by cheyulin on 11/18/15.
//

#ifndef EASY_NUMARRAY_H
#define EASY_NUMARRAY_H

#endif //EASY_NUMARRAY_H

#include <vector>
#include <map>
using namespace std;
class NumArray{
private:
    vector<int> nums;
    vector<int> sums;
    map<int,int> mIndexDelta;
    void resetArray();
    void calSums();
public:

    NumArray(vector<int> &sums);

    void update(int i, int val);
    int sumRange(int i, int j);
};