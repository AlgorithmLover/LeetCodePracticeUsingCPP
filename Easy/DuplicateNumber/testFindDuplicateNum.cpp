//
// Created by cheyulin on 11/16/15.
//

#include <iostream>
#include "FindDuplicateNumber.h"

int main(){
    FindDuplicateNumber findDuplicateNumber;
    vector<int> vMyArray;
//    int * a= new int[50]{28,18,18,18,18,18,18,18,
//                       18,18,18,18,18,31,18,18,
//                       18,18,18,18,14,18,18,18,
//                       18,18,18, 9,18,18,18,18,
//                       18,18, 4,18,18,18,18,26,
//                       18,18,18,18,18,18,18,18,
//                       18,18};
    int * a = new int[5]{1,3,4,2,1};
    for(int i=0;i<50;i++){
        vMyArray.push_back(a[i]);
    }
    cout << findDuplicateNumber.findDuplicateCyclicList(vMyArray);

}
