//
// Created by cheyulin on 12/8/15.
//


#include <iostream>
#include "SingleNumber.h"

int main(){
    SingleNumber singleNumber;
    vector<int> testme = {43,16,45,89,45,-2147483648,45,2147483646,-2147483647,-2147483648,43,2147483647,-2147483646,-2147483648,89,-2147483646,89,-2147483646,-2147483647,2147483646,-2147483647,16,16,2147483646,43};
    vector<int> test;
    for(int i=0;i<3;i++){
        test.push_back(1);
        test.push_back(2);
        test.push_back(3);
    }
    test.push_back(4);
    int answer = singleNumber.singleNumberTwo(testme);
    std::cout << answer<<std::endl;

    vector<int> test_three ={1, 2, 1, 3, 2, 5};
    vector<int> answers = singleNumber.singleNumberThree(test_three);
    for(int answer : answers){
        std::cout << answer<< std::endl;
    }
}