//
// Created by cheyulin on 12/4/15.
//

#include "../my_header.h"
using namespace std;
class Solution{
public:
    int singleNumberTwo(vector<int> nums) {
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
};

int main(){
    Solution solution;
    vector<int> test_vector = {43, 16, 45, 89, 45, -2147483648, 45, 2147483646, -2147483647, -2147483648, 43, 2147483647, -2147483646, -2147483648, 89, -2147483646, 89, -2147483646, -2147483647, 2147483646, -2147483647, 16, 16, 2147483646, 43};
    int answer = solution.singleNumberTwo(test_vector);
    std::cout << answer<<std::endl;
}



