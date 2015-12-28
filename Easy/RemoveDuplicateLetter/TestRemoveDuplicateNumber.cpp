//
// Created by cheyulin on 12/27/15.
//
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, queue<int>> char_occur_dict;
        int index = 0;
        for (char tmp_char : s) {
            if (char_occur_dict.find(tmp_char) == char_occur_dict.end()) {
                queue<int> my_queue;
                char_occur_dict.insert(make_pair(tmp_char, my_queue));
            }
            char_occur_dict[tmp_char].push(index);
            index++;
        }

        map<int, char> index_char_dict;
        for(auto begin_iterator = char_occur_dict.begin(); begin_iterator != char_occur_dict.end(); begin_iterator++){
            index_char_dict.insert(make_pair(begin_iterator->second.front(), begin_iterator->first));
            int min_cur_index = begin_iterator->second.front();
            auto check_iterator = begin_iterator;
            check_iterator++;
            for(;check_iterator!=char_occur_dict.end();check_iterator++){
                queue<int> & check_queue = check_iterator->second;
                while(check_queue.size()>1 && check_queue.front()<min_cur_index){
                    check_queue.pop();
                }
            }
        }

        stringstream string_stream;
        for(auto int_char_pair : index_char_dict){
            string_stream << int_char_pair.second;
        }

        return string_stream.str();
    }


};

int main() {
    Solution solution;
    cout << solution.removeDuplicateLetters("bcabc") << endl;
    cout << solution.removeDuplicateLetters("cbacdcbc") << endl;
}
