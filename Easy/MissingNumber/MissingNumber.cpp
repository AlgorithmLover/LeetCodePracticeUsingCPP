//
// Created by cheyulin on 11/15/15.
//

#include "MissingNumber.h"

int MissingNumber::missingNumberOrdered(vector<int> &nums) {
    int iNumSize = nums.size();
    if(iNumSize ==0)
        return 0;
    if(nums[0] == 1)
        return 1;
    if(nums[iNumSize-1] == iNumSize-1)
        return iNumSize;

    int iStart = 0;
    int iEnd = iNumSize -1;

    while(iStart<=iEnd){
        int iMiddle = (iStart + iEnd)/2;
        if(nums[iMiddle-1]==iMiddle-1 && nums[iMiddle]==iMiddle+1){
            return iMiddle;
        }
        else if(nums[iMiddle]==iMiddle){
            iStart=iMiddle+1;
        }
        else if(nums[iMiddle]==iMiddle+1){
            iEnd=iMiddle-1;
        }
    }

    return 0;
}

int MissingNumber::missingNumber(vector<int> &nums) {
    int iNumSize = nums.size();
    if(iNumSize ==0)
        return 0;
    int sum = iNumSize*(iNumSize+1)/2;
    for(int i=0; i<iNumSize; i++){
        sum-=nums[i];
    }
    return sum;
}
