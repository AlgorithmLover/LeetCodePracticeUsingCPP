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

ListNode* SortList::listMergeSort(ListNode *pHeadBefore, ListNode *pEndNext) {
    if (pHeadBefore->next->next == pEndNext)
        return pHeadBefore->next;
    ListNode *pMiddle = findCenter(pHeadBefore->next, pEndNext);
    ListNode *pFormerLastNode = listMergeSort(pHeadBefore, pMiddle->next);
    listMergeSort(pMiddle, pEndNext);
    ListNode* pLastNode= merge(pHeadBefore, pFormerLastNode, pEndNext);
    return pLastNode;
}


ListNode *SortList::findCenter(ListNode *pStart, ListNode *pEndNext) {
    ListNode *pIterator = pStart;
    int i = 0;
    while (true) {
        if (pIterator == pEndNext)
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

ListNode* SortList::merge(ListNode *pStartBefore, ListNode *pMiddle, ListNode *pEndNext) {
    ListNode *pMergeNode = pStartBefore;
    ListNode *pFormer = pStartBefore->next;
    ListNode *pLatter = pMiddle->next;
    while (pFormer != pMiddle->next && pLatter != pEndNext) {
        if (pFormer->val < pLatter->val) {
            pMergeNode->next = pFormer;
            pFormer = pFormer->next;
        }
        else {
            pMergeNode->next = pLatter;
            pLatter = pLatter->next;
        }
        pMergeNode = pMergeNode->next;
    }
    if (pFormer != pMiddle->next) {
        pMergeNode->next = pFormer;
    }
    else {
        pMergeNode->next = pLatter;
    }
    pMergeNode = pMergeNode->next;
    //In order to link to latter , in case of loop linked list
    pMergeNode->next = pEndNext;
    return pMergeNode;
}

ListNode *SortList::mergeSort(ListNode *head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    ListNode *pDumb = new ListNode(-1);
    pDumb->next = head;
    listMergeSort(pDumb, nullptr);
    ListNode * pNewHead = pDumb->next;
    delete  pDumb;
    return pNewHead;
}
