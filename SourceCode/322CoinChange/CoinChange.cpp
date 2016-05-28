//
// Created by cheyulin on 1/12/16.
//

#include "../my_header.h"

using namespace std;

class Solution {
public:
    int RecursiveFindAmount(vector<int> &coins, int amount, int *memo) {
        if (amount < 0)
            return -1;
        else if (amount == 0)
            return 0;
        else {
            int ret = -1;
            for (auto coin_value:coins) {
                int residual_amount = amount - coin_value;
                if (residual_amount < 0) {
                    continue;
                }
                else {
                    if (memo[residual_amount] == -2) {
                        memo[residual_amount] = RecursiveFindAmount(coins, residual_amount, memo);
                        cout << residual_amount << " " << memo[residual_amount] << endl;
                    }
                    if (memo[residual_amount] > -1) {
                        if (memo[residual_amount] + 1 < ret || ret == -1)
                            ret = memo[residual_amount] + 1;
                    }
                }
            }
            return ret;
        }

    }

    int coinChange(vector<int> &coins, int amount) {
        int *memo_amount = new int[amount + 1];
        for (int i = 0; i < amount + 1; i++) {
            memo_amount[i] = -2;
        }
        int ret = RecursiveFindAmount(coins, amount, memo_amount);
        delete[] memo_amount;
        return ret;
    }

};

void test(initializer_list<int> params, int amount) {
    vector<int> coins;
    for (int param:params) {
        coins.push_back(param);
    }
    Solution solution;
    cout << "Coin:";
    for (int coin :coins) {
        cout << coin << " ";
    }
    cout << " " << "Amount:" << amount << endl;
    cout << "Coin Change:" << solution.coinChange(coins, amount) << endl;
}

int main() {

//  test({1, 2, 5}, 11);
    test({2}, 3);

}