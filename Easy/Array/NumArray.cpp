//
// Created by cheyulin on 11/18/15.
//

#include "NumArray.h"

NumArray::NumArray(vector<int> &nums) {
    this->nums = nums;
    this->sums = vector<int>(nums.size());
    this->mIndexDelta = map<int, int>();
    calSums();
}

void NumArray::update(int i, int val) {
    if (mIndexDelta.find(i) != mIndexDelta.end()) {
        int iNewDelta = val - (mIndexDelta[i] + nums[i]);
        mIndexDelta[i] += iNewDelta;
        if (mIndexDelta[i] == 0) {
            mIndexDelta.erase(i);
        }
    }
    else {
        mIndexDelta.insert(make_pair(i, val - nums[i]));
    }
    if (mIndexDelta.size() * mIndexDelta.size() > nums.size()) {
        resetArray();
    }
}

int NumArray::sumRange(int i, int j) {
    int sum = 0;
    for (auto iter = mIndexDelta.begin(); iter != mIndexDelta.end(); iter++) {
        int iKey = iter->first;
        int iDelta = iter->second;
        if (iKey >= i && iKey <= j) {
            sum += iDelta;
        }
    }
    return sums[j] - sums[i] + nums[i] + sum;
}

void NumArray::resetArray() {
    for (auto iter = mIndexDelta.begin(); iter != mIndexDelta.end(); iter++) {
        int iKey = iter->first;
        int iDelta = iter->second;
        nums[iKey] += iDelta;
    }
    mIndexDelta.clear();
    calSums();
}

void NumArray::calSums() {
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0)
            sums[i] = nums[i];
        else
            sums[i] = sums[i - 1] + nums[i];
    }

}
