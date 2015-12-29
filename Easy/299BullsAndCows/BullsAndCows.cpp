//
// Created by cheyulin on 12/29/15.
//
#include "../my_header.hpp"
using namespace std;
class Solution{
public:
    string BullsAndCows(string secret, string guess) {
        vector<int> secret_count(10);
        vector<int> guess_count(10);
        int bull = 0;
        int cow = 0;
//    const char * secret_chars=secret.c_str();
        for (int i = 0; i < secret.size(); i++) {
            int secret_num = secret.at(i) - 48;
            int guess_num = guess.at(i) - 48;
            if (secret_num != guess_num) {
                secret_count[secret_num] += 1;
                guess_count[guess_num] += 1;
            }
            else {
                bull++;
            }
        }
        for (int i = 0; i < 10; i++) {
            cow += min(secret_count[i], guess_count[i]);
        }
        stringstream string_builder;
        string_builder << bull << "A" << cow << "B";
        return string_builder.str();
    }
};

int main(){
    Solution solution;
    cout << solution.BullsAndCows("1807","7810") << endl;
    cout << solution.BullsAndCows("1123","0111") << endl;
}
