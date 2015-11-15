//
// Created by cheyulin on 11/16/15.
//

#include "FindDuplicateNumber.h"

int FindDuplicateNumber::findDuplicateNaive(vector<int> &nums) {
    for(int i=0; i<nums.size(); i++){
        int iExam = nums[i];
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]==iExam)
                return iExam;
        }

    }
    return 0;
}
