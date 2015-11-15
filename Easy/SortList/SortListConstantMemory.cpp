//
// Created by cheyulin on 11/13/15.
//

#include "SortListConstantMemory.h"

ListNode::ListNode(int x) : val(x), next(nullptr) {

}

ListNode::ListNode(int i, ListNode *pNode) {
    this->val = i;
    this->next = pNode;
}


ListNode *SortList::quickSort(ListNode *head) {
    ListNode *lDumbNode = new ListNode(-1);
    lDumbNode->next = head;
    listQuickSort(lDumbNode, nullptr);
    ListNode *retHead = lDumbNode->next;
    delete lDumbNode;
    return retHead;
}

ListNode *&SortList::partition(ListNode *pStartPrev, ListNode *pEndNext) {
    ListNode *lPivotVal = pStartPrev->next;
    int iPivotVal = pStartPrev->next->val;
    ListNode *lTempPrev = pStartPrev->next;
    while (lTempPrev->next != pEndNext) {
        //Move those less than pivot forward
        //use reference will be wrong
        if (lTempPrev->next->val < iPivotVal) {
            ListNode *lChangedNode = lTempPrev->next;
            lTempPrev->next = lChangedNode->next;
            lChangedNode->next = pStartPrev->next;
            pStartPrev->next = lChangedNode;
        }
        else {
            lTempPrev = lTempPrev->next;
        }
    }
    return lPivotVal;
}

void SortList::listQuickSort(ListNode *pStartPrev, ListNode *pEndNext) {
    if (pStartPrev->next == pEndNext || pStartPrev->next->next == pEndNext)
        return;
    //use reference will be wrong
    ListNode *pPivot = partition(pStartPrev, pEndNext);
    listQuickSort(pStartPrev, pPivot);
    listQuickSort(pPivot, pEndNext);
}

ListNode *SortList::mergeSort(ListNode *head) {
    if(head == nullptr ||head->next == nullptr)
        return head;
    return listMergeSort(head);
}
ListNode *SortList::findCenter(ListNode *pStart) {
    ListNode *pIterator = pStart;
    int i = 0;
    while (true) {
        if (pIterator == nullptr)
            break;
        pIterator = pIterator->next;
        i++;
    }
    int middle = i / 2;
    pIterator = pStart;
    for (int j = 1; j < middle; j++) {
        pIterator = pIterator->next;
    }
    return pIterator;
}
ListNode *SortList::listMergeSort(ListNode *pHead) {
    if(pHead->next == nullptr){
        return pHead;
    }
    ListNode* pMiddle = findCenter(pHead);
    ListNode* pLatterStart = listMergeSort(pMiddle->next);
    pMiddle->next = nullptr;
    ListNode* pFormerStart = listMergeSort(pHead);
    ListNode* pMergeStart= merge(pLatterStart,pFormerStart);
    return pMergeStart;
}

ListNode *SortList::merge(ListNode *pHeadFormer, ListNode *pHeadLatter) {
    ListNode* pDumbNode = new ListNode(-1);
    ListNode* pMergeNode = pDumbNode;
    while(pHeadFormer!= nullptr && pHeadLatter!= nullptr){
        if(pHeadFormer->val < pHeadLatter->val){
            pMergeNode->next = pHeadFormer;
            pHeadFormer = pHeadFormer->next;
        }
        else{
            pMergeNode->next = pHeadLatter;
            pHeadLatter = pHeadLatter->next;
        }
        pMergeNode = pMergeNode->next;
    }
    if(pHeadFormer!= nullptr){
        pMergeNode->next = pHeadFormer;
    }else if(pHeadLatter!= nullptr){
        pMergeNode->next = pHeadLatter;
    }
    else{
        pMergeNode->next = nullptr;
    }
    ListNode* pNewHead = pDumbNode->next;
    delete  pDumbNode;
    return pNewHead;
}
