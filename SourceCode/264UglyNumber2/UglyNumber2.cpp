//
// Created by cheyulin on 12/29/15.
//
#include "../my_header.h"

using namespace std;

class Solution {
private:
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

    bool isUglyRecursive(int num, vector<bool> &mark_of_number) {
        if (num == 1) {
            return true;
        }
        else {
            if (num < 30) {
                return isUgly(num);
            }
            else {
                if (num % 2 == 0) {
                    return mark_of_number[num / 2 - 1];
                }
                else if (num % 3 == 0) {
                    return mark_of_number[num / 3 - 1];
                }
                else if (num % 5 == 0) {
                    return mark_of_number[num / 5 - 1];
                }
                return false;
            }
        }
    }

public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> my_queue;
        my_queue.push(1);
        int order_number = 0;
        while (true) {
            if (order_number == n - 1) {
                return my_queue.top();
            }
            else {
                order_number++;
                long cur_min = my_queue.top();
                while (cur_min == my_queue.top() && !my_queue.empty()) {
                    my_queue.pop();
                }
                my_queue.push(cur_min * 2);
                my_queue.push(cur_min * 3);
                my_queue.push(cur_min * 5);
            }
        }
    }


    int nthUglyNumberNaive(int n) {
        vector<bool> mark_of_number;
        int ugly_number = 1;
        int index = 0;
        int iterator = 0;
        while (index < n) {
            iterator++;
            bool is_ugly = isUglyRecursive(iterator, mark_of_number);
            mark_of_number.push_back(is_ugly);
            if (is_ugly) {
                index++;
                ugly_number = iterator;
            }
        }
        return ugly_number;
    }
};

int main() {
    Solution solution;
    cout << "Using Search With Priority Queue:" << solution.nthUglyNumber(1407) << endl;
    cout << "Naieve Solution, Traverse All:" <<solution.nthUglyNumberNaive(1407) << endl;
}