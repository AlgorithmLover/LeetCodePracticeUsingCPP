//
// Created by cheyulin on 11/13/15.
//


#include "WordPattern.h"

bool WordPattern::wordPattern(string pattern, string str) {
    map<string, int> mStrIndex;
    map<char, int> mCharIndex;
    stringstream sStream(str);
    int index=0;
    for(int i=0; i< pattern.length(); i++){
        char cTemp = pattern[i];
        string sTemp;
        if(!(sStream >> sTemp)){
            return false;
        }
        if(mCharIndex.find(cTemp)==mCharIndex.end()){
            if(mStrIndex.find(sTemp)==mStrIndex.end()){
                mStrIndex.insert(make_pair(sTemp, index));
                mCharIndex.insert(make_pair(cTemp, index));
                index++;
            }
            else
                return false;
        }
        else{
            if(mStrIndex.find(sTemp) == mStrIndex.end() || mCharIndex[cTemp]!=mStrIndex[sTemp]){
                return false;
            }
        }
    }
    string sTemp;
    if(sStream >> sTemp){
        return false;
    }
    else
        return true;
}
