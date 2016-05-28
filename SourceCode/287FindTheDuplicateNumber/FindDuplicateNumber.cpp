//
// Created by cheyulin on 11/16/15.
//
#include "../my_header.h"

using namespace std;

class Solution {
public:
    int findDuplicateNaive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            int iExam = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == iExam)
                    return iExam;
            }
        }
        return 0;
    }

    int findDuplicateBinarySearch(vector<int> &nums) {
        int iMax = nums.size() - 1;
        int iMin = 1;
        int iMiddle;

        int iCount = 0;
        int iDuplicate = 0;
        while (true) {
            iMiddle = (iMax + iMin) / 2;
            for (int i = 0; i < nums.size(); i++) {
                if (iMiddle == nums[i]) {
                    iDuplicate++;
                    if (iDuplicate > 1) {
                        return iMiddle;
                    }
                }
                else if (nums[i] < iMiddle) {
                    iCount++;
                }
            }
            if (iCount >= iMiddle) {
                iMax = iMiddle - 1;
            }
            else {
                iMin = iMiddle + 1;
            }
            iCount = 0;
            iDuplicate = 0;
        }
        return 0;
    }

    // With O(n) Time Complexity
    // Refer to the forum
    int findDuplicateCyclicList(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        int slow = 0;
        int fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int test(initializer_list<int> integers) {
    Solution solution;
    vector<int> test_vector;
    for (int integer : integers) {
        test_vector.push_back(integer);
    }
    cout << "findDuplicateCyclicList:" << solution.findDuplicateCyclicList(test_vector) << endl;
    cout << "findDuplicateBinarySearch:" << solution.findDuplicateBinarySearch(test_vector) << endl;
    cout << "findDuplicateNaive:" << solution.findDuplicateNaive(test_vector) << endl;
}

int main() {
    test({28, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 31, 18, 18, 18, 18, 18, 18, 14, 18, 18, 18,
          18, 18, 18, 9, 18, 18, 18, 18, 18, 18, 4, 18, 18, 18, 18, 26, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18});
    cout << endl;
    test({1,3,4,2,1});
}

