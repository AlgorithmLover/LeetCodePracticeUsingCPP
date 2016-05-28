//
// Created by cheyulin on 11/13/15.
//

#include "../my_header.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {

    }

    ListNode(int i, ListNode *pNode) {
        this->val = i;
        this->next = pNode;
    }
};

class Solution {
public:
    ListNode *quickSort(ListNode *head) {
        ListNode *lDumbNode = new ListNode(-1);
        lDumbNode->next = head;
        listQuickSort(lDumbNode, nullptr);
        ListNode *retHead = lDumbNode->next;
        delete lDumbNode;
        return retHead;
    }

    ListNode *mergeSort(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        return listMergeSort(head);
    }

private:
    //Quick Sort Related
    ListNode *&partition(ListNode *pStartPrev, ListNode *pEndNext) {
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

    void listQuickSort(ListNode *pStartPrev, ListNode *pEndNext) {
        if (pStartPrev->next == pEndNext || pStartPrev->next->next == pEndNext)
            return;
        //use reference will be wrong
        ListNode *pPivot = partition(pStartPrev, pEndNext);
        listQuickSort(pStartPrev, pPivot);
        listQuickSort(pPivot, pEndNext);
    }

    //Merge Sort Related
    ListNode *findCenter(ListNode *pStart) {
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

    ListNode *listMergeSort(ListNode *pHead) {
        if (pHead->next == nullptr) {
            return pHead;
        }
        ListNode *pMiddle = findCenter(pHead);
        ListNode *pLatterStart = listMergeSort(pMiddle->next);
        pMiddle->next = nullptr;
        ListNode *pFormerStart = listMergeSort(pHead);
        ListNode *pMergeStart = merge(pLatterStart, pFormerStart);
        return pMergeStart;
    }

    ListNode *merge(ListNode *pHeadFormer, ListNode *pHeadLatter) {
        ListNode *pDumbNode = new ListNode(-1);
        ListNode *pMergeNode = pDumbNode;
        while (pHeadFormer != nullptr && pHeadLatter != nullptr) {
            if (pHeadFormer->val < pHeadLatter->val) {
                pMergeNode->next = pHeadFormer;
                pHeadFormer = pHeadFormer->next;
            }
            else {
                pMergeNode->next = pHeadLatter;
                pHeadLatter = pHeadLatter->next;
            }
            pMergeNode = pMergeNode->next;
        }
        if (pHeadFormer != nullptr) {
            pMergeNode->next = pHeadFormer;
        } else if (pHeadLatter != nullptr) {
            pMergeNode->next = pHeadLatter;
        }
        else {
            pMergeNode->next = nullptr;
        }
        ListNode *pNewHead = pDumbNode->next;
        delete pDumbNode;
        return pNewHead;
    }
};

enum class TestType {
    mergesort, quicksort
};

void test(TestType test_type) {
    Solution solution;
    int length = 50;
    ListNode *lPrev = new ListNode(-1);
    ListNode *lHead;
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int iTemp = rand() % length;
        cout << iTemp << ",";
        ListNode *lCur = new ListNode(iTemp);
        if (i == 0) {
            lHead = lCur;
        }
        lPrev->next = lCur;
        lPrev = lPrev->next;
    }
    cout << endl;
    ListNode *lCur;
    if (test_type == TestType::mergesort) {
        lCur = solution.mergeSort(lHead);
    }
    else {
        lCur = solution.quickSort(lHead);
    }

    while (lCur != nullptr) {
        cout << lCur->val << ",";
        lCur = lCur->next;
    }
    cout << endl;
}

int main() {
    cout << "MergeSort:" << endl;
    test(TestType::mergesort);
    cout << endl;
    cout << "QuickSort:" << endl;
    test(TestType::quicksort);
    return 0;
}








