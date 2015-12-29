//
// Created by cheyulin on 12/29/15.
//
#include "../my_header.hpp"
using namespace std;
class Solution{
public:
    bool isUgly(int num) {
        if (num <= 0)
            return false;
        while (num % 2 == 0) {
            num /= 2;
        }
        while (num % 3 == 0) {
            num /= 3;
        }
        while (num % 5 == 0) {
            num /= 5;
        }
        if (num == 1)
            return true;
        else
            return false;
    }
};

int main(){
    Solution solution;
    cout << solution.isUgly(6) << endl;
    cout << solution.isUgly(8) << endl;
    cout << solution.isUgly(14) << endl;
}