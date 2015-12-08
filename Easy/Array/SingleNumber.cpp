//
// Created by cheyulin on 12/4/15.
//

#include <iostream>
#include "SingleNumber.h"

vector<int> SingleNumber::singleNumberThree(vector<int> nums) {
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

int SingleNumber::singleNumberOne(vector<int> nums) {
    int answer = 0;
    for (int num : nums) {
        answer ^= num;
    }
    return answer;
}

int SingleNumber::singleNumberTwo(vector<int> nums) {
    int *bit_indicator = new int[32];
//    memset(bit_indicator, 0, 32);
    for (int i = 0; i < 32; i++) {
        bit_indicator[i] = 0;
    }
    for (int num: nums) {
        for (int i = 0; i < 32; i++) {
            int temp = 0x00000001;
            if (((num >> i) & temp) == 1) {
                bit_indicator[i] = (bit_indicator[i] + 1) % 3;
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < 32; i++) {
        int temp = 0x00000001;
        if (bit_indicator[i] == 1) {
            answer |= (temp << i);
        }
    }
    return answer;
}
