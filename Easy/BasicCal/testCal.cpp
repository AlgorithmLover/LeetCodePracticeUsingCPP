//
// Created by cheyulin on 11/16/15.
//

#include <string.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <map>
#include <queue>

using namespace std;

bool isPowerOfTwo(int n) {
    if (n == 0)
        return false;
    while (n % 2 == 0) {
        n /= 2;
        cout << n << endl;
    }
    if (n == 1) {
        return true;
    }
    else
        return false;
}









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

string BullsAndCows(string secret, string guess) {
    vector<int> secret_count(10);
    vector<int> guess_count(10);
    int bull = 0;
    int cow = 0;
//    const char * secret_chars=secret.c_str();
    for (int i = 0; i < secret.size(); i++) {
        int secret_num = secret.at(i) - 48;
        int guess_num = guess.at(i) - 48;
        if (secret_num != guess_num) {
            secret_count[secret_num] += 1;
            guess_count[guess_num] += 1;
        }
        else {
            bull++;
        }
    }
    for (int i = 0; i < 10; i++) {
        cow += min(secret_count[i], guess_count[i]);
    }
    stringstream string_builder;
    string_builder << bull << "A" << cow << "B";
    return string_builder.str();
}

bool isAnagram(string s, string t) {
    if (s.size() == 0 && t.size() == 0) {
        return true;
    }

    if (s.size() != t.size())
        return false;
    map<char, int> left_string_char_frequency_map;
    map<char, int> right_string_char_frequency_map;
    for (char ch : s) {
        if (left_string_char_frequency_map.find(ch) == left_string_char_frequency_map.end()) {
            left_string_char_frequency_map.insert(make_pair(ch, 1));
        }
        else {
            left_string_char_frequency_map[ch]++;
        }
    }
    for (char ch : t) {
        if (left_string_char_frequency_map.find(ch) == right_string_char_frequency_map.end()) {
            right_string_char_frequency_map.insert(make_pair(ch, 1));
        }
        else {
            right_string_char_frequency_map[ch]++;
        }
    }
    for (auto iter = left_string_char_frequency_map.begin(); iter != left_string_char_frequency_map.end(); iter++) {
        char ch = iter->first;
        if (right_string_char_frequency_map.find(ch) == right_string_char_frequency_map.end()) {
            return false;
        }
        else if (right_string_char_frequency_map[ch] != left_string_char_frequency_map[ch]) {
            return false;
        }
    }
    return true;
}

int main() {
//    cout << isPowerOfTwo(18);
//    cout << isUgly(18);
//    vector<int> nums={0,1,0,3,12};
//    moveZeroes(nums);
//    for(auto iter = nums.begin(); iter != nums.end() ; iter++) {
//        cout << *iter << endl;
//    }
//    cout << BullsAndCows("","");
//    cout << isAnagram("rat","car");
    for (int i = 1; i < 100; i++) {
        if (isUgly(i)) {
            cout << i << ",";
        }
    }

    cout << endl;
    cout << nthUglyNumberNaive(28) << endl;

}


