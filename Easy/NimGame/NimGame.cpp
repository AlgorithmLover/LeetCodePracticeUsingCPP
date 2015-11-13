//
// Created by cheyulin on 11/12/15.
//

#include "NimGame.h"

bool NimGame::canWinNimNaive(int n) {
    if(n <= 3)
        return true;
    else
    {
        bool bFriendWin = (canWinNimNaive(n - 1) & canWinNimNaive(n - 2) & canWinNimNaive(n - 3));
        return !bFriendWin;
    }
}

bool NimGame::canWinNimVector(int n) {
    vector<bool> vResult;
    for(int i=0;i<n;i++){
        if(i < 3){
            vResult.push_back(true);
        }
        else{
            vResult.push_back(!(vResult[i-1] && vResult[i-2] && vResult[i-3]));
        }
    }
    return  vResult[n-1];
}

bool NimGame::canWinNimNativeArray(int n) {
    bool * bResult = new bool[n];
    for(int i=0;i<n;i++){
        if(i < 3){
            bResult[i]= true;
        }
        else{
           bResult[i]=!(bResult[i-1] && bResult[i-2] && bResult[i-3]);
        }
    }
    return bResult[n-1];
}

bool NimGame::canWinNimObservation(int n) {
    if(n % 4 ==0)
        return false;
    else
        return true;
}
