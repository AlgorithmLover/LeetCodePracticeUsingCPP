//
// Created by cheyulin on 12/4/15.
//

#include "../my_header.h"

using namespace std;

class Solution {
public:
    vector<int> singleNumberThree(vector<int> nums) {
        vector<int> answers;
        int xor_for_a_and_b = 0;
        for (int num: nums) {
            xor_for_a_and_b ^= num;
        }
        int index_of_differ = 0;
        for (int i = 0; i < 32; i++) {
            if (((xor_for_a_and_b >> i) & 0x00000001) == 1) {
                index_of_differ = i;
                break;
            }
        }
        int answer = 0;
        for (int num:nums) {
            if (((num >> index_of_differ) & 0x00000001) == 1) {
                answer ^= num;
            }
        }
        answers.push_back(answer);
        answer = 0;
        for (int num:nums) {
            if (((num >> index_of_differ) & 0x00000001) == 0) {
                answer ^= num;
            }
        }
        answers.push_back(answer);
        std::cout << index_of_differ << std::endl;
        return answers;

    }
};

int main() {
    Solution solution;
    vector<int> test_three = {1, 2, 1, 3, 2, 5};
    vector<int> answers = solution.singleNumberThree(test_three);
    for (int answer : answers) {
        std::cout << answer << std::endl;
    }
}



