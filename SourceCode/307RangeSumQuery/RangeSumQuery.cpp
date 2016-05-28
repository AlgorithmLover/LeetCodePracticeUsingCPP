//
// Created by cheyulin on 12/29/15.
//
#include "../my_header.h"

using namespace std;

class NumArray {
private:
    vector<int> nums;
    vector<int> sums;
    map<int, int> mIndexDelta;

    void resetArray() {
        for (auto iter = mIndexDelta.begin(); iter != mIndexDelta.end(); iter++) {
            int iKey = iter->first;
            int iDelta = iter->second;
            nums[iKey] += iDelta;
        }
        mIndexDelta.clear();
        calSums();
    }

    void calSums() {
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0)
                sums[i] = nums[i];
            else
                sums[i] = sums[i - 1] + nums[i];
        }

    }

public:
    NumArray(vector<int> &nums) {
        this->nums = nums;
        this->sums = vector<int>(nums.size());
        this->mIndexDelta = map<int, int>();
        calSums();
    }

    void update(int i, int val) {
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

    int sumRange(int i, int j) {
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
};

int test(initializer_list<int> integers) {
    vector<int> my_vector;
    for (auto integer : integers) {
        my_vector.push_back(integer);
    }
    NumArray numArray(my_vector);
    numArray.update(4, 6);
    numArray.update(0, 2);
    numArray.update(0, 9);
    cout << my_vector.size() << endl;
    cout << numArray.sumRange(4, 4) << endl;
    numArray.update(3, 8);
    cout << numArray.sumRange(0, 4) << endl;
    numArray.update(4, 1);
    cout << numArray.sumRange(0, 3) << endl;
    cout << numArray.sumRange(0, 4) << endl;
    cout << numArray.sumRange(0, 2) << endl;
}

int main() {
    test({7, 2, 7, 2, 0});
}