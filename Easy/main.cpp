#include <iostream>
#include "NimGame/NimGame.h"
#include "WordPattern/WordPattern.h"

using namespace std;

int main() {
//    NimGame * solution = new NimGame();
//    for (int i=1 ;i<500;i++)
//        cout << i << ":" << solution->canWinNimNativeArray(i) << endl;
//    delete solution;
    WordPattern wordPattern;
   cout << wordPattern.wordPattern("abba","dog cat cat dog")<<endl;
    cout << wordPattern.wordPattern("abba", "dog cat cat fish")<<endl;
    cout << wordPattern.wordPattern("aaa","aa aa aa aa")<<endl;
    cout << wordPattern.wordPattern("he","unit");
    return 0;
}