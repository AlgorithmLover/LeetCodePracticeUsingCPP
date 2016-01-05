//
// Created by cheyulin on 1/4/16.
//
#include "../my_header.hpp"

using namespace std;

class Solution {
public:

//private:
//    void swap(int &left, int &right) {
//        int tmp = left;
//        left = right;
//        right = tmp;
//    }
//
//public:
//    void WiggleSort(vector<int> &nums) {
//        for (int i = 0; i < nums.size() - 1; i++) {
//            if (nums[i] == nums[i + 1]) {
//                for (int j = i + 2; j < nums.size(); j++) {
//                    if (nums[j] != nums[i]) {
//                        swap(nums[j], nums[i]);
//                    }
//                }
//            }
//            if (i % 2 == 0) {
//                if (nums[i] > nums[i + 1]) {
//                    swap(nums[i + 1], nums[i]);
//                }
//            } else if (i % 2 == 1) {
//                if (nums[i] < nums[i + 1]) {
//                    swap(nums[i + 1], nums[i]);
//                }
//            }
//        }
//    }
public:
    void WiggleSort(vector<int> & nums){

    }

};

void test(initializer_list<int> init_vals) {
    vector<int> nums;
    for (auto integer: init_vals) {
        nums.push_back(integer);
    }
    Solution solution;
    solution.WiggleSort(nums);
    for (auto my_int:nums) {
        cout << my_int;
    }
    cout<<endl;
}

int main() {
    test({1, 5, 1, 1, 6, 4});
    test({1,3,2,2,3,1});
}
