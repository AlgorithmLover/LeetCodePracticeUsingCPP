//
// Created by cheyulin on 12/29/15.
//
#include "../my_header.h"

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0)
            return false;
        while (n % 2 == 0) {
            n /= 2;
        }
        if (n == 1) {
            return true;
        }
        else
            return false;
    }
};

int main() {
    Solution solution;
    cout << solution.isPowerOfTwo(0) << endl;
    cout << solution.isPowerOfTwo(1) << endl;
    cout << solution.isPowerOfTwo(32) << endl;
}



