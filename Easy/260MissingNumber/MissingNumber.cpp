//
// Created by cheyulin on 11/15/15.
//

#include "../my_header.hpp"
using namespace std;
class Solution {
public:
    int missingNumberOrdered(vector<int> &nums) {
        int iNumSize = nums.size();
        if (iNumSize == 0)
            return 0;
        if (nums[0] == 1)
            return 1;
        if (nums[iNumSize - 1] == iNumSize - 1)
            return iNumSize;

        int iStart = 0;
        int iEnd = iNumSize - 1;

        while (iStart <= iEnd) {
            int iMiddle = (iStart + iEnd) / 2;
            if (nums[iMiddle - 1] == iMiddle - 1 && nums[iMiddle] == iMiddle + 1) {
                return iMiddle;
            }
            else if (nums[iMiddle] == iMiddle) {
                iStart = iMiddle + 1;
            }
            else if (nums[iMiddle] == iMiddle + 1) {
                iEnd = iMiddle - 1;
            }
        }

        return 0;
    }

    int missingNumber(vector<int> &nums) {
        int iNumSize = nums.size();
        if (iNumSize == 0)
            return 0;
        int sum = iNumSize * (iNumSize + 1) / 2;
        for (int i = 0; i < iNumSize; i++) {
            sum -= nums[i];
        }
        return sum;
    }
};

enum class MethodType {
    sort, normal
};

void test(MethodType method_type){
    Solution solution;
    vector test_vector = {0,1,3};
    if(method_type == MethodType::sort){
        cout << solution.missingNumberOrdered(test_vector) << endl;
    }
    else
       cout << solution.missingNumber(test_vector) << endl;
}

int main() {
    test(MethodType::sort);
    test(MethodType::normal);
}

