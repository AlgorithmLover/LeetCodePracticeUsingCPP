#include <iostream>
#include "MissingNumber.h"

//
// Created by cheyulin on 11/15/15.
//

int main(){
    MissingNumber missingNumber;
    vector<int> vNums;
    vNums.push_back(0);
    vNums.push_back(2);
    vNums.push_back(3);
    vNums.push_back(4);

    cout << missingNumber.missingNumber(vNums);
}
