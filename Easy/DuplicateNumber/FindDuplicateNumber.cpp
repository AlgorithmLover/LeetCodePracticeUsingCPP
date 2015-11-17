//
// Created by cheyulin on 11/16/15.
//

#include "FindDuplicateNumber.h"

int FindDuplicateNumber::findDuplicateNaive(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        int iExam = nums[i];
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] == iExam)
                return iExam;
        }

    }
    return 0;
}

int FindDuplicateNumber::findDuplicateBinarySearch(vector<int> &nums) {
    int iMax = nums.size() - 1;
    int iMin = 1;
    int iMiddle ;

    int iCount =0;
    int iDuplicate =0;
    while(true){
        iMiddle = (iMax+iMin) / 2;
        for(int i = 0; i < nums.size(); i++ ){
            if(iMiddle == nums[i]){
                iDuplicate++;
                if(iDuplicate >1){
                    return iMiddle;
                }
            }
            else if(nums[i] < iMiddle){
                iCount++;
            }
        }
        if(iCount >= iMiddle){
            iMax = iMiddle - 1;
        }
        else{
            iMin = iMiddle + 1;
        }
        iCount =0;
        iDuplicate =0;
    }
    return 0;
}


int FindDuplicateNumber::findDuplicateCyclicList(vector<int> &nums) {
    if(nums.size() ==0 )
        return 0;
    int slow =0;
    int fast =0;
    slow = nums[slow];
    fast = nums[nums[fast]];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    fast =0;
    while (fast != slow){
        slow = nums[slow];
        fast = nums[fast];
    }
    return  slow;
}
