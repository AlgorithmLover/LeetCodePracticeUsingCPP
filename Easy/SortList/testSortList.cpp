//
// Created by cheyulin on 11/15/15.
//

#include <iostream>
#include "SortListConstantMemory.h"
using namespace std;

int main(){
    SortList sortList;
    int length =50;
    ListNode* lPrev = new ListNode(-1);
    ListNode* lHead;
    srand(time(NULL));
    for(int i=0; i<length; i++){

        int iTemp = rand() % length;
//        cout << lPrev->val <<":lPrev" << endl;
        cout << iTemp << "shit" <<endl;
        ListNode *lCur =new ListNode(iTemp);
        if(i == 0){
            lHead = lCur;
        }

        lPrev->next = lCur;
        lPrev = lPrev->next;
    }
//    ListNode* lPrev = new ListNode(-1);
//
//    ListNode* lTail = new ListNode(3);
//    ListNode* lTail2 = new ListNode(5,lTail);
//    ListNode* lTail3 = new ListNode(1, lTail2);
//    ListNode* lTail4 = new ListNode(2,lTail3);
//    ListNode* lHead = new ListNode(4,lTail4);
//    ListNode * lCur =sortList.quickSort(lHead);
    ListNode *lCur =sortList.mergeSort(lHead);
    while(lCur!= nullptr){
        cout<<lCur->val<<endl;
        lCur=lCur->next;
    }
    return 0;
}