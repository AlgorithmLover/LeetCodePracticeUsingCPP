//
// Created by cheyulin on 12/4/15.
//

#include "../my_header.hpp"
using namespace std;
class Solution{
public:
    int singleNumberOne(vector<int> nums) {
        int answer = 0;
        for (int num : nums) {
            answer ^= num;
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<int> test_vector = {1,1,2,2,3,4,4};
    int answer = solution.singleNumberOne(test_vector);
    std::cout << answer<<std::endl;
}



