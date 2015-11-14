//
// Created by cheyulin on 11/13/15.
//

#include "SortListConstantMemory.h"

ListNode::ListNode(int x) : val(x), next(nullptr) {

}

ListNode *SortList::quickSort(ListNode *head) {
    ListNode *lDumbNode = new ListNode(-1);
    lDumbNode->next = head;
    listQuickSort(lDumbNode, nullptr);
    return head;
}

ListNode* &SortList::partition(ListNode *pStartPrev, ListNode *pEndNext) {
    ListNode *lPivotVal = pStartPrev->next;
    int iPivotVal = pStartPrev->next->val;
    for (ListNode *lTempPrev = pStartPrev->next; lTempPrev->next != pEndNext; lTempPrev = lTempPrev->next) {
        //Move those less than pivot forward
        if(lTempPrev->next->val < iPivotVal){
            ListNode* &lChangedNode = lTempPrev->next;
            lTempPrev->next = lChangedNode->next;
            lChangedNode->next = pStartPrev->next;
            pStartPrev->next = lChangedNode;
        }
    }
    return lPivotVal;
}

void SortList::listQuickSort(ListNode *pStartPrev, ListNode *pEndNext) {
    if (pStartPrev->next == nullptr || pStartPrev->next->next == pEndNext)
        return;
    ListNode* &pPivot = partition(pStartPrev, pEndNext);
    listQuickSort(pStartPrev, pPivot);
    listQuickSort(pPivot, pEndNext);
}
