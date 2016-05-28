//
// Created by cheyulin on 12/29/15.
//
#include "../my_header.h"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        if (nums.size() == 0)
            return;
        int iIndex = nums.size() - 1;
        int iZeroCount = 0;
        int iCurIndex = 0;
        for (int i = 0; i <= iIndex; i++) {
            if (nums[i] == 0) {
                iZeroCount++;
            }
            else {
                nums[iCurIndex] = nums[i];
                iCurIndex++;
            }
        }
        for (int i = iCurIndex; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }

};


int main() {
    Solution solution;
    vector<int> nums = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    for(int number : nums){
        cout << number << endl;
    }
}