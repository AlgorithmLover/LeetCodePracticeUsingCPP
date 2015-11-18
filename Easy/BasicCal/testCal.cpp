//
// Created by cheyulin on 11/16/15.
//
#include <iostream>
#include <vector>

using namespace std;
bool isPowerOfTwo(int n) {
    if(n==0)
        return false;
    while(n%2==0){
        n/=2;
        cout << n << endl;
    }
    if(n==1){
        return true;
    }
    else
        return false;
}

bool isUgly(int num){
    if(num <=0)
        return false;
    while(num % 2==0)
    {
        num/=2;
    }
    while(num % 3==0)
    {
        num/=3;
    }
    while(num %5 ==0){
        num/=5;
    }
    if(num==1)
        return  true;
    else
        return false;
}

void moveZeroes(vector<int>& nums) {
    if(nums.size()==0)
        return;
    int iIndex = nums.size() -1;
    int iZeroCount =0;
    int iCurIndex =0;
    for(int i=0;i<= iIndex; i++){
       if(nums[i] ==0){
           iZeroCount++;
       }
        else{
           nums[iCurIndex]=nums[i];
           iCurIndex++;
       }
    }
    for(int i=iCurIndex; i< nums.size();i++){
        nums[i]=0;
    }
}

int main(){
//    cout << isPowerOfTwo(18);
//    cout << isUgly(18);
    vector<int> nums={0,1,0,3,12};
    moveZeroes(nums);
    for(auto iter = nums.begin(); iter != nums.end() ; iter++) {
        cout << *iter << endl;
    }

}


