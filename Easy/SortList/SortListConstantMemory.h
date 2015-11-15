//
// Created by cheyulin on 11/13/15.
//

#ifndef EASY_SORTLISTCONSTANTMEMORY_H
#define EASY_SORTLISTCONSTANTMEMORY_H

#endif //EASY_SORTLISTCONSTANTMEMORY_H

struct ListNode{
    ListNode(int i, ListNode *pNode);

    int val;
    ListNode *next;
    ListNode(int x);
};

class SortList{
public:
    ListNode* mergeSort(ListNode* head);

    ListNode* quickSort(ListNode* head);

private:
    ListNode* &partition(ListNode *pStartPrev, ListNode *pEndNext);
    void listQuickSort(ListNode *pStartPrev, ListNode *pEndNext);

    ListNode* listMergeSort(ListNode *pHead);
    ListNode* findCenter(ListNode *pStart);

    ListNode* merge(ListNode *pHeadFormer, ListNode *pHeadLatter);
};