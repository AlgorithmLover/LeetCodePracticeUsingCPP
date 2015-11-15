//
// Created by cheyulin on 11/16/15.
//
#include <iostream>
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

int main(){
//    cout << isPowerOfTwo(18);
    cout << isUgly(18);
}


