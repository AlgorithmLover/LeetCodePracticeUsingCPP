//
// Created by cheyulin on 12/29/15.
//
#include "../my_header.hpp"
using namespace std;
class Solution{
public:
    bool isAnagram(string s, string t) {
        if (s.size() == 0 && t.size() == 0) {
            return true;
        }

        if (s.size() != t.size())
            return false;
        map<char, int> left_string_char_frequency_map;
        map<char, int> right_string_char_frequency_map;
        for (char ch : s) {
            if (left_string_char_frequency_map.find(ch) == left_string_char_frequency_map.end()) {
                left_string_char_frequency_map.insert(make_pair(ch, 1));
            }
            else {
                left_string_char_frequency_map[ch]++;
            }
        }
        for (char ch : t) {
            if (left_string_char_frequency_map.find(ch) == right_string_char_frequency_map.end()) {
                right_string_char_frequency_map.insert(make_pair(ch, 1));
            }
            else {
                right_string_char_frequency_map[ch]++;
            }
        }
        for (auto iter = left_string_char_frequency_map.begin(); iter != left_string_char_frequency_map.end(); iter++) {
            char ch = iter->first;
            if (right_string_char_frequency_map.find(ch) == right_string_char_frequency_map.end()) {
                return false;
            }
            else if (right_string_char_frequency_map[ch] != left_string_char_frequency_map[ch]) {
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    cout << solution.isAnagram("anagram", "nagaram") << endl;
    cout << solution.isAnagram("rat", "car") << endl;
}
