//
// Created by cheyulin on 11/13/15.
//

#ifndef EASY_SORTLISTCONSTANTMEMORY_H
#define EASY_SORTLISTCONSTANTMEMORY_H

#endif //EASY_SORTLISTCONSTANTMEMORY_H

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x);
};

class SortList{
public:
    ListNode* sortList(ListNode* head);
    ListNode* mergeSort(ListNode* head);
    ListNode* quickSort(ListNode* head);



    void listQuickSort(ListNode *pStartPrev, ListNode *pEndNext);
private:
    ListNode* &partition(ListNode *pStartPrev, ListNode *pEndNext);
};