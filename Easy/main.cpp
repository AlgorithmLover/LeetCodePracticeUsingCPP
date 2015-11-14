#include <iostream>
#include "NimGame/NimGame.h"
#include "WordPattern/WordPattern.h"
#include "SortList/SortListConstantMemory.h"
#include <iostream>

using namespace std;

//int** testArray(int *iTemp,int iLen){
//    int** pIntArray = new int*[2];
//    for(int i=0; i<iLen; i++){
//        cout << iTemp[i] << "," << "The" << i << "th" << endl;
//    }
//    pIntArray[0] = iTemp + 0;
//    cout << "shit" << * pIntArray[0] << endl;
//    pIntArray[1] = iTemp + iLen -1;
//    return pIntArray;
//}

int main() {
//    NimGame * solution = new NimGame();
//    for (int i=1 ;i<500;i++)
//        cout << i << ":" << solution->canWinNimNativeArray(i) << endl;
//    delete solution;
//    WordPattern wordPattern;
//    cout << wordPattern.wordPattern("abba", "dog cat cat dog") << endl;
//    cout << wordPattern.wordPattern("abba", "dog cat cat fish") << endl;
//    cout << wordPattern.wordPattern("aaa", "aa aa aa aa") << endl;
//    cout << wordPattern.wordPattern("he", "unit")<< endl<<endl;
//
//    int * array = new int[6];
//    for(int i=0;i<5;i++){
//        array[i]=i+2;
//    }
//    cout << array[0] << endl;
//    int ** pBeginEnd = testArray(array,5);
//
//    cout << "hello:" << *(pBeginEnd[0]) <<"," << pBeginEnd[0]<< endl << "next:" << *(pBeginEnd[1]) <<"," << pBeginEnd[1] << endl;
//
//    delete []array;
//    delete []pBeginEnd;
    SortList sortList;
    int length =5;
    ListNode* lPrev = new ListNode(-1);
    ListNode* lHead;
    srand(time(NULL));
    for(int i=0; i<length; i++){

        int iTemp = rand() % length;
        cout << lPrev->val <<":lPrev" << endl;
        cout << iTemp << "shit" <<endl;
        ListNode *lCur =new ListNode(iTemp);
        if(i == 0){
            lHead = lCur;
        }

        lPrev->next = lCur;
        lPrev = lPrev->next;
    }

    ListNode* lCur = lHead;
    while(lCur->next != nullptr){
        cout << lCur->val << endl;
        lCur = lCur->next;
    }

    lHead = sortList.quickSort(lHead);
    lCur = lHead;
    while(lCur->next != nullptr){
        cout << lCur->val << endl;
        lCur = lCur->next;
    }
    return 0;


}

